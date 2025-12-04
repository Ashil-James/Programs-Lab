#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This function writes a text record to the object file.
 * It's called when a new record needs to start (e.g., after RESW/RESB),
 * when a record is full, or at the end of the program.
 */
void write_text_record(FILE *fp, int *start_addr, int *record_len, char buffer[]) {
    if (*record_len > 0) {
        // Write the record: T^StartAddr^Length^ObjectCodes
        // Note: The buffer (e.g., "^1A2B^3C4D") already starts with a '^'
        fprintf(fp, "T^%06X^%02X%s\n", *start_addr, (*record_len) / 2, buffer);
        
        // Reset the buffer and length for the next record
        *record_len = 0;
        buffer[0] = '\0';
    }
}

int main() {
    // --- Variable Declarations ---
    char label[10], opcode[10], operand[10];
    char code[10], mnemonic[3];
    char sym_label[10], sym_addr[10];
    
    int locctr, start, length;
    long h_record_length_pos; // To store where to write the length in the H record

    FILE *fp_inter, *fp_sym, *fp_op, *fp_out, *fp_obj;

    // Buffers for the object file
    // Max T-record size is 30 bytes = 60 hex chars + 30 '^' separators
    char text_record[100] = ""; 
    int text_len = 0, record_start_addr = 0;
    
    // --- File Opening ---
    fp_inter = fopen("intert.txt", "r");
    fp_sym = fopen("symtab.txt", "r");
    fp_op = fopen("optab.txt", "r");
    fp_out = fopen("output.txt", "w");
    fp_obj = fopen("object.txt", "w");

    // Add file opening checks
    if (fp_inter == NULL || fp_sym == NULL || fp_op == NULL || fp_out == NULL || fp_obj == NULL) {
        printf("Error: Could not open one or more files.\n");
        return 1;
    }

    // --- Pass 2: First Line (START) ---
    // *** FIX: Read locctr as hex (%x) ***
    fscanf(fp_inter, "%x\t%s\t%s\t%s", &locctr, label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start = (int)strtol(operand, NULL, 16); // Correct: Read operand as hex
        fprintf(fp_out, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

        // Write Header record
        fprintf(fp_obj, "H^%-6s^%06X^", label, start);
        h_record_length_pos = ftell(fp_obj); 
        fprintf(fp_obj, "000000\n"); // Write placeholder and newline

        // *** FIX: Read next locctr as hex (%x) ***
        fscanf(fp_inter, "%x\t%s\t%s\t%s", &locctr, label, opcode, operand);
    } else {
        start = 0; 
        locctr = 0;
    }

    record_start_addr = locctr; // Set start address for *first* T-record

    // --- Pass 2: Main Processing Loop ---
    while (strcmp(opcode, "END") != 0) {
        int found_op = 0;
        
        // Search OPTAB for the opcode
        rewind(fp_op);
        while (fscanf(fp_op, "%s\t%s", code, mnemonic) != EOF) {
            if (strcmp(opcode, code) == 0) {
                // Found opcode, now find operand in SYMTAB
                int found_sym = 0;
                char obj_code[15];
                
                if (strcmp(operand, "**") != 0) { // Handle instructions with operands
                    rewind(fp_sym);
                    while (fscanf(fp_sym, "%s\t%s", sym_label, sym_addr) != EOF) {
                        if (strcmp(operand, sym_label) == 0) {
                            sprintf(obj_code, "%s%s", mnemonic, sym_addr);
                            found_sym = 1;
                            break; // Stop searching SYMTAB
                        }
                    }
                    if (!found_sym) {
                         printf("Error: Undefined symbol '%s' at LOCCTR %X\n", operand, locctr);
                         sprintf(obj_code, "%s0000", mnemonic); // Use 0000 for undefined symbol
                    }
                } else {
                    // Handle instructions with no operand (e.g., RSUB)
                    sprintf(obj_code, "%s0000", mnemonic);
                    found_sym = 1; // Mark as "found" to proceed
                }

                int new_code_len = strlen(obj_code); // 6 chars
                
                // *** TEXT RECORD LENGTH CHECK ***
                if (text_len + new_code_len > 60) {
                    write_text_record(fp_obj, &record_start_addr, &text_len, text_record);
                    record_start_addr = locctr;
                }
                
                fprintf(fp_out, "%X\t%s\t%s\t%s\t%s\n", locctr, label, opcode, operand, obj_code);

                strcat(text_record, "^");
                strcat(text_record, obj_code);
                text_len += new_code_len;
                
                found_op = 1;
                break; // Stop searching OPTAB
            }
        }

        // If not in OPTAB, it must be a directive (WORD, BYTE, RESW, RESB)
        if (!found_op) {
            if (strcmp(opcode, "WORD") == 0) {
                char obj_code[15];
                sprintf(obj_code, "%06X", atoi(operand)); // Convert decimal string to 6-digit hex
                int new_code_len = strlen(obj_code); // 6 chars

                // *** TEXT RECORD LENGTH CHECK ***
                if (text_len + new_code_len > 60) {
                    write_text_record(fp_obj, &record_start_addr, &text_len, text_record);
                    record_start_addr = locctr;
                }
                
                fprintf(fp_out, "%X\t%s\t%s\t%s\t%s\n", locctr, label, opcode, operand, obj_code);

                strcat(text_record, "^");
                strcat(text_record, obj_code);
                text_len += new_code_len;

            } else if (strcmp(opcode, "BYTE") == 0) {
                fprintf(fp_out, "%X\t%s\t%s\t%s\t", locctr, label, opcode, operand);

                // Handle C'...'
                if (operand[0] == 'C') {
                    for (int i = 2; i < strlen(operand) - 1; i++) {
                        // *** TEXT RECORD LENGTH CHECK (per byte) ***
                        if (text_len + 2 > 60) {
                            write_text_record(fp_obj, &record_start_addr, &text_len, text_record);
                            record_start_addr = locctr + (i-2); // Adjust locctr for new record
                        }
                        
                        char hex_val[3];
                        sprintf(hex_val, "%02X", operand[i]); // Use %02X for 2 digits
                        
                        fprintf(fp_out, "%s", hex_val); // Write 2-digit hex to output
                        strcat(text_record, "^");
                        strcat(text_record, hex_val);
                        text_len += 2; // 1 byte = 2 hex chars
                    }
                }
                // Handle X'...'
                else if (operand[0] == 'X') {
                    int new_code_len = 0;
                    for (int i = 2; i < strlen(operand) - 1; i++) {
                        new_code_len++;
                    }

                    // *** TEXT RECORD LENGTH CHECK (whole block) ***
                    if (text_len + new_code_len > 60) {
                        write_text_record(fp_obj, &record_start_addr, &text_len, text_record);
                        record_start_addr = locctr;
                    }

                    strcat(text_record, "^");
                    for (int i = 2; i < strlen(operand) - 1; i++) {
                        fprintf(fp_out, "%c", operand[i]); // Write hex digit to output
                        char hex_val[2];
                        hex_val[0] = operand[i];
                        hex_val[1] = '\0';
                        strcat(text_record, hex_val);
                    }
                    text_len += new_code_len; 
                }
                fprintf(fp_out, "\n");

            } else if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0) {
                fprintf(fp_out, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);
                
                // Write the current text record *before* the reservation
                write_text_record(fp_obj, &record_start_addr, &text_len, text_record);
            }
            else {
                printf("Error: Invalid opcode '%s' at LOCCTR %X\n", opcode, locctr);
            }
        }

        // *** FIX: Read next locctr as hex (%x) ***
        fscanf(fp_inter, "%x\t%s\t%s\t%s", &locctr, label, opcode, operand);

        // If the text record is empty, set the start address for the *next* one
        if (text_len == 0 && strcmp(opcode, "END") != 0) {
            record_start_addr = locctr;
        }
    }

    // --- End of Program ---

    // Write the last text record (if any)
    write_text_record(fp_obj, &record_start_addr, &text_len, text_record);

    // Write the End record
    fprintf(fp_obj, "E^%06X\n", start);

    // --- Fix H Record Length ---
    
    length = locctr - start; // This calculation is now correct

    // Go back to the saved position
    fseek(fp_obj, h_record_length_pos, SEEK_SET);

    // *** FIX: Apply bitmask to prevent overwrite ***
    // (length & 0xFFFFFF) ensures max 6 hex digits
    fprintf(fp_obj, "%06X", length & 0xFFFFFF); 

    // --- Cleanup ---
    fclose(fp_inter);
    fclose(fp_sym);
    fclose(fp_op);
    fclose(fp_out);
    fclose(fp_obj);

    printf("Pass 2 completed. Object program generated in object.txt\n");
    return 0;
}
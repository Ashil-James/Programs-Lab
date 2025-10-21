#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 * This function writes a text record to the object file.
 * It's called when a new record needs to start (e.g., after RESW/RESB)
 * or at the end of the program.
 */
void write_text_record(FILE *fp, int *start_addr, int *record_len, char buffer[]) {
    if (*record_len > 0) {
        // Write the record: T^StartAddr^Length^ObjectCodes
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
    char text_record[80] = "";
    int text_len = 0, record_start_addr = 0;

    // --- File Opening ---
    fp_inter = fopen("intert.txt", "r");
    fp_sym = fopen("symtab.txt", "r");
    fp_op = fopen("optab.txt", "r");
    fp_out = fopen("output.txt", "w");
    fp_obj = fopen("object.txt", "w");

    // --- Pass 2: First Line (START) ---
    fscanf(fp_inter, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
        start = atoi(operand); // Get starting address
        fprintf(fp_out, "\t%s\t%s\t%s\n", label, opcode, operand);

        // Write Header record
        // H^ProgramName^StartAddr^LENGTH_PLACEHOLDER
        fprintf(fp_obj, "H^%-6s^%06X^", label, start);
        
        // Save the file position *after* the '^' (at index 16)
        h_record_length_pos = ftell(fp_obj); 
        
        // Write a 6-char placeholder for length and a newline
        fprintf(fp_obj, "000000\n"); 

        // Read the next line from the intermediate file
        fscanf(fp_inter, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);
    } else {
        start = 0; // Assume start at 0 if no START directive
    }

    // Set the starting address for the *first* text record
    record_start_addr = locctr;

    // --- Pass 2: Main Processing Loop ---
    while (strcmp(opcode, "END") != 0) {
        int found_op = 0;
        
        // Search OPTAB for the opcode
        rewind(fp_op);
        while (fscanf(fp_op, "%s\t%s", code, mnemonic) != EOF) {
            if (strcmp(opcode, code) == 0) {
                // Found opcode, now find operand in SYMTAB
                rewind(fp_sym);
                while (fscanf(fp_sym, "%s\t%s", sym_label, sym_addr) != EOF) {
                    if (strcmp(operand, sym_label) == 0) {
                        // Found symbol! Generate object code
                        char obj_code[15];
                        sprintf(obj_code, "%s%s", mnemonic, sym_addr);
                        
                        fprintf(fp_out, "%d\t%s\t%s\t%s\t%s\n", locctr, label, opcode, operand, obj_code);

                        // Add to text record
                        strcat(text_record, "^");
                        strcat(text_record, obj_code);
                        text_len += 6; // 3 bytes = 6 hex chars
                        
                        break; // Stop searching SYMTAB
                    }
                }
                found_op = 1;
                break; // Stop searching OPTAB
            }
        }

        // If not in OPTAB, it must be a directive (WORD, BYTE, RESW, RESB)
        if (!found_op) {
            if (strcmp(opcode, "WORD") == 0) {
                char obj_code[15];
                sprintf(obj_code, "%06X", atoi(operand)); // Convert decimal to 6-digit hex
                
                fprintf(fp_out, "%d\t%s\t%s\t%s\t%s\n", locctr, label, opcode, operand, obj_code);

                // Add to text record
                strcat(text_record, "^");
                strcat(text_record, obj_code);
                text_len += 6;

            } else if (strcmp(opcode, "BYTE") == 0) {
                fprintf(fp_out, "%d\t%s\t%s\t%s\t", locctr, label, opcode, operand);
                strcat(text_record, "^");

                // Only handle C'...'
                if (operand[0] == 'C') {
                    for (int i = 2; i < strlen(operand) - 1; i++) {
                        fprintf(fp_out, "%X", operand[i]); // Write ASCII hex to output
                        char hex_val[3];
                        sprintf(hex_val, "%X", operand[i]); // Convert char to hex
                        strcat(text_record, hex_val);
                        text_len += 2; // 1 byte = 2 hex chars
                    }
                }
                fprintf(fp_out, "\n");

            } else if (strcmp(opcode, "RESW") == 0 || strcmp(opcode, "RESB") == 0) {
                fprintf(fp_out, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
                
                // Write the current text record *before* the reservation
                write_text_record(fp_obj, &record_start_addr, &text_len, text_record);
            }
        }

        // Read the next line
        fscanf(fp_inter, "%d\t%s\t%s\t%s", &locctr, label, opcode, operand);

        // If the text record is empty, set the start address for the *next* one
        if (text_len == 0) {
            record_start_addr = locctr;
        }
    }

    // --- End of Program ---

    // Write the last text record
    write_text_record(fp_obj, &record_start_addr, &text_len, text_record);

    // Write the End record
    fprintf(fp_obj, "E^%06X\n", start);

    // --- Fix H Record Length ---
    
    // Calculate total program length
    length = locctr - start; 

    // Go back to the saved position in the H record (index 16)
    fseek(fp_obj, h_record_length_pos, SEEK_SET);

    // Write the actual 6-digit hex length over the "000000" placeholder
    fprintf(fp_obj, "%06X", length);

    // --- Cleanup ---
    fclose(fp_inter);
    fclose(fp_sym);
    fclose(fp_op);
    fclose(fp_out);
    fclose(fp_obj);

    printf("Pass 2 completed. Object program generated in object.txt\n");
    return 0;
}
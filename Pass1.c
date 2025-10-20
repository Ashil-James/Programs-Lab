#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char label[10], opcode[10], operand[10];
    char code[10], mnemonic[10];
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4;

    // Open all files
    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intert.txt", "w");

    // Check if files opened successfully
    if (!fp1 || !fp2 || !fp3 || !fp4) {
        printf("Error opening one or more files.\n");
        exit(1);
    }

    // Read first line of input program
    fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);

    // Check for START directive
    if (strcmp(opcode, "START") == 0) {
        start = atoi(operand);
        locctr = start;
        fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);
        fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    } else {
        locctr = 0;
        start = 0;
    }

    // Process input lines until END opcode
    while (strcmp(opcode, "END") != 0) {
        fprintf(fp4, "%d\t", locctr); // print address to intermediate file

        // If label exists, store in symbol table
        if (strcmp(label, "**") != 0)
            fprintf(fp3, "%s\t%d\n", label, locctr);

        int found = 0;
        rewind(fp2);

        // Search opcode in OPTAB
        while (fscanf(fp2, "%s\t%s", code, mnemonic) != EOF) {
            if (strcmp(opcode, code) == 0) {
                locctr += 3; // instruction length = 3
                found = 1;
                break;
            }
        }

        // If opcode not found, handle directives
        if (!found) {
            if (strcmp(opcode, "WORD") == 0)
                locctr += 3;
            else if (strcmp(opcode, "RESW") == 0)
                locctr += 3 * atoi(operand);
            else if (strcmp(opcode, "RESB") == 0)
                locctr += atoi(operand);
            else if (strcmp(opcode, "BYTE") == 0) {
                if (operand[0] == 'X')
                    locctr += (strlen(operand) - 3) / 2;
                else
                    locctr += strlen(operand) - 3;
            } else {
                printf("Warning: Unknown opcode '%s' at address %d\n", opcode, locctr);
            }
        }

        // Write intermediate line
        fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);

        // Read next line
        if (fscanf(fp1, "%s\t%s\t%s", label, opcode, operand) == EOF)
            break;
    }

    // Write final END line
    fprintf(fp4, "%d\t%s\t%s\t%s\n", locctr, label, opcode, operand);

    // Calculate program length
    length = locctr - start;
    printf("\n✅ Pass 1 Successful.\n");
    printf("Program Length: %d (0x%X)\n", length, length);

    // Close all files
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    fclose(fp4);

    return 0;
}

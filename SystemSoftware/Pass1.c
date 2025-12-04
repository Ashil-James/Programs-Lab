#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char label[10], opcode[10], operand[10];
    char code[10], mnemonic[10];
    int locctr, start, length;
    FILE *fp1, *fp2, *fp3, *fp4;

    fp1 = fopen("input.txt", "r");
    fp2 = fopen("optab.txt", "r");
    fp3 = fopen("symtab.txt", "w");
    fp4 = fopen("intert.txt", "w");

    if (!fp1 || !fp2 || !fp3 || !fp4) {
         printf("Error opening one or more files.\n");
        exit(1);
     }

     fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);

    if (strcmp(opcode, "START") == 0) {
     sscanf(operand, "%x", &start);
     locctr = start;
        
        // **FIX 2: Print locctr as hexadecimal**
     fprintf(fp4, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);
     fscanf(fp1, "%s\t%s\t%s", label, opcode, operand);
    } else {
     locctr = 0;
     start = 0;
    }


     while (strcmp(opcode, "END") != 0) {
        // **FIX 3: Print locctr as hexadecimal**
    fprintf(fp4, "%X\t", locctr); // print address to intermediate file

    if (strcmp(label, "**") != 0)
            // **Also print symbol address as hex**
    fprintf(fp3, "%s\t%X\n", label, locctr);
    int found = 0;
    rewind(fp2);
     while (fscanf(fp2, "%s\t%s", code, mnemonic) != EOF) {
     if (strcmp(opcode, code) == 0) {
     locctr += 3; // instruction length = 3
     found = 1;
     break;
     }
    }

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
     printf("Warning: Unknown opcode '%s' at address %X\n", opcode, locctr);
    }
}
    
fprintf(fp4, "%s\t%s\t%s\n", label, opcode, operand);

    if (fscanf(fp1, "%s\t%s\t%s", label, opcode, operand) == EOF)
     break;
    }

fprintf(fp4, "%X\t%s\t%s\t%s\n", locctr, label, opcode, operand);

length = locctr - start;
printf("\nPass 1 Successful.\n");
printf("Program Length: %d (0x%X)\n", length, length); // This already shows hex

 fclose(fp1);
 fclose(fp2);
 fclose(fp3);
 fclose(fp4);
    
 return 0;
}
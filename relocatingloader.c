#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char length[10], input[10], bitmask[10], relobit;
    int start, len, i, address, opcode, addr, actualadd, add;

    FILE *fp1, *fp2;
    printf("Enter the actual address: ");
    scanf("%d", &start);

    fp1=fopen("relinput.txt", "r");
    fp2=fopen("reloutput.txt", "w");

    if(fp1==NULL || fp2==NULL)
    {
        printf("Error opening files");
        return 1;
    }

    fscanf(fp1,"%s",input);
    while(strcmp(input,"E")!=0)
    {
        if(strcmp(input,"H")==0)
        {
            fscanf(fp1,"%d", &add);
            fscanf(fp1,"%s", length);
            fscanf(fp1,"%s", input);
        }

        else if(strcmp(input, "T")==0)
        {
            fscanf(fp1,"%d", &address);
            fscanf(fp1,"%s", bitmask);
            address= address + start - add;
            len=strlen(bitmask);

            for(int i=0;i<len;i++)
            {
                fscanf(fp1,"%2d", &opcode);//fix: earlier it was written opcode and address separate(like 14 10002)
                fscanf(fp1,"%d", &addr);/
                relobit=bitmask[i];
                if(relobit =='0'){
                    actualadd=addr;
                }
                else{
                    actualadd=addr+start-add;
                }
                fprintf(fp2,"%d\t%02d%04d\n", address, opcode, actualadd);
                address+=3;
            }
            fscanf(fp1,"%s", input);
        }
    }
        fclose(fp1);
        fclose(fp2);
        printf("Relocation completed. Check reloutput.txt for results.\n");
        return 0;
}

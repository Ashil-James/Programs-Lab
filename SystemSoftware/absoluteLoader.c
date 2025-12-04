#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp;
    char name[10], name1[10],line[50], staddr[10];

    printf("enter program name: ");
    scanf("%s", name);

    fp=fopen("objectcode_abs.txt", "r");
    if(fp == NULL)
    {
        printf("Error");
        return 1;
    }  
    fscanf(fp, "%s", line);
    for(int i=2, j=0;j<6;i++,j++)
    {
        name1[j]=line[i];
    }
    name1[6]='\0';
    printf("name from obj. %s\n", name1);

    if(strcmp(name,name1)==0)
    {
        fscanf(fp,"%s", line);
        do{
            if(line[0] == 'T')
            {
                for(int i=2, j=0;j<6;i++,j++)
                {
                    staddr[j]=line[i];
                }
                staddr[6]='\0';
                int staddr1=atoi(staddr);
                int i=12;
                while(line[i]!='$')
                {
                    if(line[i]!='^')
                    {
                        printf("00%d\t%c%c\n", staddr1, line[i], line[i+1]);
                        i+=2;
                        staddr1++;
                    }
                    else{
                        i++;
                    }
                }
            } 
            else if(line[0]=='E')
            {
                printf("Jump to address: %s\n",&line[2]);    
            }
        } while(fscanf(fp,"%s",line)==1);
    }
    else{
        printf("program name doesnt match\n");
    }
    fclose(fp);
    return 0;
}
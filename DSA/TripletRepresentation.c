#include<stdio.h>
#include<stdlib.h>
int main()
{
    int tripletRep[50][50];
    int sparseMatrix[50][50];
    int r;
    int c;
    int index=1;

    printf("Enter the number of rows: ");
    scanf("%d",&r);
    printf("Enter the number of coloumns: ");
    scanf("%d",&c);

    printf("Enter the sparseMatrix: ");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            scanf("%d",&sparseMatrix[i][j]);
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(sparseMatrix[i][j]!=0)
            {
                tripletRep[index][0]=i;
                tripletRep[index][1]=j;
                tripletRep[index][2]=sparseMatrix[i][j];
                index++;
            }
        }
    }
    tripletRep[0][0]=r;
    tripletRep[0][1]=c;
    tripletRep[0][2]=index-1;

    printf("Triplet: \n");
    for(int i=0;i<index;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%d\t",tripletRep[i][j]);
        }
        printf("\n");
    }
    return 0;
}
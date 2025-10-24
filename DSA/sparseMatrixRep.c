#include<stdio.h> 
void main()
{
    int Tripletrep[20][3];  // Triplet representation has 3 columns only
    int sparseMatrix[20][20];

    int r, c;
    int index = 1;

    printf("Enter the rows: ");
    scanf("%d", &r);
    printf("Enter the columns: ");
    scanf("%d", &c);

    printf("Enter the elements of the sparse matrix:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &sparseMatrix[i][j]);
        }
    }

    Tripletrep[0][0] = r;
    Tripletrep[0][1] = c;

    // Convert sparse matrix to triplet representation
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            if(sparseMatrix[i][j] != 0)  // Check sparseMatrix not Tripletrep
            {
                Tripletrep[index][0] = i;
                Tripletrep[index][1] = j;
                Tripletrep[index][2] = sparseMatrix[i][j];
                index++;
            }
        }
    }

    Tripletrep[0][2] = index - 1;

    printf("Sparse Matrix:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d\t", sparseMatrix[i][j]);
        }
        printf("\n");
    }

    printf("Triplet Representation:\n");
    for(int i = 0; i < index; i++)
    {
        printf("%d %d %d\n", Tripletrep[i][0], Tripletrep[i][1], Tripletrep[i][2]);
    }
}

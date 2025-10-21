#include<stdio.h>
#define MAX 10

int main()
{
    int mat1[MAX][3];
    int mat2[MAX][3];
    int result[MAX][3];
    int m1, n1, m2, n2, num1, num2;
    int i = 0, j = 0, k = 0;

    // Input for the first matrix
    printf("Enter number of rows and columns for the first matrix: ");
    scanf("%d %d", &n1, &m1);
    printf("Enter number of non-zero elements for the first matrix: ");
    scanf("%d", &num1);

    printf("Enter row, column, and value for each non-zero element of the first matrix:\n");
    for (i = 0; i < num1; i++) {
        scanf("%d %d %d", &mat1[i][0], &mat1[i][1], &mat1[i][2]);
    }

    // Input for the second matrix
    printf("\nEnter number of rows and columns for the second matrix: ");
    scanf("%d %d", &n2, &m2);
    printf("Enter number of non-zero elements for the second matrix: ");
    scanf("%d", &num2);

    printf("Enter row, column, and value for each non-zero element of the second matrix:\n");
    for (i = 0; i < num2; i++) {
        scanf("%d %d %d", &mat2[i][0], &mat2[i][1], &mat2[i][2]);
    }

    i = 0;
    j = 0;
    k = 0;
    
    while (i < num1 && j < num2)
    {
        if (mat1[i][0] < mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] < mat2[j][1]))
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2];
            i++;
            k++;
        }
        else if (mat1[i][0] > mat2[j][0] || (mat1[i][0] == mat2[j][0] && mat1[i][1] > mat2[j][1]))
        {
            result[k][0] = mat2[j][0];
            result[k][1] = mat2[j][1];
            result[k][2] = mat2[j][2];
            j++;
            k++;
        }
        else
        {
            result[k][0] = mat1[i][0];
            result[k][1] = mat1[i][1];
            result[k][2] = mat1[i][2] + mat2[j][2];
            i++;
            j++;
            k++;
        }
    }

    // Add remaining elements from mat1
    while (i < num1)
    {
        result[k][0] = mat1[i][0];
        result[k][1] = mat1[i][1];
        result[k][2] = mat1[i][2];
        i++;
        k++;
    }

    // Add remaining elements from mat2
    while (j < num2)
    {
        result[k][0] = mat2[j][0];
        result[k][1] = mat2[j][1];
        result[k][2] = mat2[j][2];
        j++;
        k++;
    }

    // Print the resultant matrix in triplet form
    printf("\nResultant Sparse Matrix (in Triplet form):\n");
    printf("Row\tColumn\tValue\n");
    for (i = 0; i < k; i++) {
        printf("%d\t%d\t%d\n", result[i][0], result[i][1], result[i][2]);
    }

    return 0;
}

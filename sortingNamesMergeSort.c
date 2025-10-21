#include <stdio.h>
#include <string.h>

void display(char A[][50], int n) {
    for (int i = 0; i < n; i++)
        printf("%s\t", A[i]);
    printf("\n");
}

void merge(char A[][50], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    char B[50][50]; // Temporary array for merging

    while (i <= mid && j <= ub) {
        if (strcmp(A[i], A[j]) <= 0) {
            strcpy(B[k], A[i]);
            i++;
        } else {
            strcpy(B[k], A[j]);
            j++;
        }
        k++;
    }
    while (i <= mid) {
        strcpy(B[k], A[i]);
        i++;
        k++;
    }
    while (j <= ub) {
        strcpy(B[k], A[j]);
        j++;
        k++;
    }
    for (int x = lb; x <= ub; x++) {
        strcpy(A[x], B[x]);
    }
}

void mergeSort(char A[][50], int lb, int ub) {
    if (lb < ub) {
        int mid = (lb + ub) / 2;
        mergeSort(A, lb, mid);
        mergeSort(A, mid + 1, ub);
        merge(A, lb, mid, ub);
    }
}

int main() {
    int n;
    printf("Enter the size of the array (max 50): ");
    scanf("%d", &n);

    char arr[50][50]; // Array to store strings

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]); // Prevent buffer overflow
    }

    printf("Array Before Sorting:\n");
    display(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("Array After Sorting:\n");
    display(arr, n);

    return 0;
}

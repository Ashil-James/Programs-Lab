#include <stdio.h>

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int pivotLoc(int A[], int start, int end) {
    int pivot = A[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (A[i] <= pivot && i <= end - 1) {
            i++;
        }
        while (A[j] > pivot && j >= start + 1) {
            j--;
        }
        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
    // Swap the pivot with A[j] to place it in the correct position
    int t = A[start];
    A[start] = A[j];
    A[j] = t;
    return j;
}

void quickSort(int A[], int start, int end) {
    if (start < end) {
        int loc = pivotLoc(A, start, end);
        quickSort(A, start, loc - 1);
        quickSort(A, loc + 1, end);
    }
}

int main() {
    int arr[50];
    int n;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Array Before Sorting:\n");
    display(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Array After Sorting:\n");
    display(arr, n);
}

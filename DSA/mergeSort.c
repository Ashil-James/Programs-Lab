#include<stdio.h>

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void merge(int A[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    int B[100];

    while(i<=mid&&j<=ub)
    {
        if(A[i]<=A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else{
            B[k]=A[j];
            k++;
            j++; 
        }
    }

    while(j<=ub)
    {
        B[k]=A[j];
        j++;
        k++;
    }

    while(i<=mid)
    {
        B[k]=A[i];
        i++;
        k++;
    }

    for (int i = lb; i <= ub; i++)
    {
        A[i] = B[i];
    }

}

void mergeSort(int A[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(A,lb,mid);
        mergeSort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
}

int main(){
    int arr[50];
    int n;

    printf("Enter the size of array: ");
    scanf("%d",&n);

    printf("Enter the array elements: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array Before Sorting:\n");
    display(arr,n);

    mergeSort(arr,0,n-1);
    printf("Array After Sorting:\n");
    display(arr,n);
    return 0;
}
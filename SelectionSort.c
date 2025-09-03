#include<stdio.h>

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
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

    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
    printf("Array After Sorting:\n");
    display(arr,n);
    return 0;
}
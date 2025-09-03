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
    for(int i=1;i<n;i++)
    {
        int j=i;
        while(j>0&&arr[j]<arr[j-1]){
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
            j--;
        }
    }

    printf("Array After Sorting:\n");
    display(arr,n);
    return 0;
}
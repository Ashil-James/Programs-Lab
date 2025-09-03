#include<stdio.h>
int main()
{
    int ele;
    int arr[100];
    int search;
    int n;

    printf("Enter the array limit: ");
    scanf("%d",&n);

    printf("Enter array values: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    int l=0;
    int r=n-1;

    printf("Enter element to search ");
    scanf("%d",&search);
    while(l<=r){
        int mid=(l+r)/2;

        if(arr[mid]==search){
            printf("Element found at position %d ",(mid+1));
            break;
        }
        else if(arr[mid]<search)
        {
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    if(l>r){
        printf("Elemnt not found ");
    }
    return 0;    
}
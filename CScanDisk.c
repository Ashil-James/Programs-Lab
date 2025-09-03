//C-SCAN
#include<stdio.h>
#include<stdlib.h>

void sortArray(int arr[], int n){
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{
    int n, head, diskSize, direction;
    int requests[100];
    int left[100], right[100];
    int seekSequence[100], seekIndex=0;
    int l=0, r=0;

    printf("Enter the number of requestst: ");
    scanf("%d", &n);    
    printf("Enter the request sequence: ");
    for(int i=0;i<n;i++){
        scanf("%d", &requests[i]);
    }

    printf("Enter the intial head position: ");
    scanf("%d", &head);
    printf("Enter Total Disk Size: ");
    scanf("%d", &diskSize);
    printf("Enter The direction to move (0 for left, 1 for right): ");
    scanf("%d", &direction);

    for(int i=0;i<n;i++)
    {

            if(requests[i]<head)
            {
                left[l++]=requests[i];
            }
            else{
                right[r++]=requests[i];
            }
    }

    sortArray(left,l);
    sortArray(right,r);

    int currentPosition=head;
    printf("\nHead Movement:\n");
    if(direction==1)
    {
        for(int i=0;i<r;i++)
        {
            printf("Disk Moves From %d to %d\n", currentPosition, right[i]);
            seekSequence[seekIndex++]=right[i];
            currentPosition=right[i];
        }
        if(diskSize-1!=currentPosition)
        {
            printf("Disk Moves From %d to %d\n",currentPosition, diskSize-1);
            seekSequence[seekIndex++]=diskSize-1;
            currentPosition=diskSize-1;
        }

        printf("Disk Moves From %d to %d\n", currentPosition, 0);
        seekSequence[seekIndex++]=0;
        currentPosition=0;

        for(int i=0;i<l;i++)
        {
            printf("Disk Move From %d to %d\n", currentPosition, left[i]);
            seekSequence[seekIndex++]=left[i];
            currentPosition=left[i];
        }
    }

    else{
        for(int i=l-1;i>=0;i--)
        {
            printf("Disk Moves From %d to %d\n", currentPosition, left[i]);
            seekSequence[seekIndex++]=left[i];
            currentPosition=left[i];
        }
        if(currentPosition!=0)
        {
            printf("Disk Moves From %d to %d\n", currentPosition, 0);
            seekSequence[seekIndex++]=0;
            currentPosition=0;
        }
        printf("Disk Moves From %d to %d\n", currentPosition, diskSize-1);
        seekSequence[seekIndex++]=diskSize-1;
        currentPosition=diskSize-1;
        for(int i=r-1;i>=0;i--)
        {
            printf("Disk Moves From %d to %d\n", currentPosition, right[i]);
            seekSequence[seekIndex++]=right[i];
            currentPosition=right[i];
        }
    }
    
    int totHeadMovement=0;
    currentPosition=head;
    for(int i=0;i<seekIndex;i++)
    {
        totHeadMovement+=abs(seekSequence[i]-currentPosition);
        currentPosition=seekSequence[i];
    }
    printf("Total Head Movement: %d\n", totHeadMovement);
    return 0;
}
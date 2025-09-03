#include<stdio.h>

int main(){

    int no_of_pages, no_of_frames, pages[30], frames[10];
    int faults=0;
    int front=0;

    printf("Enter the number of frames: ");
    scanf("%d", &no_of_frames);
    printf("Enter the number of pages: ");
    scanf("%d", &no_of_pages);

    printf("Enter the refference string: ");
    for(int i=0;i<no_of_pages;i++)
    {
        scanf("%d", &pages[i]);
    }

    for(int i=0;i<no_of_frames;i++)
    {
        frames[i]=-1;
    }

    for(int i=0;i<no_of_pages;i++)
    {
        int page=pages[i];
        int pageFound=0;

        for(int j=0;j<no_of_frames;j++)
        {
            if(frames[j]==page)
            {
                pageFound=1;
                break;
            }
        }

        if(!pageFound)
        {
            frames[front]=page;
            front=(front+1)%no_of_frames;
            faults++;
        }

        printf("Current Frame:");
        for(int j=0;j<no_of_frames;j++)
        {
            printf("%d\t", frames[j]);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", faults);
    return 0;
}
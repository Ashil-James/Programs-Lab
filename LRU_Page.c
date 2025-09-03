#include<stdio.h>
#include<stdlib.h>

int main()
{
    int hit=0, miss=0;
    int v,f;

    printf("Enter the number of pages: ");
    scanf("%d",&v);
    printf("Enter the number of frames: ");
    scanf("%d",&f);

    int pages[v], frames[f], recent[f];

    printf("Enter the reference string: ");
    for(int i=0;i<v;i++)
    {
        scanf("%d",&pages[i]);
    }

    for(int i=0;i<f;i++){
        frames[i]=-1;
        recent[i]=-1;
    }

    for(int i=0;i<v;i++)
    {
        int page=pages[i];
        int found=0;

        for(int j=0;j<f;j++)
        {
            if(frames[j]==page)
            {
                hit++;
                found=1;
                recent[j]=i;
                break;
            }
        }

        if(!found)
        {
            miss++;
            int inserted=0;
            for(int j=0;j<f;j++)
            {
                if(frames[j]==-1)
                {
                    inserted=1;
                    frames[j]=page;
                    recent[j]=i;
                    break;
                }
            }

            if(!inserted)
            {
                int lruindex=0;
                for(int j=1;j<f;j++)
                {
                    if(recent[j]<recent[lruindex])
                    {
                        lruindex=j;
                    }
                }
                frames[lruindex]=page;
                recent[lruindex]=i;
            }
        }
        printf("Current Frame: ");
            for(int j=0;j<f;j++)
            {
                printf("%d\t", frames[j]);
            }
            printf("\n");
    }

    printf("\nTotal Hits: %d\n", hit);
    printf("Total Misses: %d\n", miss);
    return 0;
}
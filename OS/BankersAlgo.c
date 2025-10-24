#include<stdio.h>
#include<stdlib.h>

int main()
{
    int allocation[20][20],max[20][20],need[20][20],available[20];
    int m,n,c=0,completed=0,sequence[20],status[20];

    printf("Enter the number of processes:");
    scanf("%d",&m);
    printf("Enter the number of resources:");
    scanf("%d",&n);

    printf("Enter the allocation matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&allocation[i][j]);
        }
    }

    printf("Enter the max matrix:\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

    printf("Enter the available resources: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&available[i]);
    }

    for(int i=0;i<m;i++)
    {
        sequence[i]=0;
        status[i]=0;
    }
    for(int k=0;k<m;k++)
    {
        for(int i=0;i<m;i++)
        {
            if(status[i]==0)
            {
                int count=0;
                for(int j=0;j<n;j++)
                {
                    if(need[i][j]<=available[j]){
                        count++;
                    }
                }
                if(count==n){
                    status[i]=1;
                    sequence[c]=i;
                    c++;
                    completed++;
                    for(int j=0;j<n;j++)
                    {
                        available[j]+=allocation[i][j];
                    }
                }
            }
        }
    }

    if(completed==m){
        printf("The System is in a safe satate.\n");
        printf("The safe sequence is: ");
        for(int i=0;i<m;i++)
        {
            printf("P%d->",sequence[i]);
        }    
    }
    else{
        printf("The system is not in a safe state.\n");
        printf("The process is not completed.\n");
    }
    return 0;
}
#include<stdio.h>
struct process{
    int id,at,bt,wt,tat,ct,pt,stat;
};

int main()
{
    struct process p[20];
    int n,i;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the Process Details:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter ID|AT|BT|PT:\t");
        scanf("%d%d%d%d",&p[i].id,&p[i].at,&p[i].bt,&p[i].pt);
        p[i].stat=0;
    }
    float tottat=0,totwt=0,avgwt=0,avgtat=0;
    int time=0,completed=0;
    while(completed<n)
    {
        int min=32765,index=-1;
        for(i=0;i<n;i++)
        {
            if((p[i].at<=time)&&(p[i].stat==0))
            {
                if(p[i].pt<min)
                {
                    min=p[i].pt;
                    index=i;
                }
            }
        }
            if(index==-1)
            {
                time++;
            }
            else{
                time+=p[index].bt;
                p[index].ct=time;
                p[index].stat=1;
                completed++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            tottat+=p[i].tat;
            totwt+=p[i].wt;
        }   
        avgwt=totwt/n;
        avgtat=tottat/n;
        printf("ID\tPT\tAT\tBT\tCT\tTAT\tWT\n");
        for(i=0;i<=n-1;i++)
        {
            printf("%d \t%d \t%d \t%d \t%d \t%d \t%d\n",p[i].id,p[i].pt,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
        }
        printf("Average Turn Around Time :%f\n",avgtat);
        printf("Average Waiting Time     :%f\n",avgwt);
        return 0;
}
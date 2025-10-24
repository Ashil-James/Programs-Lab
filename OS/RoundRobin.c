#include<stdio.h>

struct process
{
    int id,at,bt,wt,tat,ct,stat,qstat,rbt;
}p[20];

int Q[100];
int front=-1,rear=-1;

void enqueue(int item)
{
    if(rear==-1)
    {
        rear=0;
        front=0;
    }
    else
    {
        rear++;
    }
    Q[rear]=item;
}


int dequeue()
{
    int item=Q[front];
    front++;
    return item;
}

int main()
{

    int i,j,tq,n;
    float tottat=0,totwt=0,avgwt=0,avgtat=0;
    int completed=0,current_time=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    printf("Enter the time quantum: ");
    scanf("%d",&tq);

    printf("Enter the Process Details:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter ID|AT|BT:\t");
        scanf("%d%d%d",&p[i].id,&p[i].at,&p[i].bt);
        p[i].stat=0;
        p[i].qstat=0;
        p[i].rbt=p[i].bt;
    }

    
    enqueue(0);
    p[0].qstat=1;
    current_time=p[0].at;

    while(completed!=n)
    {
        i=dequeue();
        if(p[i].rbt>tq)
        {
            current_time+=tq;
            p[i].rbt-=tq;
        }
        else{
            current_time+=p[i].rbt;
            p[i].ct=current_time;
            p[i].tat=p[i].ct-p[i].at;
            p[i].wt=p[i].tat-p[i].bt;
            p[i].rbt=0;
            p[i].stat=1;
            completed++;
        }

        for(j=(i+1);j<n;j++)
        {
            if((p[j].at<=current_time)&&(p[j].stat==0)&&(p[j].qstat==0))
            {
              enqueue(j);
              p[j].qstat=1;
            }
        }

        if(p[i].rbt!=0)
        {
            enqueue(i);
        }
    }

    for(i=0;i<n;i++)
    {
        tottat+=p[i].tat;
        totwt+=p[i].wt;
    }

    avgwt=totwt/n;
    avgtat=tottat/n;

    printf("ID\tAT\tBT\tCT\tTAT\tWT\n");
    for(i=0;i<n;i++)
    {
    printf("%d \t%d \t%d \t%d \t%d  \t%d\n",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
    printf("Average Turn Around Time :%f\n",avgtat);
    printf("Average Waiting Time     :%f\n",avgwt);
    return 0;
}
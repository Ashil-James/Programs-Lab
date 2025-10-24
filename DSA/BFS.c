#include<stdio.h>
#include<stdlib.h>

int G[50][50];
int Q[50];
int visited[50];
int N;
int f=-1;
int r=-1;

void enqueue(int x){
    if(r==(N-1))
    {
        printf("overFlow!");
        return;
    }
    if(f==-1)
    {
        f=0;
    }
    r++;
    Q[r]=x;
}

int dequeue()
{
    if(f==-1)
    {
        return -1;
    }
    int ele=Q[f];
    if(f==r)
    {
        f=-1;
        r=-1;
    }
    else{
        f++;
    }
    return ele;
}

void bfs(int s)
{
    visited[s]=1;
    printf("%d ",s);
    enqueue(s);
    while(f!=-1)
    {
        s=dequeue();
        for(int i=1;i<=N;i++)
        {
            if(G[s][i]==1&&visited[i]==0)
            {
                printf("%d ",i);
                visited[i]=1;
                enqueue(i);
            }
        }
    }
}

int main()
{
    int v;
    int edge;
    printf("Enter the number of vertices: ");
    scanf("%d",&N);

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j++)
        {
            printf("Edge %d to %d:",i,j);
            scanf("%d",&edge);
            G[i][j]=edge;
            G[j][i]=edge;
        }
    }

    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            printf("%d\t",G[i][j]);
        }
        printf("\n");
    }

    for(int i=1;i<=N;i++)
    {
        visited[i]=0;
    }

    printf("Enter starting node: ");
    scanf("%d",&v);
    printf("BFS Traversal");
    bfs(v);
    printf("\n");
}
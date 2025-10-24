#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int N;
int Adj[MAX][MAX];
int visited[MAX];

void dfs(int v){
    visited[v]=1;
    printf("%d ",v);
    for(int i=0;i<N;i++){
        if(Adj[v][i]==1&&visited[i]==0)
        {
            dfs(i);
        }
    }
}

int main()
{
    int v;
    int edge;

    printf("Enter the number of vertices: ");
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            Adj[i][j]=0;
        }
        visited[i]=0;
    }

    printf("Enter the edges: ");
    for(int i=0;i<N;i++)
    {
        for(int j=i;j<N;j++)
        {
            printf("Edge %d to %d: ",i,j);
            scanf("%d",&edge);  
            Adj[i][j]=edge;
            Adj[j][i]=edge;
        }
    }

    printf("Adjacency Matrix:\n");
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            printf("%d ",Adj[i][j]);
        }
        printf("\n");
    }
    printf("Enter starting: ");
    scanf("%d",&v);
    dfs(v);
    return 0;
}
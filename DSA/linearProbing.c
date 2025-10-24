#include<stdio.h>
#include<stdlib.h>

int hashFunction(int k,int m)
{
    return k%m;
}

void insert(int ht[],int k,int m)
{
    int index=hashFunction(k,m);
    int orgIndex=index;
    while(ht[index]!=-1)
    {
        index=(index+1)%m;
        if(index==orgIndex)
        {
            printf("HashTable is Full\n");
            return;
        }
    }
    ht[index]=k;
}

void display(int ht[],int m){
    for(int i=0;i<m;i++)
    {
        if(ht[i]!=-1)
        {
            printf("Index %d:%d\n",i,ht[i]);
        }
        else{
            printf("Index %d: Empty\n",i);
        }
    }
}

int main()
{
    int m;
    int n;
    int k;
    int ht[50];

    printf("Enter the number of Memory Locations: ");
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        ht[i]=-1;
    }

    printf("Enter the number of records: ");
    scanf("%d",&n);

    if(n>m)
    {
        printf("Number of records exceeds hash table size\n");
    }
    else{
        for(int i=0;i<n;i++)
        {
            printf("Enter the key: ");
            scanf("%d",&k);
            insert(ht,k,m);
        }

        printf("\n");
        display(ht,m);
    }
    return 0;
}
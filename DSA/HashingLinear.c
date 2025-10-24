#include<stdio.h>
#include<stdlib.h>

int hashFunction(int k,int m)
{
    return k%m;
}

void insert(int HT[],int k,int m)
{
    int index=hashFunction(k,m);
    int original_index=index;

    while(HT[index]!=-1){
        index=(index+1)%m;
        if(index==original_index)
        {
            printf("Hash-Table is FULL");
            return;
        }
    }
    HT[index]=k;
}

void display(int HT[],int m)
{
    printf("Hash Table: \n");
    for(int i=0;i<m;i++)
    {
        if(HT[i]!=-1)
        {
            printf("Index %d: %d\n",i,HT[i]);
        }
        else{
            printf("Index %d: Empty\n",i);  
        }
    }
}

int main()
{
    int k;
    int m;
    int n;
    int HT[50];
    printf("Enter the number of Memory Locations: ");
    scanf("%d",&m);

    printf("Enter the number of Records: ");
    scanf("%d",&n);

    for(int i=0;i<m;i++)
    {
        HT[i]=-1;
    }

    if(n>m)
    {
        printf("Number of records exceeds hash table ");
    }
    else{
        for(int i=0;i<n;i++)
        {
            printf("Enter Key: ");
            scanf("%d",&k);
            insert(HT,k,m);
        }

        printf("\n");
        display(HT,m);
    }
    return 0;
}
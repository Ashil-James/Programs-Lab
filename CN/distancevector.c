#include <stdio.h>

struct node{
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main(){
    int costmat[20][20];
    int nodes, i, j, k, count = 0;

    printf("\n Enter the number of nodes: ");
    scanf("%d", &nodes);

    printf("Enter the costmatrix:\n");
    printf("Enter 999 for no link, 0 for self - loop");

    for(int i = 0 ; i < nodes ; i++){
        for(int j=0; j < nodes; j++){
            scanf("%d",&costmat[i][j]);

            if(i == j) {
                costmat[i][j] = 0;
            }

            rt[i].dist[j] = costmat[i][j];
            rt[i].from[j] = j;
        }
    }

    do {
        count = 0;
        for(int i=0; i < nodes; i++){
            for(int j = 0; j < nodes; j++){
                for(int k = 0; k < nodes; k++){
                    if(rt[i].dist[j] > costmat[i][k] + rt[k].dist[j]){
                        rt[i].dist[j] = costmat[i][k] + rt[k].dist[j];
                        rt[i].from[j] = k;
                        count++; 
                    }
                }
            }
        }
    } while(count != 0 );

    for (i = 0; i < nodes; i++) {
        printf("\n\nRouting Table for Router %d\n", i + 1);
        printf("Destination\tNext Hop\tCost\n");
        printf("-----------------------------------------\n");

        for (j = 0; j < nodes; j++) {
            printf("%d\t\t%d\t\t%d\n",
                j + 1,
                rt[i].from[j] + 1,
                rt[i].dist[j]);
        }
    }

    printf("\n");
    return 0;
}
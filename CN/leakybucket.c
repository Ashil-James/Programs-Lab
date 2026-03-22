#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
#include<math.h>

#define  NOF_PACKETS 10

int get_rand(int a){
    int rn = rand() % a;
    return rn == 0 ? 1 : rn;
}

int main(){
    int packet_sz[NOF_PACKETS], clk, b_size, o_rate;
    int p_sz_rm = 0, p_time, op = 0;

    srand(time(NULL));

    for(int i=0; i<NOF_PACKETS; i++){
        packet_sz[i] = get_rand(6) * 10;
    }

    for(int i=0; i<NOF_PACKETS; i++){
        printf("\npacket[%d]: %d bytes", i, packet_sz[i]);
    }

    printf("\n\nEnter the output rate: ");
    scanf("%d", &o_rate);
    printf("Enter the Bucket size: ");
    scanf("%d", &b_size);

    for(int i=0; i<NOF_PACKETS; i++){
        if((packet_sz[i] + p_sz_rm) > b_size){
            if(packet_sz[i] > b_size){
                printf("\n\nIncoming packet size (%d bytes) is greater than " 
                    "bucket capacity (%d bytes) - PACKET REJECTED",packet_sz[i], b_size);
            }
            else {
                printf("\n\n Bucket capacity exceeded - PACKET REJECTED");
            }
        }
        else {
            p_sz_rm += packet_sz[i];
            printf("\n\nIncoming packet size: %d bytes", packet_sz[i]);
            printf("\n Bytes Remaining in bucket: %d", p_sz_rm);
            
            p_time = get_rand(4) * 10;
            printf("\n Time allocated for transmission: %d units", p_time);

            for(clk=0; clk<p_time; clk+=10){
                sleep(1);

                if(p_sz_rm > 0){
                    if(p_sz_rm <= o_rate){
                        op=p_sz_rm;
                        p_sz_rm = 0;
                    } else {
                        op = o_rate;
                        p_sz_rm -= o_rate;
                    }
                    printf("\n Clock tick %d: Transmitted %d bytes" 
                        " | Remanining in bucket: %d",(clk + 10), op, p_sz_rm);
                } else {
                    printf("\n Clock tick %d: No packets to transmit"
                        " | Time Remaining: %d units",(clk + 10), (p_time - clk - 10));
                }
            }
        }
    }
    printf("\n");
    return 0;
}
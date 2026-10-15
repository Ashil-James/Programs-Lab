#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_TRANSITION 100
#define MAX_STATES 100
#define MAX_ALPHABET 20

typedef struct {
    int from_state;
    char symbol;
    int to_state;
} Transition;

Transition transition_table[MAX_TRANSITION];
int num_transitions;
int num_states;

void compute_epsilon_closure(int current_state, bool closure[]) {
    closure[current_state] = true;

    for(int i=0; i<num_transitions; i++) {
        if(transition_table[i].from_state == current_state && transition_table[i].symbol == 'e') {
            int next_state = transition_table[i].to_state;

            if(!closure[next_state]) {
            compute_epsilon_closure(next_state, closure);
            }
        }
    }
}


int main() {
    
    printf("Enter the number of states: ");
    scanf("%d", &num_states);
    
    printf("Enter the number of transitions: ");
    scanf("%d", &num_transitions);

    printf("Enter the transitions in the format: from_state symbol to_state: \n");
    for(int i=0; i<num_transitions; i++) {
        scanf("%d %c %d", 
            &transition_table[i].from_state,
            &transition_table[i].symbol,
            &transition_table[i].to_state);
    }

    printf("Epsilon Closure: \n");
    for(int i=0; i<num_states; i++) {
        bool closure[MAX_STATES] = {false};
        compute_epsilon_closure(i, closure);

        printf("e-closure(q%d) = {", i);
        for(int j=0; j<num_states; j++) {
            if(closure[j]) {
                printf("q%d", j);
            }
        }

        printf("}\n");
    }

    return 0;
}

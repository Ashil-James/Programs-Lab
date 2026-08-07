#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_TRANSITIONS 100
#define MAX_STATES 100
#define MAX_ALPHABETS 20

typedef struct {
    int from_state;
    char symbol;
    int to_state;
} Transition;

Transition transition_table[MAX_TRANSITIONS];
int num_transitions;
int num_states;

void compute_epsilon_closure(int current_state, bool closure[]) {
    closure[current_state] = true;

    for (int i = 0; i < num_transitions; i++) {
        if (transition_table[i].from_state == current_state &&
            transition_table[i].symbol == 'e') {

            int next_state = transition_table[i].to_state;

            if (!closure[next_state]) {
                compute_epsilon_closure(next_state, closure);
            }
        }
    }
}

int main() {
    int num_alphabets;
    char alphabets[MAX_ALPHABETS];
    int start_state;
    int num_final_states;
    int final_states[MAX_STATES];

    printf("Enter the number of states: ");
    scanf("%d", &num_states);

    printf("Enter the number of alphabets (including epsilon as 'e'): ");
    scanf("%d", &num_alphabets);

    printf("Enter the alphabets (e must be last): ");
    for (int i = 0; i < num_alphabets; i++) {
        scanf(" %c", &alphabets[i]);
    }

    printf("Enter the start state: ");
    scanf("%d", &start_state);

    printf("Enter the number of final states: ");
    scanf("%d", &num_final_states);

    printf("Enter the final states:\n");
    for (int i = 0; i < num_final_states; i++) {
        scanf("%d", &final_states[i]);
    }

    printf("Enter the number of transitions: ");
    scanf("%d", &num_transitions);

    printf("Enter transitions in the format: from_state symbol to_state\n");
    for (int i = 0; i < num_transitions; i++) {
        scanf("%d %c %d",
            &transition_table[i].from_state,
            &transition_table[i].symbol,
            &transition_table[i].to_state);
    }

    printf("Epsilon Closures:\n");
    for (int i = 0; i < num_states; i++) {
        bool closure[MAX_STATES] = {false};

        compute_epsilon_closure(i, closure);

        printf("e-Closure(q%d) = { ", i);
        for (int j = 0; j < num_states; j++) {
            if (closure[j]) {
                printf("q%d ", j);
            }
        }
        printf("}\n");
    }

    return 0;
}
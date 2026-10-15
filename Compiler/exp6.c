#include<stdio.h>
#include<stdlib.h>

#define MAX 10

char nfa[MAX][MAX][MAX];
char nfa_no_e[MAX][MAX][MAX];
char symbols[MAX];
int n_state, n_symbols;

void compute_epsilon_closure(int state, int closure[MAX]) {
    if(closure[state] == 1) {
        return;
    }
    closure[state] = 1;

    for(int i=0; i<n_state; i++) {
        if(nfa[state][n_symbols][i] == '1') {
            compute_epsilon_closure(i, closure);
        }
    }
}

void initialize_table() {
    printf("Enter number of states: ");
    scanf("%d", &n_state);

    printf("Enter the number of states (excluding e): ");
    scanf("%d", &n_symbols);

    printf("Enter the symbols: ");
    for(int i=0; i<n_symbols; i++) {
        scanf(" %c", &symbols[i]);
    }

    symbols[n_symbols] = 'e';

    for(int i=0; i<n_state; i++){
        for(int j=0; j<MAX; j++) {
            for(int k=0; k<n_state; k++) {
                nfa[i][j][k] = '0';
                nfa_no_e[i][j][k] = '0';
            }
        }
    }
    
    int trans;
    printf("Enter the number of transitions: ");
    scanf("%d", &trans);
    
    printf("Enter the transitions (From Symbol To)");
    for(int i=0; i<trans; i++) {
        int start, end;
        char symbol;

        scanf("%d %c %d", &start, &symbol, &end);
        int symbol_index;

        if(symbol == 'e') {
            symbol_index = n_symbols;
        } else {
            for(int j=0; j<n_symbols; j++) {
                if(symbols[j] == symbol) {
                    symbol_index = j;
                    break;
                }
            }
        }
        nfa[start][symbol_index][end] = '1';
    }
} 

void print_nfa_formatted(char table[MAX][MAX][MAX], int symbols_count) {
    for(int i=0; i<n_state; i++) {
        for(int j=0; j<symbols_count; j++) {
            for(int k=0; k<n_state; k++) {
                if(table[i][j][k] == '1') {
                    printf("q%d %c q%d\n", i, symbols[j], k);
                }
            }
        }
    }
}

void convert_to_nfa_without_epsilon() {
    for(int state=0; state<n_state; state++) {
        int start_closure[MAX] = {0};
        compute_epsilon_closure(state, start_closure);

        for(int sym=0; sym<n_symbols; sym++) {
            for(int i=0; i<n_state; i++ ){
                if(start_closure[i] == 1) {
                    for(int j=0; j<n_state; j++) {
                        if(nfa[i][sym][j] == '1') {
                            int dest_closure[MAX] = {0};
                            compute_epsilon_closure(j, dest_closure);

                            for(int k=0; k<n_state; k++) {
                                if(dest_closure[k] == 1) {
                                    nfa_no_e[state][sym][k] = '1';
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    initialize_table();
    convert_to_nfa_without_epsilon();
    printf("\nFormatted NFA Without Epsilon: \n");
    print_nfa_formatted(nfa_no_e, n_symbols);

    return 0;
}

#include<stdio.h>

#define MAX 10
#define MAX_DFA 100

int n, m;

int nfa[MAX][MAX][MAX];
int dfa_states[MAX_DFA][MAX];
int dfa[MAX_DFA][MAX];

int dfaCount = 0;

int sameSet(int a[], int b[]) {
    for(int i=0; i<n; i++) {
        if(a[i] != b[i]) {
            return 0;
        }
    }

    return 1;
}

int findState(int set[]) {
    for(int i=0; i<dfaCount; i++){
        if(sameSet(dfa_states[i], set)) {
            return i;
        }
    }

    return -1;
}

void printSet(int set[]) {
    printf("{");
    int first = 1;

    for(int i=0; i<n; i++) {
        if(set[i]) {
            if(!first) {
                printf(",");
            }
            printf("%d", i);
            first = 0;
        }
    }
    printf("}");
}

int main() {
    int count, state;
    printf("Enter number of NFA states"); 
    scanf("%d", &n);

    printf("Enter the number of Alphabets");
    scanf("%d", &m);

    printf("\nEnter transitions:\n");
    printf("First enter number of destination states, followed by states.\n");
    printf("Example: 2 0 1 means {0,1}\n");
    printf("Example: 0 means no transition.\n\n");

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            printf("Transition from %d to %d: ", i, j);
            scanf("%d", &count);
            for(int k=0; k<count; k++) {
                scanf("%d", &state);
                nfa[i][j][state] = 1;
            }
        }
    }

    dfaCount = 1;
    for(int i=0; i<n; i++) {
        dfa_states[0][i] = 0;
    }

    dfa_states[0][0] = 1;

    for(int i=0; i<dfaCount; i++) {
        for(int symbol=0; symbol<m; symbol++) {
            int newSet[MAX] = {0};

            for(int state=0; state<n; state++) {
                if(dfa_states[i][state]) {
                    for(int next=0; next<n; next++) {
                        if(nfa[state][symbol][next] == 1) {
                            newSet[next] = 1;
                        }
                    }
                }
            }
            int index = findState(newSet);

            if(index == -1) {
                index = dfaCount;

                for(int k=0; k<n; k++) {
                    dfa_states[dfaCount][k] = newSet[k];
                }
                dfaCount++;
            }
            dfa[i][symbol] = index;
        }
    }
    

         /* Print DFA transition table */
    printf("\nDFA Transition Table:\n\n");

    printf("%-15s", "State");

    for (int i = 0; i < m; i++)
        printf("%-15d", i);

    printf("\n");

    printf("---------------------------------------------\n");

    for(int i=0; i<dfaCount; i++) {
        printSet(dfa_states[i]);
        printf("%*s", 10, "");

        for(int symbol=0; symbol<m; symbol++) {
            int next = dfa[i][symbol];
            printSet(dfa_states[next]);
            printf("%*s", 8, "");
        }
        printf("\n");
    }
    return 0;
}



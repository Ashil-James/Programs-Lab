#include <stdio.h>

int frames[100][3], frames_updated = 0;

// Check if page is in frame
int search(int x) {
    int c = -1;
    for (int i = 0; i < frames_updated; i++) {
        if (frames[i][0] == x) {
            c = i;
        }
    }
    return c;
}

// Find least frequently used frame
int replace() {
    int index = 0, small = frames[0][2];
    for (int i = 1; i < frames_updated; i++) {
        if (small > frames[i][2]) {
            index = i;
            small = frames[i][2];
        } else if (frames[index][2] == frames[i][2] && frames[index][1] > frames[i][1]) {
            index = i;
        }
    }
    return index;
}

int main() {
    int n, ref[100], pf = 0, nf, i, j, p, current_time = 0, index, f, freq = 0;

    printf("Enter the number of frames:\n");
    scanf("%d", &nf);

    printf("Enter the number of page requests:\n");
    scanf("%d", &n);

    printf("Enter the reference string:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &ref[i]);
    }

    // Initialize frames to empty (-1)
    for (i = 0; i < nf; i++) {
        frames[i][0] = -1;
        frames[i][1] = -1;
        frames[i][2] = -1;
    }

    for (i = 0; i < n; i++) {
        p = ref[i];

        freq = 0;
        for (j = 0; j < i; j++) {
            if (p == ref[j]) {
                freq++;
            }
        }

        f = search(p);

        if (f == -1) {
            // Page fault
            pf++;
            if (frames_updated < nf) {
                frames[frames_updated][0] = p;
                frames[frames_updated][1] = current_time;
                frames[frames_updated][2] = freq;
                frames_updated++;
            } else {
                index = replace();
                frames[index][0] = p;
                frames[index][1] = current_time;
                frames[index][2] = freq;
            }
        } else {
            // Page hit, update frequency
            frames[f][2] = freq;
        }

        // Print current frame status
        printf("Current frames: ");
        for (j = 0; j < nf; j++) {
            if (frames[j][0] == -1)
                printf("-\t");
            else
                printf("%d\t", frames[j][0]);
        }
        printf("\n");

        current_time++;
    }

    printf("\nNumber of page faults = %d\n", pf);

    return 0;
}
#include <stdio.h>
#include <limits.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

int findLFUIndex(int frames[], int frequency[], int age[], int frameCount) {
    int minFreq = INT_MAX;
    int oldestAge = -1;
    int lfuIndex = -1;

    for (int i = 0; i < frameCount; i++) {
        if (frequency[i] < minFreq ||
            (frequency[i] == minFreq && age[i] > oldestAge)) {
            minFreq = frequency[i];
            oldestAge = age[i];
            lfuIndex = i;
        }
    }

    return lfuIndex;
}

int isInMemory(int frames[], int frameCount, int page, int *index) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            *index = i;
            return 1;
        }
    }
    return 0;
}

void printFrames(int frames[], int frameCount) {
    printf("Frames: ");
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int main() {
    int pageCount, frameCount;
    int pages[MAX_PAGES];
    int frames[MAX_FRAMES];
    int frequency[MAX_FRAMES];
    int age[MAX_FRAMES];
    int pageFaults = 0;
    int time = 0;

    printf("Enter number of pages: ");
    scanf("%d", &pageCount);

    printf("Enter page reference string: ");
    for (int i = 0; i < pageCount; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    // Initialize
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
        frequency[i] = 0;
        age[i] = 0;
    }

    for (int i = 0; i < pageCount; i++) {
        int page = pages[i];
        time++;
        int index;

        printf("\nProcessing page %d:\n", page);

        if (isInMemory(frames, frameCount, page, &index)) {
            frequency[index]++;
            age[index] = time;
            printf("Page %d -> HIT\n", page);
        } else {
            pageFaults++;

            int replaceIndex = -1;

            // Check for empty frame
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty frame, find LFU
            if (replaceIndex == -1) {
                replaceIndex = findLFUIndex(frames, frequency, age, frameCount);
            }

            frames[replaceIndex] = page;
            frequency[replaceIndex] = 1;
            age[replaceIndex] = time;

            printf("Page %d -> FAULT (replaced frame %d)\n", page, replaceIndex);
        }

        // Print current state of frames
        printFrames(frames, frameCount);
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
    return 0;
}

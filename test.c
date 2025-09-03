#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int n, head, disk_size, direction;
    int requests[100], left[100], right[100];
    int i, l = 0, r = 0, seek_count = 0;
    int seek_sequence[200];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request sequence: ");
    for (i = 0; i < n; i++)
        scanf("%d", &requests[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter total disk size (maximum cylinder number): ");
    scanf("%d", &disk_size);

    printf("Enter direction (0 for lower side, 1 for higher side): ");
    scanf("%d", &direction);

    for (i = 0; i < n; i++) {
        if (requests[i] < head)
            left[l++] = requests[i];
        else
            right[r++] = requests[i];
    }

    sort(left, l);
    sort(right, r);

    int current_position = head;
    printf("\nHead Movement:\n");

    if (direction == 1) {
        // Move to higher values first
        for (i = 0; i < r; i++) {
            printf("Move from %d to %d\n", current_position, right[i]);
            seek_sequence[seek_count++] = right[i];
            current_position = right[i];
        }
        if (disk_size - 1 > right[r - 1]) {
            printf("Move from %d to %d\n", current_position, disk_size - 1);
            seek_sequence[seek_count++] = disk_size - 1;
            current_position = disk_size - 1;
        }
        for (i = l - 1; i >= 0; i--) {
            printf("Move from %d to %d\n", current_position, left[i]);
            seek_sequence[seek_count++] = left[i];
            current_position = left[i];
        }
    } else {
        // Move to lower values first
        for (i = l - 1; i >= 0; i--) {
            printf("Move from %d to %d\n", current_position, left[i]);
            seek_sequence[seek_count++] = left[i];
            current_position = left[i];
        }
        if (left[0] > 0) {
            printf("Move from %d to %d\n", current_position, 0);
            seek_sequence[seek_count++] = 0;
            current_position = 0;
        }
        for (i = 0; i < r; i++) {
            printf("Move from %d to %d\n", current_position, right[i]);
            seek_sequence[seek_count++] = right[i];
            current_position = right[i];
        }
    }

    // Calculate total seek time
    int total_seek = 0;
    current_position = head;
    for (i = 0; i < seek_count; i++) {
        total_seek += abs(seek_sequence[i] - current_position);
        current_position = seek_sequence[i];
    }

    printf("\nTotal Seek Time: %d\n", total_seek);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *front = NULL, *rear = NULL, *temp;

void enqueue(int data) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    p->data = data;
    p->link = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = p;
    } else {
        rear->link = p;
        rear = p;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Empty\n");
        return;
    }
    temp = front;
    front = front->link;
    free(temp);
    if (front == NULL) {
        rear = NULL;
    }
}

void display() {
    if (front == NULL) {
        printf("Empty\n");
        return;
    }
    temp = front;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    int ch, data;
    while (1) {
        printf("\nMENU\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        if (ch == 1) {
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            display();
        } else if (ch == 2) {
            dequeue();
            display();
        } else if (ch == 3) {
            display();
        } else if (ch == 4) {
            exit(0);
        } else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

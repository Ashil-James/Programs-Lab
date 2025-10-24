#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* insert(struct node* Node, int ele) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = ele;
    p->link = NULL;

    if (Node == NULL) {
        return p;
    }

    struct node* temp = Node;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;

    return Node;
}

void peakElements(struct node* list) {
    if (list == NULL || list->link == NULL) {
        return; // Handle empty or single-node lists
    }

    struct node* prev = list;
    struct node* curr = list->link;

    // Check if the first node is a peak
    if (prev->data >= curr->data) {
        printf("%d ", prev->data);
    }

    while (curr->link != NULL) {
        struct node* next = curr->link;

        if (curr->data > prev->data && curr->data > next->data) {
            printf("%d ", curr->data);
        }

        prev = curr;
        curr = next;
    }

    // Check if the last node is a peak
    if (curr->data > prev->data) {
        printf("%d ", curr->data);
    }
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->link != NULL) {
            printf("->");
        }
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct node* exp = NULL;
    exp = insert(exp, 20);
    exp = insert(exp, 10);
    exp = insert(exp, 9);
    exp = insert(exp, 8);
    exp = insert(exp, 7);
    exp = insert(exp, 6);
    exp = insert(exp, 5);

    printf("Linked List: ");
    display(exp);

    printf("Peak elements: ");
    peakElements(exp);

    return 0;
}
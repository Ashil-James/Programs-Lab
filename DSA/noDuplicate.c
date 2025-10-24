#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* link;
};

struct node* insert(struct node* head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = NULL;

    if (head == NULL) {
        return new_node;
    }

    struct node* temp = head;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = new_node;
    return head;
}

struct node* removeDuplicate(struct node* list1, struct node* list2) {
    struct node* noCommon = NULL;
    int visited[100] = {0}; 

    struct node* temp = list1;
    while (temp != NULL) {
        if (!visited[temp->data]) {
            noCommon = insert(noCommon, temp->data);
            visited[temp->data] = 1;
        }
        temp = temp->link;
    }

    temp = list2;
    while (temp != NULL) {
        if (!visited[temp->data]) {
            noCommon = insert(noCommon, temp->data);
            visited[temp->data] = 1;
        }
        temp = temp->link;
    }

    return noCommon;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    struct node* removeCommon = NULL;

    list1 = insert(list1, 10);
    list1 = insert(list1, 10);
    list1 = insert(list1, 10);
    list1 = insert(list1, 10);
    list1 = insert(list1, 10);

    list2 = insert(list2, 5);
    list2 = insert(list2, 4);
    list2 = insert(list2, 3);
    list2 = insert(list2, 2);
    list2 = insert(list2, 1);
    list2 = insert(list2, 10);

    display(list1);
    display(list2);

    removeCommon = removeDuplicate(list1, list2);
    display(removeCommon);

    return 0;
}
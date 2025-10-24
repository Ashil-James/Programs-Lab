#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a linked list node
struct node {
    char data[100];
    struct node* next;
};

// Function to create a new node
struct node* createNode(char* data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
struct node* insertNode(struct node* head, char* data) {
    struct node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }
}

// Function to sort the linked list in ascending order
void sortList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        struct node* nextNode = temp->next;
        while (nextNode != NULL) {
            if (strcmp(temp->data, nextNode->data) > 0) {
                char tempData[100];
                strcpy(tempData, temp->data);
                strcpy(temp->data, nextNode->data);
                strcpy(nextNode->data, tempData);
            }
            nextNode = nextNode->next;
        }
        temp = temp->next;
    }
}

// Function to print the linked list
void printList(struct node* head) {
    while (head != NULL) {
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node* head = NULL;
    head = insertNode(head, "Date");
    head = insertNode(head, "Cherry");
    head = insertNode(head, "Banana");
    head = insertNode(head, "Apple");

    printf("Before sorting: ");
    printList(head);

    sortList(head);

    printf("After sorting: ");
    printList(head);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the singly linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list and return the new head
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

// Function to display the list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to perform bubble sort on the list using a for loop
void bubbleSort(struct Node* head) {
    if (head == NULL) return;
    
    struct Node *ptr1, *ptr2;
    int temp;
    
    // Perform bubble sort using for loops
    for (ptr1 = head; ptr1 != NULL; ptr1 = ptr1->next) {
        for (ptr2 = head; ptr2->next != NULL; ptr2 = ptr2->next) {
            struct Node* nextNode = ptr2->next;  // Save the next node to avoid direct access

            if (ptr2->data > nextNode->data) {
                // Swap the data between ptr2 and nextNode
                temp = ptr2->data;
                ptr2->data = nextNode->data;
                nextNode->data = temp;
            }
        }
    }
}

int main() {
    struct Node* head = NULL;

    // Insert some nodes
    head = insertEnd(head, 64);
    head = insertEnd(head, 25);
    head = insertEnd(head, 12);
    head = insertEnd(head, 22);
    head = insertEnd(head, 11);

    printf("Original List: ");
    display(head);

    // Perform bubble sort
    bubbleSort(head);

    printf("Sorted List: ");
    display(head);

    return 0;
}

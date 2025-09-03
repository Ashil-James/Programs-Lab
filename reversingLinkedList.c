#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
int stack[MAXSIZE];
int top = -1;

void push(int data) {
    if (top == MAXSIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        return -1;
    }
    return stack[top--];
}

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL, *newNode;

void insertBeg(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertEnd(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head != NULL) {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    } else {
        insertBeg(data);
    }
}

void reverseList() {
    struct Node* temp = head;
    while (temp != NULL) {
        push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp != NULL) { 
        temp->data = pop();
        temp = temp->next;
    }
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d<->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insertEnd(10);
    insertEnd(20);
    insertEnd(40);
    display();
    reverseList();
    display();
    return 0;
}

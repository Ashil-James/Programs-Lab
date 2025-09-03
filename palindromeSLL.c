#include <stdio.h>
#include <stdlib.h>

int stack[100];
int top = -1;

struct Node {
    int data;
    struct Node* link;
};

struct Node* head = NULL, *newNode;

void insertBeg(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->data = data;
    newNode->link = head;
    head = newNode;
}

void insertEnd(int data) {
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->link = NULL;
    newNode->data = data;
    if (head != NULL) {
        struct Node* temp = head;
        while (temp->link != NULL) {
            temp = temp->link;    
        }
        temp->link = newNode;
    } else {
        insertBeg(data);
    }
}

void display() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}

void push(int data) {
    stack[++top] = data;
}

int pop() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack[top--];
}

int isPalin() {
    struct Node* temp = head;

    while (temp != NULL) {
        push(temp->data);
        temp = temp->link;
    }

    temp = head;

    while (temp != NULL) {
        int el = pop();
        if (temp->data != el) {
            return 0;
        }
        temp = temp->link;
    }
    
    return 1;
}

int main() {
    insertEnd(1);
    insertEnd(2);
    insertEnd(3);
    insertEnd(3);
    insertEnd(1);
    display();

    int palin = isPalin();
    if (palin == 1) {
        printf("Palindrome\n");
    } else {
        printf("Not palindrome\n");
    }
    
    return 0;
}

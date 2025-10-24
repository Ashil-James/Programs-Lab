#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* insert(struct node* Node, int ele) {
    struct node* p = (struct node*)malloc(sizeof(struct node));
    p->data = ele;
    p->link = NULL;
    
    if(Node == NULL) {
        return p;
    }

    struct node* temp = Node;
    while(temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = p;

    return Node;
}

void peakElements(struct node* list) {
    if (list == NULL) return;

    struct node* prev = NULL;
    struct node* curr = list;
    struct node* next = curr->link;

    // Handle first element
    if (curr->data >= next->data) {
        printf("%d ", curr->data);
    }

    // Traverse the middle elements
    while (next != NULL) {
        prev = curr;
        curr = next;
        next = next->link;
        if(next->link==NULL&&next->data>curr->data)
        {
            printf("%d",next->data);
        }
        if(curr->data>prev->data&&curr->data>next->data)
        {
            printf("%d ",curr->data);
        }
    }

    // Handle last element
    if (curr != NULL && prev->data <= curr->data) {
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

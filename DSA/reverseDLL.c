#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

// Function to insert a node at the end of the doubly linked list
struct node* insert_end(struct node* head, int data) {
    struct node* new_node = create_node(data);
    
    if (head == NULL) {
        return new_node;  // If the list is empty, return the new node as the head
    }

    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  // Traverse to the last node
    }
    
    // Insert the new node at the end
    temp->next = new_node;
    new_node->prev = temp;
    
    return head;  // Return the unchanged head
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf("->");
        }
        temp = temp->next;
    }
    printf("\n");
}

struct node* reverse(struct node* head)
{
    struct node* last=NULL;
    struct node* curr=head;

    while(curr!=NULL){
        last=curr->prev;
        curr->prev=curr->next;
        curr->next=last;
        curr=curr->prev;
    }
    return last->prev;
}
// Main function to test the implementation
int main() {
    struct node* exp=NULL;
    struct node* rev=NULL;
    exp=insert_end(exp,5);
    exp=insert_end(exp,4);
    exp=insert_end(exp,3);
    exp=insert_end(exp,2);
    exp=insert_end(exp,1);

    display(exp);
    rev=reverse(exp);
    display(rev);
    return 0;
}

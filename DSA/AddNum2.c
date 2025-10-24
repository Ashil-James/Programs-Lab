#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct node {
    int data;
    struct node* next;
    struct node* prev;
}*result = NULL,*head1=NULL,*head2=NULL;

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

// Function to add two numbers represented by two doubly linked lists
void add_lists(struct node* head1, struct node* head2) {
    struct node *temp1 = head1, *temp2 = head2;
    int carry = 0;

    // Traverse to the end of both lists
    while (temp1->next != NULL) temp1 = temp1->next;
    while (temp2->next != NULL) temp2 = temp2->next;

    // Add digits until both lists are processed and there's no carry
    while (temp1 != NULL || temp2 != NULL || carry) {
        int sum = carry;

        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->prev;  // Move to the previous node in the first list
        }

        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->prev;  // Move to the previous node in the second list
        }

        // Calculate new carry
        carry = sum / 10;
        sum = sum % 10;  // Get the last digit of the sum

 struct node* newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=sum;
    newNode->prev=NULL;
    newNode->next=NULL;
        if(result==NULL)
        {
           newNode->next=NULL;
           result=newNode;
        }
        else{
    newNode->next=result;
    result=newNode;
    newNode->next->prev=newNode;
        }
    }
}

// Function to display the list
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

// Main function to test the implementation
int main() {
   

    // Inserting digits into the first list (representing the number 563)
    head1 = insert_end(head1, 1);
   // head1 = insert_end(head1, 8);
    //head1 = insert_end(head1, 3);

    // Inserting digits into the second list (representing the number 842)
    head2 = insert_end(head2, 9);
     head2 = insert_end(head2, 8);
    // head2 = insert_end(head2, 2);

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    // Add the two lists
    add_lists(head1, head2);

    // Display the result
    printf("Resultant List: ");
    display(result);

    return 0;
}

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

// Function to add two numbers represented by two doubly linked lists
struct node* add_lists(struct node* head1, struct node* head2) {
    struct node *temp1 = head1, *temp2 = head2;
    struct node *result = NULL;
    int carry = 0;

    while (temp1 != NULL || temp2 != NULL || carry) {
        int sum = carry;

        if (temp1 != NULL) {
            sum += temp1->data;
            temp1 = temp1->next;
        }

        if (temp2 != NULL) {
            sum += temp2->data;
            temp2 = temp2->next;
        }

        carry = sum / 10;  // Carry for the next digit
        result = insert_end(result, sum % 10);  // Insert the result digit
    }

    return result;
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

void reverseTraversal(struct node* head){
		if (head == NULL) {
			printf("List is empty.\n");
			return;
		}
		
		struct node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		while (temp != NULL) {
			printf("%d", temp->data);
			if (temp->prev != NULL) {
				printf("<->");
			}
			temp = temp->prev;
		}
		printf("\n");
	}
// Main function to test the implementation
int main() {
    struct node* head1 = NULL;
    struct node* head2 = NULL;

    // Inserting digits into the first list (representing the number 563)
    head1 = insert_end(head1, 5);
    head1 = insert_end(head1, 6);
    head1 = insert_end(head1, 3);

    // Inserting digits into the second list (representing the number 842)
    head2 = insert_end(head2, 8);
    head2 = insert_end(head2, 4);
    head2 = insert_end(head2, 2);
    return 0;
}

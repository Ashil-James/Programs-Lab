	/*
	Name:Ashil George James
	RollNo:MGP23CS037
	Program to implemenet basic operations on a doubly linked list
	*/
	#include<stdio.h>
	#include<stdlib.h>

	struct Node{
		int data;
		struct Node* prev;
		struct Node* next;
	};

	struct Node* head=NULL, *newNode,*temp;

	void insertBeg(int item){
		newNode=(struct Node*)malloc(sizeof(struct Node));
		newNode->prev=NULL;
		newNode->data=item;
		if(head==NULL)
		{
			newNode->next=NULL;
			head=newNode;
			return;
		}
		
		head->prev=newNode;
		newNode->next=head;
		head=newNode;
	}


	void insertEnd(int item){
		newNode=(struct Node*)malloc(sizeof(struct Node));
		newNode->prev=NULL;
		newNode->next=NULL;
		newNode->data=item;
		if(head==NULL){
			insertBeg(item);
			return;
		}
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=newNode;
			newNode->prev=temp;
			newNode->next=NULL;
	}

	void insertPosition(int position, int ele) {
		newNode = (struct Node*)malloc(sizeof(struct Node));
		newNode->data = ele;
		
		if (position == 1) {
			insertBeg(ele);
			return;
		}

			temp = head;
			for(int i=1;i<position-1&&temp!=NULL;i++){
				temp=temp->next;
			}
			
			if(temp == NULL){
				printf("Position exceeds the length of the list\n");
				free(newNode);
				return;
			}
			newNode->next=temp->next;
			newNode->prev=temp;
			if(temp->next!=NULL){
				temp->next->prev=newNode;
			}
			temp->next=newNode;
			
	}

	void deleteBeg(){
		if(head==NULL){
			printf("Empty List");
			return;
		}
		else{
			struct Node* temp=head;
			head=head->next;
			head->prev=NULL;
			free(temp);
			
		}
	}

	void deleteEnd(){
		if(head==NULL){
			printf("List is empty");
			return;
		}
		else{
			struct Node* temp=head;
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->prev->next=NULL;
			free(temp);
		}
	}

	void deletePosition(int position){
		if(head==NULL){
			printf("List is empty ");
			return;
		}
		struct Node* temp=head;
		if(position==1){
			deleteBeg();
			return;
		}
		
		else{
			for(int i=1;i<position && temp!=NULL;i++){
				temp=temp->next;
			}
			if(temp==NULL){
				printf("Position exceeds the length of the list");
				return;
			}
			

			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);	
		}
	}

	void traverse(){
		temp=head;
		while(temp!=NULL){
			printf("%d<->",temp->data);
			temp=temp->next;
		}
		printf("NULL\n");
	}

	void reverseTraversal(){
		if (head == NULL) {
			printf("List is empty.\n");
			return;
		}
		
		struct Node* temp = head;

		while (temp->next != NULL) {
			temp = temp->next;
		}
		printf("Doubly Linked List: ");
		while (temp != NULL) {
			printf("%d", temp->data);
			if (temp->prev != NULL) {
				printf("<->");
			}
			temp = temp->prev;
		}
		printf("\n");
	}

	void searchList(int ele){
		struct Node* temp=head;
		while(temp!=NULL)
		{
			if(temp->data==ele){
				printf("Element Found!\n");
				break;
			}
			temp=temp->next;
		}
		if(temp==NULL)
			printf("Element Not Found");
	}

	int main() {
		int choice, subchoice, data, position;

		while (1) {
			printf("\nMenu:\n");
			printf("1. Insert\n");
			printf("2. Delete\n");
			printf("3. Display List\n");
			printf("4. Search Element\n");
			printf("5. Exit\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);

			switch (choice) {
				case 1:
					printf("\nInsert Options:\n");
					printf("1. Insert at Beginning\n");
					printf("2. Insert at End\n");
					printf("3. Insert at Position\n");
					printf("Enter your subchoice: ");
					scanf("%d", &subchoice);
		
					printf("Enter the data to insert: ");
					scanf("%d", &data);

					if (subchoice == 1) {
						insertBeg(data);
					} else if (subchoice == 2) {
						insertEnd(data);
					} else if (subchoice == 3) {
						printf("Enter the position: ");
						scanf("%d", &position);
						insertPosition(position, data);
					} else {
						printf("Invalid subchoice!\n");
					}
					break;

				case 2:
					printf("\nDelete Options:\n");
					printf("1. Delete from Beginning\n");
					printf("2. Delete from End\n");
					printf("3. Delete from Position\n");
					printf("Enter your subchoice: ");
					scanf("%d", &subchoice);

					if (subchoice == 1) {
						deleteBeg();
					} else if (subchoice == 2) {
						deleteEnd();
					} else if (subchoice == 3) {
						printf("Enter the position: ");
						scanf("%d", &position);
						deletePosition(position);
					} else {
						printf("Invalid subchoice!\n");
					}
					break;

				case 3:
					printf("\nDisplay Options:\n");
					printf("1. Display in Forward Order\n");
					printf("2. Display in Reverse Order\n");
					printf("Enter your subchoice: ");
					scanf("%d", &subchoice);

					if (subchoice == 1) {
						printf("Traversing the List:\n");
						traverse();
					} else if (subchoice == 2) {
						printf("Reverse Traversal of the List:\n");
						reverseTraversal();
					} else {
						printf("Invalid subchoice!\n");
					}
					break;

				case 4:
					printf("Enter the element to search: ");
					scanf("%d", &data);
					searchList(data);
					break;

				case 5:
					exit(0);

				default:
					printf("Invalid choice! Please try again.\n");
			}
		}
		return 0;
	}

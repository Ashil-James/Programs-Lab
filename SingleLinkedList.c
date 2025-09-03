    #include<stdio.h>
    #include<stdlib.h>

    struct Node{
        int data;
        struct Node* link;
    };

    struct Node* head=NULL, *newNode;

    void insertBeg(int data){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->link=NULL;
        newNode->link=head;
        head=newNode;
    }

    void insertEnd(int data){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->data=data;
        newNode->link=NULL;
        if(head!=NULL)
        {
            struct Node*temp=head;
            while(temp->link!=NULL)
            {
                temp=temp->link;
            }
            temp->link=newNode;
            newNode->link=NULL;
        }
        else{
            insertBeg(data);
        }
    }

    void insertPosition(int data,int position)
    {
        newNode=(struct Node*)malloc(sizeof(struct Node));
        newNode->link=NULL;
        newNode->data=data;

        if(position==1){
            insertBeg(data);
            return;
        }

        struct Node* temp=head;
        for(int i=1;i<position-1&&temp!=NULL;i++)
        {
            temp=temp->link;
        }
        if(temp==NULL)
        {
            printf("Position exceeds MaxSize");
            free(newNode);
            return;
        }
        newNode->link=temp->link;
        temp->link=newNode;
    }

    void deleteBeg()
    {
        if(head==NULL)
        {
            printf("List is empty!");
            return;
        }
        struct Node* temp=head;
        head=head->link;
        free(temp);
    }


    void deleteEnd()
    {
        if(head==NULL)
        {
            printf("List is empty");
            return;
        }

        if (head->link == NULL) {  // Only one element
            free(head);
            head = NULL;
            return;
        }
        struct Node* temp=head;
        struct Node* loc=temp->link;

        while(loc->link!=NULL){
            temp=temp->link;
            loc=loc->link;
        }
        temp->link=NULL;
        free(loc);
    }

    void deletePosition(int position)
    {
        if(head==NULL){
            printf("List is Empty!\n");
            return;
        }
        if(position==1)
        {
            deleteBeg();
            return;
        }
        struct Node* temp=head;
        struct Node* loc=temp->link;

        for(int i=1;i<position-1&&loc!=NULL;i++){
            temp=temp->link;
            loc=loc->link;
        }
        if(loc==NULL){  
            printf("Size Exceeds Max Size!\n");
            return;
        }
        temp->link=loc->link;
        free(loc);
    }
    void traverse(){
        struct Node* temp=head;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("NULL\n");
    }

int main() {
    int choice;
    int data;
    int position;
    int search;
    
    printf("Enter your choice\n");
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at a specified position\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Delete from a specified position\n");
        printf("7. Display list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertBeg(data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &position);
                insertPosition(data, position);
                break;
            case 4:
                deleteBeg();
                break;
            case 5:
                deleteEnd();
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deletePosition(position);
                break;
            case 7:
                printf("Linked List:\n");
                traverse();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

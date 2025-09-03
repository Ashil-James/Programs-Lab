#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

struct node* createNode(int value)
{
    struct node* newNode=malloc(sizeof(struct node));
    newNode->data=value;
    newNode->leftChild=NULL;
    newNode->rightChild=NULL;
    return newNode;
}

struct node* insertLeftChild(struct node* root,int value)
{
    root->leftChild=createNode(value);
    return root->leftChild;
}

struct node* insertRightChild(struct node* root,int value)
{
    root->rightChild=createNode(value);
    return root->rightChild;
}

void inorderTraversal(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    inorderTraversal(root->leftChild);
    printf("%d ",root->data);
    inorderTraversal(root->rightChild);
}

void preorderTraversal(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    printf("%d ",root->data);
    preorderTraversal(root->leftChild);
    preorderTraversal(root->rightChild);
}

void postorderTraversal(struct node* root)
{
    if(root==NULL)
    {
        return;
    }
    postorderTraversal(root->leftChild);
    postorderTraversal(root->rightChild);
    printf("%d ",root->data);
}

struct node* searchKey(struct node* root, int key)
{
    if(root==NULL||root->data==key)
    {
        return root;
    }

    if(root->data<key){
        return searchKey(root->rightChild,key);
    }

    else{
        return searchKey(root->leftChild,key);
    }
}


int main()
{
    int key;
    struct node* root = createNode(50);
    root->leftChild = createNode(30);
    root->rightChild = createNode(70);
    root->leftChild->leftChild = createNode(20);
    root->leftChild->rightChild = createNode(40);
    root->rightChild->leftChild = createNode(60);
    root->rightChild->rightChild = createNode(80);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);

  printf("\n");
  printf("Enter the key: ");
  scanf("%d",&key);

  if(searchKey(root,key)!=NULL)
  {
    printf("%d Was Found!",key);
  }
  else{
    printf("%d Was Not Found!",key);
  }
}
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Function to count the leaf nodes in a binary tree
int countLeaves(struct Node* root) {
    // If root is NULL, return 0
    if (root == NULL) {
        return 0;
    }
    // If the node has no left or right child, 
    // it is a leaf
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    // Recursively count the leaves in the left 
    // and right subtrees
    return countLeaves(root->left) + countLeaves(root->right);
}

struct Node* createNode(int val) {
    struct Node* node 
      = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("%d\n", countLeaves(root));

    return 0;
}
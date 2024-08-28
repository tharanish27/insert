#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int data;              
    struct TreeNode* left;  
    struct TreeNode* right; 
} TreeNode;


TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode)); 
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1); // Exit if memory allocation fails
    }
    newNode->data = value; 
    newNode->left = NULL; 
    newNode->right = NULL; 
    return newNode;
}


TreeNode* insertNode(TreeNode* root, int value) {
    if (root == NULL) {
        
        return createNode(value);
    }

   
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    }
    
    else {
        root->right = insertNode(root->right, value);
    }

    return root;
}


void printTree(TreeNode* root) {
    if (root != NULL) {
        printTree(root->left); // Traverse left subtree
        printf("%d ", root->data); // Print node data
        printTree(root->right); // Traverse right subtree
    }
}


void freeTree(TreeNode* root) {
    if (root != NULL) {
        freeTree(root->left);  
        freeTree(root->right); 
        free(root);            
    }
}

int main() {
    // Create a binary search tree
    TreeNode* root = NULL;
    root = insertNode(root, 10);
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 3);
    root = insertNode(root, 7);
    root = insertNode(root, 12);
    root = insertNode(root, 18);

    printf("In-order traversal of the binary search tree:\n");
    printTree(root);
    printf("\n");

    
    freeTree(root);

    return 0;
}

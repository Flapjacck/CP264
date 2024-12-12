#include <stdio.h>
#include <stdlib.h>

// Define the structure of a tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Helper function to calculate the height of a tree
int height(TreeNode* node) {
    if (node == NULL)
        return 0; // Height of an empty tree is 0
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to check if a tree is height-balanced
int isBalanced(TreeNode* node) {
    if (node == NULL)
        return 1; // An empty tree is balanced

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    // Check the height difference
    if (abs(leftHeight - rightHeight) > 1)
        return 0; // Tree is not balanced

    // Recursively check left and right subtrees
    return isBalanced(node->left) && isBalanced(node->right);
}

// Function to check if a BST is an AVL tree
int isAVL(TreeNode* root) {
    return isBalanced(root);
}

// Helper function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main() {
    // Create a sample tree
    TreeNode* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(2);
    root->left->right = createNode(7);

    // Test the isAVL function
    if (isAVL(root)) {
        printf("The tree is an AVL tree.\n");
    } else {
        printf("The tree is not an AVL tree.\n");
    }

    return 0;
}
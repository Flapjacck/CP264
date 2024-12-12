#include <stdio.h>
#include <stdlib.h>

// Define the structure of a binary tree node
typedef struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new tree node
TreeNode* createNode(int value) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the height of the tree
int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to perform Breadth-First Search (BFS) or level-order traversal
void bfsTraversal(TreeNode* root) {
    if (root == NULL) {
        printf("The tree is empty.\n");
        return;
    }

    int h = height(root);
    for (int i = 1; i <= h; i++) {
        printLevel(root, i);
        printf("\n");
    }
}

// Helper function to print a specific level
void printLevel(TreeNode* root, int level) {
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->value);
    else if (level > 1) {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

// Function to count the total number of nodes in the tree
int countNodes(TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Function to count the number of leaf nodes in the tree
int countLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Example usage
int main() {
    // Create a sample binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("BFS Traversal (Level-Order):\n");
    bfsTraversal(root);

    int totalNodes = countNodes(root);
    printf("\nTotal Number of Nodes: %d\n", totalNodes);

    int treeHeight = height(root);
    printf("Height of the Tree: %d\n", treeHeight);

    int totalLeaves = countLeaves(root);
    printf("Number of Leaves: %d\n", totalLeaves);

    return 0;
}
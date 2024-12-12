#include <stdio.h>
#include <stdlib.h>

// Define the structure of an AVL tree node
typedef struct AVLNode {
    int value;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

// Function to create a new AVL tree node
AVLNode* createNode(int value) {
    AVLNode* newNode = (AVLNode*)malloc(sizeof(AVLNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1; // New node height is initialized as 1
    return newNode;
}

// Function to get the height of a node
int getHeight(AVLNode* node) {
    return (node == NULL) ? 0 : node->height;
}

// Function to calculate the balance factor of a node
int getBalance(AVLNode* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
}

// Helper function to update the height of a node
void updateHeight(AVLNode* node) {
    if (node != NULL) {
        node->height = 1 + (getHeight(node->left) > getHeight(node->right)
                                ? getHeight(node->left)
                                : getHeight(node->right));
    }
}

// Function to perform a right rotation
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x; // New root after rotation
}

// Function to perform a left rotation
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y; // New root after rotation
}

// Function to insert a value into the AVL tree
AVLNode* insert(AVLNode* root, int value) {
    // Perform standard BST insertion
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    } else {
        // Duplicate values are not allowed in AVL tree
        return root;
    }

    // Update the height of the current node
    updateHeight(root);

    // Calculate the balance factor
    int balance = getBalance(root);

    // Perform rotations to maintain AVL property

    // Left Left Case
    if (balance > 1 && value < root->left->value) {
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && value > root->right->value) {
        return leftRotate(root);
    }

    // Left Right Case
    if (balance > 1 && value > root->left->value) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && value < root->right->value) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root; // Return the unchanged node if no rotation is needed
}

// Function to perform an in-order traversal (to display the tree)
void inOrderTraversal(AVLNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->value);
        inOrderTraversal(root->right);
    }
}

// Example usage
int main() {
    AVLNode* root = NULL;

    // Insert elements into the AVL tree
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // Print the in-order traversal of the AVL tree
    printf("In-order traversal of the AVL tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
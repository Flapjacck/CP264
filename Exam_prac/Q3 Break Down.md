# Question 3 Break Down (AVL's)

## Right Rotation

- The right rotation is used to balance the AVL tree when the balance factor of a node is greater than 1.
- The right rotation is performed on a node `y` with a left child `x`.
- The right rotation is performed by making `x` the new root of the subtree and `y` its right child.
- The right child of `x` becomes the left child of `y`.
- The heights of `x` and `y` are updated after the rotation.
- Uses the helper function `updateHeight` to update the height of a node.

```c
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
```

## Insertion

- The insertion operation in an AVL tree is similar to that of a binary search tree (BST).
- After inserting a node, the heights of the nodes on the path from the root to the inserted node are updated.
- The balance factor of each node is calculated to determine if any rotations are needed to maintain the AVL property.
- Four cases of imbalance may occur during insertion:
    1. Left Left Case
    2. Right Right Case
    3. Left Right Case
    4. Right Left Case
- The appropriate rotation(s) are performed to balance the tree after insertion.
- Duplicate values are not allowed in an AVL tree.

```c
// Function to calculate the balance factor of a node
int getBalance(AVLNode* node) {
    return (node == NULL) ? 0 : getHeight(node->left) - getHeight(node->right);
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
```

## Main File

```c
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
```
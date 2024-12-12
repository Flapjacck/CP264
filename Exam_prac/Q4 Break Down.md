# Question 4 Break Down

## Determine if a BST is a AVL tree

- To determine if a BST is an AVL tree, we need to check if the tree is height-balanced.
- A tree is height-balanced if the height difference between the left and right subtrees of every node is at most 1.
- We can use a helper function to calculate the height of a tree and another function to check if the tree is height-balanced.
- The helper function will calculate the height of a tree recursively.
- The function to check if a tree is height-balanced will return 1 if the tree is balanced and 0 otherwise.

```c
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
```

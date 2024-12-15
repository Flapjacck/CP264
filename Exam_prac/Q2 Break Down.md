# Question 2 Break Down (BST's)

## Traversal using Breadth-First Search (BFS)

- The BFS traversal of a tree is also known as the level-order traversal.
- In this traversal, we visit all the nodes at a given level before moving on to the next level.
- We start at the root node and visit all the nodes at level 1, then all the nodes at level 2, and so on.

```c
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
```

## Number of Nodes in a Binary Search Tree

- The number of nodes in a binary search tree can be calculated using a recursive approach.
- The total number of nodes in a tree is equal to 1 (for the root node) plus the number of nodes in the left subtree plus the number of nodes in the right subtree.

```c
// Function to count the total number of nodes in the tree
int countNodes(TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
```

## Height of a Binary Search Tree

- The height of a binary search tree is the maximum depth of the tree, i.e., the length of the longest path from the root node to a leaf node.
- The height of a tree can be calculated recursively by finding the height of the left subtree and the height of the right subtree, and then taking the maximum of the two heights and adding 1 (for the root node).
- The height of an empty tree is considered to be 0.

```c
// Function to calculate the height of the tree
int height(TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}
```

## Number of Leaves in a Binary Search Tree

- The number of leaf nodes in a binary search tree can be calculated using a recursive approach.
- A leaf node is a node that has no children (i.e., both the left and right child pointers are NULL).

```c
// Function to count the number of leaf nodes in the tree
int countLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}
```

## Main File

```c
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
```
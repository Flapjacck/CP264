/**
 * -------------------------------------
 * @file  bst_linked.c
 * Linked BST Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-03-01
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "bst_linked.h"

// Macro for comparing node heights
#define MAX_HEIGHT(a,b) ((a) > (b) ? a : b)

//--------------------------------------------------------------------
// Local Static Helper Functions

/**
 * Initializes a new BST node with a copy of item.
 *
 * @param source - pointer to a BST source
 * @param item - pointer to the item to assign to the node
 * @return a pointer to a new BST node
 */
static bst_node* bst_node_initialize(const data_ptr item) {
	// Base case: add a new node containing a copy of item.
	bst_node *node = malloc(sizeof *node);
	node->item = malloc(sizeof *node->item);
	data_copy(node->item, item);
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/**
 * Helper function to determine the height of node - handles empty node.
 * @param node - The node to process.
 * @return The height of the current node.
 */
static int bst_node_height(const bst_node *node) {
	int height = 0;

	if (node != NULL) {
		height = node->height;
	}
	return height;
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node The node to process.
 */
static void bst_update_height(bst_node *node) {
	int left_height = bst_node_height(node->left);
	int right_height = bst_node_height(node->right);

	node->height = MAX_HEIGHT(left_height, right_height) + 1;
	return;
}

/**
 * Inserts item into a BST. Insertion must preserve the BST definition.
 * item may appear only once in source.
 *
 * @param source - pointer to a BST
 * @param node - pointer to a node
 * @param item - the item to insert
 * @return - TRUE if item inserted, FALSE otherwise
 */
static BOOLEAN bst_insert_aux(bst_linked *source, bst_node **node,
		const data_ptr item) {
	BOOLEAN inserted = FALSE;

	if (*node == NULL) {
		// Base case: add a new node containing the item.
		*node = bst_node_initialize(item);
		source->count += 1;
		inserted = TRUE;
	} else {
		// Compare the node data_ptr against the new item.
		int comp = data_compare(item, (*node)->item);

		if (comp < 0) {
			// General case: check the left subsource.
			inserted = bst_insert_aux(source, &(*node)->left, item);
		} else if (comp > 0) {
			// General case: check the right subsource.
			inserted = bst_insert_aux(source, &(*node)->right, item);
		}
	}
	if (inserted) {
		// Update the node height if any of its children have been changed.
		bst_update_height(*node);
	}
	return inserted;
}

//--------------------------------------------------------------------
// Functions

// Initializes a BST.
bst_linked* bst_initialize() {
	bst_linked *source = malloc(sizeof *source);
	source->root = NULL;
	source->count = 0;
	return source;
}

// frees a BST.
void bst_free(bst_linked **source) {

	// your code here
	if (source != NULL && *source != NULL) {
		// Helper function to free nodes recursively
		void free_nodes(bst_node *node) {
			if (node != NULL) {
				free_nodes(node->left);
				free_nodes(node->right);
				data_free(&node->item);
				free(node);
			}
		}
		// Free all nodes starting from the root
		free_nodes((*source)->root);
		// Free the BST structure itself
		free(*source);
		*source = NULL;
	}
}

// Determines if a BST is empty.
BOOLEAN bst_empty(const bst_linked *source) {

	// your code here

	return source->count == 0;
}

// Determines if a BST is full.
BOOLEAN bst_full(const bst_linked *source) {
	return FALSE; // A linked BST is never full
}

// Returns number of items in a BST.
int bst_count(const bst_linked *source) {

	// your code here

	return source->count;
}

// Copies the contents of a BST to an array in inorder.
void bst_inorder(const bst_linked *source, data_ptr *items) {

	// your code here
	int index = 0; // Initialize index to track the position in the items array

	// Helper function to perform inorder traversal
	void inorder_aux(bst_node *node) {
		if (node == NULL) {
			// Base case: if the node is NULL, return
			return;
		}
		// Recursively traverse the left subtree
		inorder_aux(node->left);
		// Copy the current node's item to the array and increment the index
		items[index++] = node->item;
		// Recursively traverse the right subtree
		inorder_aux(node->right);
	}

	// Start the traversal from the root
	if (source != NULL && source->root != NULL) {
		// Perform inorder traversal starting from the root
		inorder_aux(source->root);
	}

}

// Copies the contents of a BST to an array in preorder.
void bst_preorder(const bst_linked *source, data_ptr *items) {

	// your code here
	int index = 0; // Initialize index to track the position in the items array

	// Helper function to perform preorder traversal
	void preorder_aux(bst_node *node) {
		if (node == NULL) {
			// Base case: if the node is NULL, return
			return;
		}
		// Copy the current node's item to the array and increment the index
		items[index++] = node->item;
		// Recursively traverse the left subtree
		preorder_aux(node->left);
		// Recursively traverse the right subtree
		preorder_aux(node->right);
	}

	// Start the traversal from the root
	if (source != NULL && source->root != NULL) {
		// Perform preorder traversal starting from the root
		preorder_aux(source->root);
	}
}

// Copies the contents of a BST to an array in postorder.
void bst_postorder(const bst_linked *source, data_ptr *items) {

	// your code here
	int index = 0; // Initialize index to track the position in the items array

	// Helper function to perform postorder traversal
	void postorder_aux(bst_node *node) {
		if (node == NULL) {
			// Base case: if the node is NULL, return
			return;
		}
		// Recursively traverse the left subtree
		postorder_aux(node->left);
		// Recursively traverse the right subtree
		postorder_aux(node->right);
		// Copy the current node's item to the array and increment the index
		items[index++] = node->item;
	}

	// Start the traversal from the root
	if (source != NULL && source->root != NULL) {
		// Perform postorder traversal starting from the root
		postorder_aux(source->root);
	}
}

// Inserts a copy of an item into a BST.
BOOLEAN bst_insert(bst_linked *source, const data_ptr item) {
	return bst_insert_aux(source, &(source->root), item);
}

// Retrieves a copy of a value matching key in a BST.
BOOLEAN bst_retrieve(bst_linked *source, const data_ptr key, data_ptr item) {

	// your code here
	// Helper function to find a node
	bst_node* find_node(bst_node *node, const data_ptr key) {
		if (node == NULL) {
			return NULL;
		} else if (data_compare(key, node->item) < 0) {
			return find_node(node->left, key);
		} else if (data_compare(key, node->item) > 0) {
			return find_node(node->right, key);
		} else {
			return node;
		}
	}

	if (source != NULL) {
		bst_node *node = find_node(source->root, key);
		if (node != NULL) {
			data_copy(item, node->item);
			return TRUE;
		}
	}
	return FALSE;

}

// Removes a value matching key in a BST.
BOOLEAN bst_remove(bst_linked *source, const data_ptr key, data_ptr item) {

	// your code here
	BOOLEAN removed = FALSE;
	// Check if the source tree is not NULL.
	if (source != NULL) {
		bst_node **node = &(source->root);
		// Iterate through the tree nodes.
		while (*node != NULL) {
			// Compare the key with the current node's item.
			int comp = data_compare(key, (*node)->item);
			if (comp < 0) {
				// If the key is less than the current node's item, move to the left subtree.
				node = &((*node)->left);
			} else if (comp > 0) {
				// If the key is greater than the current node's item, move to the right subtree.
				node = &((*node)->right);
			} else {
				// Key matches the current node's item, set removed to TRUE and copy the item to the output parameter.
				removed = TRUE;
				data_copy(item, (*node)->item);
				if ((*node)->left == NULL) {
					// Node with only right child or no child.
					bst_node *right = (*node)->right;
					data_free(&((*node)->item));
					free(*node);
					*node = right;
				} else if ((*node)->right == NULL) {
					// Node with only left child.
					bst_node *left = (*node)->left;
					data_free(&((*node)->item));
					free(*node);
					*node = left;
				} else {
					// Node with two children: find the inorder successor (smallest in the right subtree).
					bst_node **min_node = &((*node)->right);
					while ((*min_node)->left != NULL) {
						min_node = &((*min_node)->left);
					}
					// Copy the inorder successor's item to the current node and remove the inorder successor.
					data_copy((*node)->item, (*min_node)->item);
					bst_node *right = (*min_node)->right;
					data_free(&((*min_node)->item));
					free(*min_node);
					*min_node = right;
				}
				break;
			}
		}
		// If a node was removed, decrement the count.
		if (removed) {
			source->count -= 1;
		}
	}
	// Return whether a node was removed.
	return removed;
}

// Aux function to recursively copy a binary search tree node.
static bst_node* bst_copy_aux(const bst_node *node) {
	// Base case: if the node is NULL, return NULL.
	if (node == NULL) {
		return NULL;
	}
	// Allocate memory for the new node.
	bst_node *new_node = malloc(sizeof *new_node);
	// Allocate memory for the new node's item and copy the item from the original node.
	new_node->item = malloc(sizeof *new_node->item);
	data_copy(new_node->item, node->item);
	// Copy the height from the original node.
	new_node->height = node->height;
	// Recursively copy the left and right subtrees.
	new_node->left = bst_copy_aux(node->left);
	new_node->right = bst_copy_aux(node->right);
	// Return the new node.
	return new_node;
}

// Copies source to target.
void bst_copy(bst_linked **target, const bst_linked *source) {

	// your code here
	// If the source tree is not NULL, initialize the target tree.
	if (source != NULL) {
		*target = bst_initialize();
		// Copy the count of nodes from the source tree.
		(*target)->count = source->count;
		// Copy the root node and its subtrees using the helper function.
		(*target)->root = bst_copy_aux(source->root);
	}
}

// Finds the maximum item in a BST.
BOOLEAN bst_max(const bst_linked *source, data_ptr item) {

	// your code here
	if (source->root == NULL) {
		return FALSE;
	}

	// Traverse to the rightmost node.
	bst_node *current = source->root;
	while (current->right != NULL) {
		current = current->right;
	}

	data_copy(item, current->item);
	return TRUE;
}

// Finds the minimum item in a BST.
BOOLEAN bst_min(const bst_linked *source, data_ptr item) {

	// your code here
	if (source->root == NULL) {
		return FALSE;
	}

	// Traverse to the leftmost node.
	bst_node *current = source->root;
	while (current->left != NULL) {
		current = current->left;
	}

	data_copy(item, current->item);
	return TRUE;
}

// Finds the number of leaf nodes in a tree.
int bst_leaf_count(const bst_linked *source) {

	// your code here
	// Helper function to count leaf nodes
	int count_leaves(bst_node *node) {
		if (node == NULL) {
			return 0;
		} else if (node->left == NULL && node->right == NULL) {
			return 1;
		} else {
			return count_leaves(node->left) + count_leaves(node->right);
		}
	}

	// Return the count of leaf nodes in the tree by starting from the root
	return (source != NULL) ? count_leaves(source->root) : 0;
}

// Finds the number of nodes with one child in a tree.
int bst_one_child_count(const bst_linked *source) {

	// your code here
	int count = 0;
	// Check if the source tree is not NULL.
	if (source != NULL) {
		bst_node *node = source->root;
		// Iterate through the tree nodes.
		while (node != NULL) {
			// If the node has exactly one child, increment the count.
			if ((node->left == NULL && node->right != NULL)
					|| (node->left != NULL && node->right == NULL)) {
				count++;
			}
			// Move to the left or right child if they exist, otherwise break the loop.
			if (node->left != NULL) {
				node = node->left;
			} else if (node->right != NULL) {
				node = node->right;
			} else {
				break;
			}
		}
	}
	// Return the count of nodes with one child.
	return count;
}

// Finds the number of nodes with two children in a tree.
int bst_two_child_count(const bst_linked *source) {

	// your code here
	int count = 0;
	// Check if the source tree is not NULL.
	if (source != NULL) {
		bst_node *node = source->root;
		// Iterate through the tree nodes.
		while (node != NULL) {
			// If the node has two children, increment the count.
			if (node->left != NULL && node->right != NULL) {
				count++;
			}
			// Move to the left or right child if they exist, otherwise break the loop.
			if (node->left != NULL) {
				node = node->left;
			} else if (node->right != NULL) {
				node = node->right;
			} else {
				break;
			}
		}
	}
	// Return the count of nodes with two children.
	return count;
}

// Determines the number of nodes with zero, one, and two children.
// (May not call bst_leaf_count, bst_one_child_count, or bst_two_child_count.)
void bst_node_counts(const bst_linked *source, int *zero, int *one, int *two) {

	// your code here
	if (source != NULL) {
		// Initialize the counts for nodes with zero, one, and two children to zero.
		*zero = *one = *two = 0;
		bst_node *node = source->root;
		// Iterate through the tree nodes.
		while (node != NULL) {
			// If the node has no children, increment the zero children count.
			if (node->left == NULL && node->right == NULL) {
				(*zero)++;
				// If the node has exactly one child, increment the one child count.
			} else if ((node->left == NULL && node->right != NULL)
					|| (node->left != NULL && node->right == NULL)) {
				(*one)++;
				// If the node has two children, increment the two children count.
			} else {
				(*two)++;
			}
			// Move to the left or right child if they exist, otherwise break the loop.
			if (node->left != NULL) {
				node = node->left;
			} else if (node->right != NULL) {
				node = node->right;
			} else {
				break;
			}
		}
	}
}

// Determines whether or not a tree is a balanced tree.
BOOLEAN bst_balanced(const bst_linked *source) {

	// Helper function to check if a tree is balanced
	int check_balance(bst_node *node) {
		// Base case: If the node is NULL, the height is 0
		if (node == NULL) {
			return 0;
		}

		// Recursively check the balance of the left subtree
		int left_height = check_balance(node->left);

		// Recursively check the balance of the right subtree
		int right_height = check_balance(node->right);

		// If either subtree is unbalanced, propagate the -1 upwards
		if (left_height == -1 || right_height == -1) {
			return -1;
		}

		// If the current node is unbalanced (height difference > 1), return -1
		if (abs(left_height - right_height) > 1) {
			return -1;
		}

		// Calculate the height of the current node
		int current_height = 1
				+ (left_height > right_height ? left_height : right_height);

		// Return the height of the current node
		return current_height;
	}

	// Check if the BST is balanced by calling the helper function
	// If the helper function returns -1, the tree is unbalanced
	// If the helper function returns any non-negative value, the tree is balanced
	return (source != NULL && check_balance(source->root) != -1);
}

// Determines whether or not a tree is a valid BST.
BOOLEAN bst_valid(const bst_linked *source) {

	// your code here
	// If the source tree is NULL, it is considered valid.
	if (source == NULL) {
		return TRUE;
	}
	bst_node *node = source->root;
	data_ptr min = NULL, max = NULL;
	// Iterate through the tree nodes.
	while (node != NULL) {
		// Check if the current node's item violates the BST properties.
		if ((min != NULL && data_compare(node->item, min) <= 0)
				|| (max != NULL && data_compare(node->item, max) >= 0)) {
			return FALSE;
		}
		// Move to the left or right child and update the min or max values.
		if (node->left != NULL) {
			max = node->item;
			node = node->left;
		} else if (node->right != NULL) {
			min = node->item;
			node = node->right;
		} else {
			break;
		}
	}
	// If no violations are found, the tree is valid.
	return TRUE;
}

// Determines if two trees contain same data in same configuration.
BOOLEAN bst_equals(const bst_linked *target, const bst_linked *source) {

	// your code here
	// If either tree is NULL, they are not equal.
	if (target == NULL || source == NULL) {
		return FALSE;
	}
	bst_node *node1 = target->root;
	bst_node *node2 = source->root;
	// Iterate through the tree nodes.
	while (node1 != NULL && node2 != NULL) {
		// If the current nodes' items are not equal, return FALSE.
		if (data_compare(node1->item, node2->item) != 0) {
			return FALSE;
		}
		// Move to the left children if both nodes have left children.
		if (node1->left != NULL && node2->left != NULL) {
			node1 = node1->left;
			node2 = node2->left;
			// Move to the right children if both nodes have right children.
		} else if (node1->right != NULL && node2->right != NULL) {
			node1 = node1->right;
			node2 = node2->right;
		} else {
			// If the structure is not identical, break the loop.
			break;
		}
	}
	// Return TRUE if both nodes are NULL, indicating both trees are equal.
	return node1 == NULL && node2 == NULL;
}

/**
 * Private helper function to print contents of BS in preorder.
 *
 * @param to_string - function to print data_ptr
 * @param node - pointer to bst_node
 */
static void bst_print_aux(bst_node *node) {
	char string[DATA_STRING_SIZE];

	if (node != NULL) {
		printf("%s\n", data_string(string, DATA_STRING_SIZE, node->item));
		bst_print_aux(node->left);
		bst_print_aux(node->right);
	}
	return;
}

// Prints the items in a BST in preorder.
void bst_print(const bst_linked *source) {
	printf("  count: %d, height: %d, items:\n", source->count,
			source->root->height);
	bst_print_aux(source->root);
	printf("\n");
	return;
}

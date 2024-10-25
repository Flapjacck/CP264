/**
 * -------------------------------------
 * @file  bst_linked.h
 * Linked BST Header File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 *
 * @version 2024-03-01
 *
 * -------------------------------------
 * DO NOT CHANGE CONTENTS
 */
#ifndef BST_LINKED_H_
#define BST_LINKED_H_

// Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "data.h"

// typedefs
/**
 * BST node
 */
typedef struct BST_NODE {
    data_ptr item;           // Pointer to the node data.
    int height;              // Height of the current node.
    struct BST_NODE *left;   // Pointer to the left child.
    struct BST_NODE *right;  // Pointer to the right child.
} bst_node;

/**
 * BST header
 */
typedef struct {
    int count;               // Number of nodes in the BST.
    bst_node *root;          // Pointer to root node of the BST.
} bst_linked;

// Prototypes

/**
 * Initializes a BST.
 *
 * @return pointer to a BST
 */
bst_linked* bst_initialize();

/**
 * Frees all parts of a BST.
 *
 * @param source - pointer to a BST
 */
void bst_free(bst_linked **source);

/**
 * Determines if a BST is empty.
 *
 * @param source - pointer to a BST
 * @return TRUE if the BST is empty, FALSE otherwise
 */
BOOLEAN bst_empty(const bst_linked *source);

/**
 * Determines if a BST is full.
 *
 * @param source - pointer to a BST
 * @return - TRUE if the BST is full, FALSE otherwise
 */
BOOLEAN bst_full(const bst_linked *source);

/**
 * Returns number of items in a BST.
 *
 * @param source - pointer to a BST
 * @return - number of items in BST
 */
int bst_count(const bst_linked *source);

/**
 * Inserts a copy of an item into a BST.
 *
 * @param source - pointer to a BST Pointer to a BST.
 * @param item - pointer to the item to push
 * @return - TRUE if item inserted, FALSE otherwise
 */
BOOLEAN bst_insert(bst_linked *source, const data_ptr item);

/**
 * Retrieves a copy of a value matching key in a BST.
 *
 * @param source - pointer to a BST
 * @param key - key value to search for
 * @param item - pointer to copy of the item retrieved
 * @return - TRUE if item retrieved, FALSE otherwise (key not found)
 */
BOOLEAN bst_retrieve(bst_linked *source, const data_ptr key, data_ptr item);

/**
 * Removes a value matching key in a BST.
 *
 * @param source - pointer to a BST
 * @param key - key value to search for
 * @param item - pointer to the item removed
 * @return - TRUE if item removed, FALSE otherwise (key not found)
 */
BOOLEAN bst_remove(bst_linked *source, const data_ptr key, data_ptr item);

/**
 * Copies source to target.
 *
 * @param target - pointer to a BST
 * @param source - pointer to a BST
 */
void bst_copy(bst_linked **target, const bst_linked *source);

/**
 * Copies the contents of a BST to an array in inorder.
 *
 * @param source - pointer to a BST
 * @param items - array of items: length must be at least size of BST
 */
void bst_inorder(const bst_linked *source, data_ptr *items);

/**
 * Copies the contents of a BST to an array in preorder.
 *
 * @param source - pointer to a BST
 * @param items - array of items: length must be at least size of BST
 */
void bst_preorder(const bst_linked *source, data_ptr *items);

/**
 * Copies the contents of a tree to an array in postorder.
 *
 * @param source - pointer to a BST
 * @param items - array of items: length must be at least size of BST
 */
void bst_postorder(const bst_linked *source, data_ptr *items);

/**
 * Finds the maximum item in a BST.
 *
 * @param source - pointer to a BST
 * @param item - pointer to copy of maximum item
 * @return - TRUE if a maximum value is found, FALSE otherwise (list is empty)
 */
BOOLEAN bst_max(const bst_linked *source, data_ptr item);

/**
 * Finds the minimum item in a BST.
 *
 * @param source - pointer to a BST
 * @param item - pointer to copy of minimum item
 * @return - TRUE if a minimum value is found, FALSE otherwise (list is empty)
 */
BOOLEAN bst_min(const bst_linked *source, data_ptr item);

/**
 * Finds the number of leaf nodes in a tree.
 *
 * @param source - pointer to a BST
 * @return - count of nodes with no children.
 */
int bst_leaf_count(const bst_linked *source);

/**
 * Finds the number of nodes with one child in a tree.
 *
 * @param source - pointer to a BST
 * @return - count of nodes with one child.
 */
int bst_one_child_count(const bst_linked *source);

/**
 * Finds the number of nodes with two children in a tree.
 *
 * @param source - pointer to a BST
 * @return - count of nodes with two children
 */
int bst_two_child_count(const bst_linked *source);

/**
 * Determines the number of nodes with zero, one, and two children.
 * (May not call bst_leaf_count, bst_one_child_count, or bst_two_child_count.)
 *
 * @param source - pointer to a BST
 * @param zero - count of leaf nodes (no children)
 * @param one - count of nodes with one child
 * @param two - count of nodes with two children
 */
void bst_node_counts(const bst_linked *source, int *zero, int *one, int *two);

/**
 * Determines whether or not a tree is a balanced tree.
 * All node heights are no more than one greater than any child heights.
 *
 * @param source - pointer to a BST
 * @return - TRUE if source is balanced, FALSE otherwise
 */
BOOLEAN bst_balanced(const bst_linked *source);

/**
 * Determines whether or not a tree is a valid BST.
 *
 * @param source - pointer to a BST
 * @return - TRUE if source is valid, FALSE otherwise
 */
BOOLEAN bst_valid(const bst_linked *source);

/**
 * Determines if two trees contain same data in same configuration.
 *
 * @param target - pointer to a BST
 * @param source - pointer to a BST
 * @return - TRUE if target is identical to source, FALSE otherwise
 */
BOOLEAN bst_equals(const bst_linked *target, const bst_linked *source);

/**
 * Prints the items in a BST in preorder.
 *
 * @param source - pointer to a BST
 */
void bst_print(const bst_linked *source);

#endif /* BST_LINKED_H_ */

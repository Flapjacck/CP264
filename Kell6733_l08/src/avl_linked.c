/**
 * -------------------------------------
 * @file  avl_linked.c
 * Linked AVL Source Code File
 * -------------------------------------
 * @author David Brown, 123456789, dbrown@wlu.ca
 * @author Spencer Kelly, 169066733, kell6733@mylaurier.ca
 *
 * @version 2024-03-01
 *
 * -------------------------------------
 */
// Includes
#include <stdio.h>
#include <stdlib.h>

#include "avl_linked.h"

// Local Functions

/**
 * Initializes a new AVL node with a copy of item.
 *
 * @param source - - pointer to a AVL source
 * @param item - pointer to the item to assign to the node
 * @return a pointer to a new AVL node
 */
static avl_node* avl_node_initialize(const data_ptr item) {
    // Base case: add a new node containing a copy of item.
    avl_node *node = malloc(sizeof *node);
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
static int avl_node_height(const avl_node *node) {
    int height = 0;

    if(node != NULL) {
        height = node->height;
    }
    return (height);
}

/**
 * Updates the height of a node. Its height is the max of the heights of its
 * child nodes, plus 1.
 * @param node - The node to process.
 */
static void avl_update_height(avl_node *node) {
    int left_height = avl_node_height(node->left);
    int right_height = avl_node_height(node->right);

    if(left_height >= right_height) {
        node->height = left_height + 1;
    } else {
        node->height = right_height + 1;
    }
    return;
}

/**
 * Frees a node and its children.
 * @param node - The node to process
 */
static void avl_free_aux(avl_node **node) {

    if(*node != NULL) {
        avl_free_aux(&(*node)->left);
        avl_free_aux(&(*node)->right);
        data_free(&(*node)->item);
        (*node)->item = NULL;
        free(*node);
        *node = NULL;
    }
    return;
}

/**
 * Determines whether the AVL is balanced.
 * @param node - The node to process.
 * @return 1 if the node and its children are balanced, 0 otherwise.
 */
static int avl_balance(const avl_node *node) {
    return (avl_node_height(node->left) - avl_node_height(node->right));
}

/**
 * Performs a left rotation around node.
 * @param node - the node to process
 * @return Pointer to new root of subsource
 */
static avl_node* avl_rotate_left(avl_node *node) {

    // your code here

    return NULL;
}

/**
 * Performs a right rotation around node.
 * @param node - the node to process
 * @return Pointer to new root of subsource.
 */
static avl_node* avl_rotate_right(avl_node *node) {

    // your code here

    return NULL;
}

/**
 * Rebalances a node according to AVL rules.
 * @param node - the node to process
 */
static void avl_rebalance(avl_node **node) {

    // your code here

    return;
}

/**
 * Inserts item into a AVL. Insertion must preserve the AVL definition.
 * Only one of item may be in the source.
 * @param source Pointer to a AVL.
 * @param node - The node to process.
 * @param item The item to insert.
 * @return 1 if the item is inserted, 0 otherwise.
 */
static BOOLEAN avl_insert_aux(avl_linked *source, avl_node **node, const data_ptr item) {

    // your code here

    return FALSE;
}

/**
 * Attempts to find a item matching key in a AVL node. Deletes the node
 * if found.
 * @param source Pointer to a AVL.
 * @param node - The node to process.
 * @param key - The key to look for.
 * @param item If key is found, the item being removed.
 * @return 1 if the key is found and the item removed, 0 otherwise.
 */
static BOOLEAN avl_remove_aux(avl_linked *source, avl_node **node, const data_ptr key, data_ptr item) {

    // your code here

    return FALSE;
}

/**
 * Copies the contents of a node to an array location.
 *
 * @param source - - pointer to a AVL
 * @param node - pointer to a node
 * @param items - array of items
 * @param index - current index in array
 * @return - the updated index
 */
static int avl_inorder_aux(const avl_linked *source, data_ptr *items, const avl_node *node, int index) {

    if(node != NULL) {
        index = avl_inorder_aux(source, items, node->left, index);
        items[index] = node->item;
        index++;
        index = avl_inorder_aux(source, items, node->right, index);
    }
    return index;
}

/**
 * Copies the contents of a node to an array location.
 * @param source - Pointer to a source.
 * @param node - The node to process
 * @param items - Array of items.
 * @param index - Current index in array.
 * @return the updated index.
 */
static int avl_preorder_aux(const avl_linked *source, data_ptr *items, const avl_node *node, int index) {

    if(node != NULL) {
        items[index] = node->item;
        index++;
        index = avl_preorder_aux(source, items, node->left, index);
        index = avl_preorder_aux(source, items, node->right, index);
    }
    return index;
}

/**
 * Copies the contents of a node to an array location.
 * @param source - Pointer to a source.
 * @param node - The node to process
 * @param items - Array of items.
 * @param index - Current index in array.
 * @return the updated index.
 */
static int avl_postorder_aux(const avl_linked *source, data_ptr *items, const avl_node *node, int index) {

    if(node != NULL) {
        index = avl_postorder_aux(source, items, node->left, index);
        index = avl_postorder_aux(source, items, node->right, index);
        items[index] = node->item;
        index++;
    }
    return index;
}

/**
 * Determines if a source is a valid AVL.
 * @param node - The node to process.
 * @return 1 if the node and its children are valid, 0 otherwise.
 */
static AVL_ERROR avl_valid_aux(const avl_node *node) {
    AVL_ERROR valid = AVL_VALID; // default base case

    if(node != NULL) {
        if((node->left != NULL && data_compare(node->left->item, node->item) >= 0)
                || (node->right != NULL && data_compare(node->right->item, node->item) <= 0)) {
            // Base case: child items are incorrect
            valid = AVL_BAD_CHILDREN;
        } else if(abs(avl_node_height(node->left) - avl_node_height(node->right)) > 1) {
            // Base case: height violation - child heights not balanced
            valid = AVL_NOT_BALANCED;
        } else if(node->height < (avl_node_height(node->left) + 1)
                || node->height < (avl_node_height(node->right) + 1)) {
            // Base case: height violation - current node height incorrect
            valid = AVL_HEIGHT_VIOLATION;
        } else {
            valid = avl_valid_aux(node->left) && avl_valid_aux(node->right);
        }
    }
    return (valid);
}

/**
 * Determines if two AVL subtrees are equal.
 *
 * @param compare - item comparison function
 * @param target_node - pointer to an AVL node
 * @param source_node - pointer to an AVL node
 * @return - TRUE if subtree is equal, FALSE otherwise
 */
static BOOLEAN avl_equals_aux(const avl_node *target_node, const avl_node *source_node) {
    BOOLEAN equals = FALSE;

    if((source_node == NULL) && (target_node == NULL)) {
        // Reached a bottom of the AVL.
        equals = TRUE;
    } else if((source_node != NULL) && (target_node != NULL)
            && (data_compare(target_node->item, source_node->item) == 0)
            && (target_node->height == source_node->height)) {
        equals = avl_equals_aux(target_node->left, source_node->left)
                && avl_equals_aux(target_node->right, source_node->right);
    }
    return equals;
}

/**
 * Private helper function to print contents of an AVL in preorder.
 *
 * @param to_string - function to print data_ptr
 * @param node - pointer to avl_node
 */
static void avl_print_aux(avl_node *node) {
    char string[DATA_STRING_SIZE];

    if(node != NULL) {
        printf("%s\n", data_string(string, DATA_STRING_SIZE, node->item));
        avl_print_aux(node->left);
        avl_print_aux(node->right);
    }
    return;
}

//--------------------------------------------------------------------
// Functions

avl_linked* avl_initialize() {
    avl_linked *source = malloc(sizeof *source);
    source->root = NULL;
    source->count = 0;
    return source;
}

// frees an AVL.
void avl_free(avl_linked **source) {
    avl_free_aux(&(*source)->root);
    free(*source);
    *source = NULL;
    return;
}

BOOLEAN avl_empty(const avl_linked *source) {
    return (source->root == NULL);
}

BOOLEAN avl_full(const avl_linked *source) {
    return FALSE;
}

int avl_count(const avl_linked *source) {
    return source->count;
}

// Copies the contents of a AVL to an array in inorder.
void avl_inorder(const avl_linked *source, data_ptr *items) {
    avl_inorder_aux(source, items, source->root, 0);
    return;
}

// Copies the contents of a AVL to an array in preorder.
void avl_preorder(const avl_linked *source, data_ptr *items) {
    avl_preorder_aux(source, items, source->root, 0);
    return;
}

// Copies the contents of a AVL to an array in postorder.
void avl_postorder(const avl_linked *source, data_ptr *items) {
    avl_postorder_aux(source, items, source->root, 0);
    return;
}

BOOLEAN avl_insert(avl_linked *source, data_ptr item) {
    return (avl_insert_aux(source, &(source->root), item));
}

BOOLEAN avl_retrieve(const avl_linked *source, data_ptr key, data_ptr item) {
    BOOLEAN retrieved = FALSE;
    avl_node *node = source->root;

    while((node != NULL) && (retrieved == FALSE)) {
        int comp = data_compare(key, node->item);

        if(comp < 0) {
            node = node->left;
        } else if(comp > 0) {
            node = node->right;
        } else {
            data_copy(item, node->item);
            retrieved = TRUE;
        }
    }
    return retrieved;
}

BOOLEAN avl_remove(avl_linked *source, const data_ptr key, data_ptr item) {
    return (avl_remove_aux(source, &(source->root), key, item));
}

AVL_ERROR avl_valid(const avl_linked *source) {
    return (avl_valid_aux(source->root));
}

BOOLEAN avl_equals(const avl_linked *target, const avl_linked *source) {
    return (avl_equals_aux(target->root, source->root));
}

// Returns a string version of an AVL error.
char* avl_error_string(char *string, size_t size, AVL_ERROR error) {

    switch (error) {
        case AVL_BAD_CHILDREN:
            strncpy(string, "AVL_BAD_CHILDREN", size);
            break;
        case AVL_HEIGHT_VIOLATION:
            strncpy(string, "AVL_HEIGHT_VIOLATION", size);
            break;
        case AVL_NOT_BALANCED:
            strncpy(string, "AVL_NOT_BALANCED", size);
            break;
        default:
            strncpy(string, "AVL_VALID", size);
    }
    return string;
}

// Prints the items in a AVL in preorder.
void avl_print(const avl_linked *source) {
    printf("  count: %d, height: %d, items:\n", source->count, source->root->height);
    avl_print_aux(source->root);
    printf("\n");
    return;
}

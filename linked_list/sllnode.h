/**
 * Singly Linked List Header File
 *
 * The node values are integers
 *
 * @author Kiril Reznik (c) 2018
 */

#ifndef SLLNODE_H
#define SLLNODE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * Singly Linked List node structure
 *********************************************************/
typedef struct _sllnode
{
    int val;
    struct _sllnode *next;
}
sllnode;

/**
 * Create a node
 *********************************************************/
sllnode *sll_create(int val)
{
    // must use calloc in order to ensure this memory range is initialized with NULL
    sllnode *node = calloc(1, sizeof(sllnode));
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    return node;
}

/**
 * Insert a value into a Linked List
 *********************************************************/
sllnode *sll_insert(sllnode *list_head, int val)
{
    // create a new node
    sllnode *node = sll_create(val);
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return NULL;
    }

    // insert the new node at the beginning of the linked list
    node->next = list_head;

    // return the pointer to the new node
    return node;
}

/**
 * Search Linked List for a value
 *********************************************************/
bool sll_find(sllnode *list_head, int val)
{
    // if the current node is NULL, list exhausted, report failure
    if (list_head == NULL)
    {
        return false;
    }

    // if the current node's val field is what we're looking for, report success
    if (list_head->val == val)
    {
        return true;
    }

    // else, search the rest of the list
    return sll_find(list_head->next, val);
}

/**
 * Destory a Linked List
 *********************************************************/
void sll_destroy(sllnode *list_head)
{
    // if you've reached a null pointer, stop
    if (list_head == NULL)
    {
        return;
    }

    // destroy the rest of the list
    sll_destroy(list_head->next);

    // free the current node
    free(list_head);
}

#endif // SLLNODE_H

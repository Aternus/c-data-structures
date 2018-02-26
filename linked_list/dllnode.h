/**
 * Doubly Linked List Header File
 *
 * The node values are strings (char *)
 *
 * @author Kiril Reznik (c) 2018
 */

#ifndef DLLNODE_H
#define DLLNODE_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Doubly Linked List node structure
 *********************************************************/
typedef struct _dllnode
{
    char *val;
    struct _dllnode *next;
    struct _dllnode *prev;
}
dllnode;

/**
 * Create a node
 *********************************************************/
dllnode *dll_create(char *val)
{
    // must use calloc in order to ensure this memory range is initialized with NULL
    dllnode *node = calloc(1, sizeof(dllnode));
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return NULL;
    }
    node->val = val;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

/**
 * Insert a value into a Linked List
 *********************************************************/
dllnode *dll_insert(dllnode *list_head, char *val)
{
    // create a new node
    dllnode *node = dll_create(val);
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return NULL;
    }

    // insert the new node at the beginning of the linked list
    node->next = list_head;

    // update the previous value of the list head
    list_head->prev = node;

    // return the pointer to the new node
    return node;
}

/**
 * Search Linked List for a value
 *********************************************************/
bool dll_find(dllnode *list_head, char *val)
{
    // if the current node is NULL, list exhausted, report failure
    if (list_head == NULL)
    {
        return false;
    }

    // if the current node's val field is what we're looking for, report success
    if (strcmp(list_head->val, val) == 0)
    {
        return true;
    }

    // else, search the rest of the list
    return dll_find(list_head->next, val);
}

/**
 * Delete a Node from a Linked List
 *********************************************************/
dllnode *dll_delete(dllnode *list_head, dllnode *node)
{
    dllnode *head_node = list_head;
    dllnode *next_node = node->next;
    dllnode *prev_node = node->prev;

    // there is only one node
    if (prev_node == NULL && next_node == NULL)
    {
        head_node = NULL;
    }
    // the node is first
    else if (prev_node == NULL)
    {
        next_node->prev = NULL;
        head_node = next_node; // next node becomes the head node
    }
    // the node is last
    else if (next_node == NULL)
    {
        prev_node->next = NULL;
    }
    // the node is somewhere in the middle
    else
    {
        next_node->prev = prev_node;
        prev_node->next = next_node;
    }

    // free the current node
    free(node);

    return head_node;
}

/**
 * Destory a Linked List
 *********************************************************/
void dll_destroy(dllnode *list_head)
{
    // if you've reached a null pointer, stop
    if (list_head == NULL)
    {
        return;
    }

    // destroy the rest of the list
    dll_destroy(list_head->next);

    // free the current node
    free(list_head);
}

#endif // DLLNODE_H

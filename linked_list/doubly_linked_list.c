/**
 * Doubly Linked List
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dllnode.h"

/**
 * Main
 *********************************************************/
int main(void)
{
    // create a new linked list
    dllnode *list_head = dll_create("Hello World");

    // insert a new node into the linked list
    list_head = dll_insert(list_head, "CS50");
    dllnode *middle_node = list_head = dll_insert(list_head, "Middle");
    dllnode *first_node = list_head = dll_insert(list_head, "First");

    // delete a node from the linked list
    list_head = dll_delete(list_head, middle_node);
    list_head = dll_delete(list_head, first_node);

    // search the linked list
    printf("'First' in the list? %i\n", dll_find(list_head, "First"));

    // destroy the linked list
    dll_destroy(list_head);

    return 0;
}

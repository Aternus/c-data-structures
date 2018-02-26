/**
 * Singly Linked List
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sllnode.h"

/**
 * Main
 *********************************************************/
int main(void)
{
    // create a new linked list
    sllnode *list_head = sll_create(2);

    // insert a new node into the linked list
    list_head = sll_insert(list_head, 4);
    list_head = sll_insert(list_head, 8);
    list_head = sll_insert(list_head, 16);
    list_head = sll_insert(list_head, 32);

    // search the linked list
    printf("'32' in the list? %i\n", sll_find(list_head, 32));

    // destroy the linked list
    sll_destroy(list_head);

    return 0;
}

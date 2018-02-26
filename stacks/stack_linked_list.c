/**
 * Stack - Linked List based implementation
 *
 * Pros:
 * 1. Flexible size
 *
 * Cons:
 * 1. Harder to implement when compared to the array alternative since you need to handle memory allocation
 *
 * (!) Make sure to always maintain a pointer to the head of the linked list!
 */

#include <stdbool.h>
#include <stdio.h> // printf()
#include <stdlib.h> // calloc()
#include <limits.h> // INT_MAX

typedef struct _stack
{
    int value;
    struct _stack *next;
}
stack;

// create a stack pointers
stack *s_head = NULL;

/**
 * push
 */
bool push(int value)
{
    // dynamically allocate a new node
    stack *node = calloc(1, sizeof(stack));
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return false;
    }

    // set node's value
    node->value = value;

    // if this is not the first node in the chain
    node->next = (s_head != NULL) ? (s_head) : (NULL);

    s_head = node;
    return true;
}

/**
 * pop
 */
int pop(void)
{
    // if there haven't been a push yet
    if (s_head == NULL)
    {
        return INT_MAX;
    }

    // save the pointer to the current stack head so we can free its memory
    stack *current = s_head;

    // get node's value
    int value = current->value;

    // if there is a next node
    if (current->next != NULL)
    {
        // set the stack head to the next node
        s_head = current->next;
    }
    else
    {
        // reset the stack head
        s_head = NULL;
    }

    // free the current node
    free(current);

    // return the value
    return value;
}

/**
 * destroy stack
 */
void destroy_stack()
{
    // set traversal pointer
    stack *trav = s_head;

    // while traversal is possible
    while (trav != NULL)
    {
        // set the current node
        stack *current = trav;

        // set the traversal pointer to the next node
        trav = trav->next;

        // free the current node
        free(current);
    }
}

/**
 * Main
 *********************************************************/
int main(void)
{
    // push
    push(1);

    // pop
    printf("popped: %i\n", pop());

    // pop non-existing element
    printf("popped: %i\n", pop());

    // memory leak
    push(1337);

    // ensure there is no memory leak
    destroy_stack();

    return 0;
}

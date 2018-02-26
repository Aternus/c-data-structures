/**
 * Queue - Linked List based implementation
 *
 * Pros:
 * 1. Flexible size
 *
 * Cons:
 * 1. Harder to implement when compared to the array alternative since you need to handle memory allocation
 *
 * (!) Make sure to always maintain a pointer to the head AND the tail of the linked list!
 */

#include <stdbool.h>
#include <stdio.h> // printf()
#include <stdlib.h> // calloc()
#include <limits.h> // INT_MAX

typedef struct _queue
{
    int value;
    struct _queue *next;
    struct _queue *prev;
}
queue;

// create queue pointers
queue *q_head = NULL;
queue *q_tail = NULL;

/**
 * enqueue
 */
bool enqueue(int value)
{
    // dynamically allocate a new node
    queue *node = calloc(1, sizeof(queue));
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return false;
    }

    // set the value for new node
    node->value = value;

    // update new node pointers
    node->next = NULL;
    node->prev = q_tail;

    // if the there is a node at queue tail
    if (q_tail != NULL)
    {
        q_tail->next = node;
    }

    // set the queue head to be the new node
    if (q_head == NULL)
    {
        q_head = node;
    }

    // set the queue tail to be the new node
    q_tail = node;
    return true;
}

/**
 * dequeue
 */
int dequeue()
{
    // if there haven't been a push yet
    if (q_head == NULL && q_tail == NULL)
    {
        return INT_MAX;
    }

    // save the pointer to the current queue head so we can free its memory
    queue *current = q_head;

    // get node's value
    int value = current->value;

    // if there is a next node
    if (q_head->next)
    {
        // set queue head to the next node
        q_head = q_head->next;
        // set queue prev pointer to NULL
        q_head->prev = NULL;
        // free the current node
        free(current);
    }
    else
    {
        // free the current node
        free(current);
        // reset queue head and tail
        q_head = q_tail = NULL;
    }

    // return the value
    return value;
}

/**
 * destroy queue
 */
void destroy_queue()
{
    // set traversal pointer
    queue *trav = q_head;

    // while traversal is possible
    while (trav != NULL)
    {
        // set the current node
        queue *current = trav;

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
    // enqueue
    enqueue(1);
    enqueue(2);
    enqueue(3);

    // dequeue
    printf("dequeued: %i\n", dequeue());
    printf("dequeued: %i\n", dequeue());
    printf("dequeued: %i\n", dequeue());

    // dequeue non-existing element
    printf("dequeued: %i\n", dequeue());

    // memory leak
    enqueue(1337);

    // ensure there is no memory leak
    destroy_queue();

    return 0;
}

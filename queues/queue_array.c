/**
 * Queue - Array based implementation
 *
 * Pros:
 * 1. Easy to implement
 *
 * Cons:
 * 1. Predefined size
 */

#include <stdio.h> // printf()
#include <stdlib.h> // calloc()
#include <limits.h> // INT_MAX

#define QUEUE_SIZE 2

typedef struct _queue
{
    int array[QUEUE_SIZE];
    int front;
    int size;
}
queue;

/**
 * enqueue
 */
void enqueue(queue *q, int value)
{
    // if there is space in the queue
    if (q->size < QUEUE_SIZE)
    {
        // add the value to the end of the queue
        q->array[q->size + q->front] = value;
        // change the size of the queue
        q->size++;
    }
}

/**
 * dequeue
 */
int dequeue(queue *q)
{
    // is there anything to dequeue?
    if (q->size == 0)
    {
        return INT_MAX;
    }
    // get the value from the front of the queue
    int value = q->array[q->front];
    // change the queue front
    q->front = (q->front + 1) % QUEUE_SIZE; // wrap around the queue array
    // change the size of the queue
    q->size--;
    // return the value
    return value;
}

/**
 * Main
 *********************************************************/
int main(void)
{
    // create a queue on the heap
    queue *q = calloc(1, sizeof(queue));

    // initialize the queue
    q->front = 0;
    q->size = 0;

    // enqueue
    enqueue(q, 1);

    // dequeue
    printf("dequeued: %i\n", dequeue(q));

    // dequeue non-existing element
    printf("dequeued: %i\n", dequeue(q));

    // warp-over test
    enqueue(q, 2); // f = 1, s = 1
    printf("dequeued: %i\n", dequeue(q)); // f = 0, s = 0
    enqueue(q, 3); // f = 0, s = 1
    printf("dequeued: %i\n", dequeue(q)); // f = 1, s = 0

    // remove queue from the heap
    free(q);

    return 0;
}

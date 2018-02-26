/**
 * Stack - Array based implementation
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

#define STACK_SIZE 2

typedef struct _stack
{
    int array[STACK_SIZE];
    int top;
}
stack;

/**
 * push
 */
void push(stack *stack, int value)
{
    // if there is space in the stack
    if (stack->top < STACK_SIZE)
    {
        // add the value to the top of the stack
        stack->array[stack->top++] = value; // ++ suffix increases the value after the statement is run
    }
}

/**
 * pop
 */
int pop(stack *stack)
{
    // is there anything to pop?
    if (stack->top == 0)
    {
        return INT_MAX;
    }
    // return the value
    return stack->array[--stack->top]; // -- prefix decreases the value before the statement is run
}

/**
 * Main
 *********************************************************/
int main(void)
{
    // create a stack on the heap
    stack *s = calloc(1, sizeof(stack));

    // initialize top of the stack
    s->top = 0;

    // push
    push(s, 1);

    // pop
    printf("popped: %i\n", pop(s));

    // pop non-existing element
    printf("popped: %i\n", pop(s));

    // remove stack from the heap
    free(s);

    return 0;
}

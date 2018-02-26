# Linked Lists

So far the array has been the only kind of data structure for representing collections of like values.
`struct` gave us the ability to create "containers" for holding variables of different data types, typically.

Arrays are great for element lookup, but unless we want to insert at the very end of the array,
inserting elements is quite costly.

Arrays also suffer from a great inflexibility - you always get an exact size - if you want to resize an array
it's going to be a costly operation.

Using pointers, dynamic memory allocation and structs, we can develop a new kind of data structure
that gives us the ability to grow and shrink a collection of like values to fit our needs - the *singly-linked list*.


## Linked List Properties:

    Insertion        O(1)
    Deletion         O(1)
    Lookup           O(n)


## Singly Linked List

### Singly Linked List node structure

A struct with a field that is a self-referential data type must have a defined name.
The alias of the struct is available only after the full declaration.

(!) In a struct that is not self-referential, you can omit the struct name altogether.

```c
typedef struct _sllnode
{
    int val; // data of some data type (int, char, float...)
    struct _sllnode *next; // a pointer to another node of the same type
}
sllnode;
```

## Doubly Linked List

Singly-linked lists suffer from a crucial limitation: we can only ever move in one direction through the list;
which makes things like deleting a node or inserting a node in the middle of a list a complicated procedure.

A doubly-linked list allows us to move forward and backward through the list.

### Doubly Linked List node structure

```c
typedef struct _dllnode
{
    char *val;
    struct _dllnode *next;
    struct _dllnode *prev;
}
dllnode;
```

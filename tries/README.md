# Tries

We have seen a few data structures that handle the mapping of key-value pairs:

* Arrays: the key is the element index, the value is the data at that location.
* Hash Tables: the key is the hash code of the data, the value is a linked list of data hashing to that hash code.

Tries combine structures and pointers together to store data in an interesting way.


## Trie Properties:

    Insertion       O(1)
    Deletion        O(1)
    Lookup          O(1)


## How it Works?

The data to be searched for in the trie is a road-map.

* If you can follow the map from beginning to end, the data exits in the trie.
* If you can't, it doesn't.

Unlike with a hash table, there are no collisions, and no two pieces of data (unless they are identical) have the same path.


## Example

Let's map key-value pairs where the keys are four-digit years (YYYY) and
the values are names of universities founded during those years.

In a trie, the paths from a central *root* node to a *leaf* node (where the school names would be),
would be labeled with digits of the year.

Each node on the path from the root to leaf could have 10 pointers emanating from it, one for each digit.

To insert an element into the trie, simply build the correct path from the root to the leaf.

```c
typedef struct _trie_node
{
    char university[20];
    struct _trie_node *paths[10];
}
trie_node;
```

To search for an element in the trie, use successive digits to navigate from the root,
if you can make it to the end without hitting a dead end (a NULL pointer), you've found it.

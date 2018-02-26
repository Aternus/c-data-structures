/**
 * Hash Table
 *
 * Using the separate chaining method to avoid collisions.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// xxHash library
#define XXH_PRIVATE_API // all functions are static, directly accessible
#include "xxHash/xxhash.h"

// dllnode library
#include "../linked_list/dllnode.h"

/**
 * Hash Table Array (Global Variable)
 *********************************************************/
dllnode *hash_table[10] = {};
#define HASH_MAX 9

/**
 * Hash Table Hash Function (Global Function)
 *
 * @see https://github.com/Cyan4973/xxHash
 *********************************************************/
unsigned int get_hash(char *key)
{
    return XXH64(key, strlen(key), 0) % HASH_MAX;
}

/**
 * Is Set Hash?
 *********************************************************/
bool isset_hash(int hash)
{
    return (hash_table[hash] != NULL) ? (true) : (false);
}

/**
 * Set Node at Hash
 *********************************************************/
void set_node_at_hash(int hash, dllnode *node)
{
    hash_table[hash] = node;
}

/**
 * Get Node at Hash
 *********************************************************/
dllnode *get_node_at_hash(int hash)
{
    return hash_table[hash];
}

/**
 * Insert
 *********************************************************/
bool ht_insert(char *value)
{
    // get the hash code for the value
    int hash = get_hash(value);

    // hash location is empty
    if (!isset_hash(hash))
    {
        // create a dllnode
        dllnode *node = dll_create(value);
        // create a pointer from the hash location to the dllnode
        set_node_at_hash(hash, node);
        // success
        return true;
    }

    // hash location is not empty

    // get the list head pointer
    dllnode *list_head = get_node_at_hash(hash);

    // does the value exists in the chain already?
    if (!dll_find(list_head, value))
    {
        // create a new dllnode
        dllnode *new_node = dll_create(value);
        // adjust the next pointer of the new dllnode to point to the old dllnode
        new_node->next = list_head;
        // adjust the prev pointer of the old dllnode to point to the new dllnode
        list_head->prev = new_node;
        // create a pointer from the hash location to the new dllnode
        set_node_at_hash(hash, new_node);
        // success
        return true;
    }

    // failure
    return false;
}

/**
 * Lookup
 *********************************************************/
bool ht_lookup(char *value)
{
    // get the hash code for the value
    int hash = get_hash(value);

    // hash location is not empty and the value exists in the chain
    if (isset_hash(hash) && dll_find(get_node_at_hash(hash), value))
    {
        return true;
    }

    // hash location is empty or the value doesn't exist in the chain
    return false;
}

/**
 * Delete
 *********************************************************/
bool ht_delete(char *value)
{
    // get the hash code for the value
    int hash = get_hash(value);

    // hash location is not empty, delete the node with the value from the chain
    if (isset_hash(hash))
    {
        // get the list head pointer
        dllnode *list_head = get_node_at_hash(hash);

        // current node pointer
        dllnode *node = list_head;

        // iterate over the chain nodes looking for the value
        while (node)
        {
            if (strcmp(node->val, value) == 0)
            {
                // delete the node
                if (dll_delete(list_head, node) == NULL)
                {
                    // there is no longer a chain
                    set_node_at_hash(hash, NULL);
                }
                return true;
            }
            node = node->next;
        }
    }

    // hash location is empty or the value doesn't exist in the chain
    return false;
}

/**
 * Destroy
 *********************************************************/
void ht_destroy(void)
{
    // for each element of the array
    for (int i = 0; i < HASH_MAX; i++)
    {
        // if the element is not NULL
        if (isset_hash(i))
        {
            // destroy the list
            dll_destroy(get_node_at_hash(i));
        }
    }
}

/**
 * Main
 *********************************************************/
int main(void)
{
    // insert
    printf("'CS50' inserted? %i\n", ht_insert("CS50"));

    // lookup
    printf("'CS50' in the hash table? %i\n", ht_lookup("CS50"));

    // insert, hash collision
    printf("'Hello World' inserted? %i\n", ht_insert("Hello World"));
    printf("'snushing' inserted? %i\n", ht_insert("snushing")); // collision with "Hello World"

    // lookup, hash collision
    printf("'Hello World' in the hash table? %i\n", ht_lookup("Hello World"));
    printf("'snushing' in the hash table? %i\n", ht_lookup("snushing"));

    // lookup, value is missing
    printf("'djb2' in the hash table? %i\n", ht_lookup("djb2"));

    // delete
    printf("'CS50' deleted? %i\n", ht_delete("CS50"));
    printf("'CS50' in the hash table? %i\n", ht_lookup("CS50"));

    // delete, value is missing
    printf("'CS50' deleted? %i\n", ht_delete("CS50"));

    // cleanup
    ht_destroy();

    return 0;
}

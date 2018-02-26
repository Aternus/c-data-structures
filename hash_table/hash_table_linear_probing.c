/**
 * Hash Table
 *
 * Using the linear probing method to avoid collisions.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Hash Table Array (Global Variable)
 *********************************************************/
char *hash_table[10] = {}; // make sure values are initialized to NULL
#define HASH_MAX 9 // highest index of the hash_table array

/**
 * Hash Table Hash Function (Global Function)
 *
 * (!) In production code, use a well-tested hash function :)
 *********************************************************/
unsigned int get_hash(char *key)
{
    unsigned int sum = 0;
    for (unsigned int j = 0; key[j] != '\0'; j++)
    {
        sum += key[j];
    }
    return sum % HASH_MAX;
}

/**
 * Is Set Hash?
 *********************************************************/
bool isset_hash(int hash)
{
    return (hash_table[hash] != NULL) ? (true) : (false);
}

/**
 * Get Value by Hash
 *********************************************************/
char *get_val_by_hash(int hash)
{
    return hash_table[hash];
}

/**
 * Set Value by Hash
 *********************************************************/
void set_val_by_hash(int hash, char *value)
{
    hash_table[hash] = value;
}

/**
 * Insert
 *********************************************************/
bool ht_insert(char *value)
{
    // get the hash code for the value
    int hash = get_hash(value);

    // if the hash code location is empty
    if (!isset_hash(hash))
    {
        set_val_by_hash(hash, value);
        return true;
    }

    // if the hash code location is not empty and contains the same value
    if (isset_hash(hash) && strcmp(get_val_by_hash(hash), value) == 0)
    {
        return true;
    }

    // else, there is a collision

    /**
     * linear probing
     */

    // get the next available location
    int new_hash = hash;

    for (int loops = (HASH_MAX - 1); loops > 0; loops--)
    {
        new_hash = (new_hash + 1) % HASH_MAX;
        if (!isset_hash(new_hash))
        {
            break;
        }
    }

    // locations exhausted, all locations are taken, bail out
    if (new_hash == hash)
    {
        return false;
    }

    // there is a location available, insert
    set_val_by_hash(new_hash, value);
    return true;
}

/**
 * Lookup
 *********************************************************/
bool ht_lookup(char *value)
{
    // get the hash code for the value
    int hash = get_hash(value);

    // if the hash code location is empty
    if (!isset_hash(hash))
    {
        return false;
    }

    // if the hash code location is not empty and contains the same value
    if (isset_hash(hash) && strcmp(get_val_by_hash(hash), value) == 0)
    {
        return true;
    }

    // else, is there a hash collision?

    /**
     * linear probing
     */

    // iterate over the locations searching for the value
    for (int loops = (HASH_MAX - 1); loops > 0; loops--)
    {
        hash = (hash + 1) % HASH_MAX;
        if (isset_hash(hash) && strcmp(get_val_by_hash(hash), value) == 0)
        {
            return true;
        }
    }

    // locations exhaused, the value is not in the hash table
    return false;
}

/**
 * Delete
 *********************************************************/
bool ht_delete(char *value)
{
    // get the hash code for the value
    int hash = get_hash(value);

    // if the hash code location is empty, this value is not in the hash table, nothing to delete
    if (!isset_hash(hash))
    {
        return false;
    }

    // if the hash code location is not empty and contains the same value
    if (isset_hash(hash) && strcmp(get_val_by_hash(hash), value) == 0)
    {
        set_val_by_hash(hash, NULL);
        return true;
    }

    // else, is there a hash collision?

    /**
     * linear probing
     */

    // iterate over the locations searching for the value
    for (int loops = (HASH_MAX - 1); loops > 0; loops--)
    {
        hash = (hash + 1) % HASH_MAX;
        if (isset_hash(hash) && strcmp(get_val_by_hash(hash), value) == 0)
        {
            set_val_by_hash(hash, NULL);
            return true;
        }
    }

    // locations exhaused, the value is not in the hash table
    return false;
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
    printf("'World Hello' inserted? %i\n", ht_insert("World Hello")); // collision with "Hello World"

    // lookup, hash collision
    printf("'Hello World' in the hash table? %i\n", ht_lookup("Hello World"));
    printf("'World Hello' in the hash table? %i\n", ht_lookup("World Hello"));

    // lookup, value is missing
    printf("'djb2' in the hash table? %i\n", ht_lookup("djb2"));

    // delete
    printf("'CS50' deleted? %i\n", ht_delete("CS50"));
    printf("'CS50' in the hash table? %i\n", ht_lookup("CS50"));

    // delete, value is missing
    printf("'CS50' deleted? %i\n", ht_delete("CS50"));

    return 0;
}

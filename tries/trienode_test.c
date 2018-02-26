/**
 * Trie Test File
 *
 * @author Kiril Reznik (c) 2018
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // abort(), NULL
#include <ctype.h> // isalpha(), tolower()

#include "trienode.h"

/**
 * Main
 *********************************************************/
int main(void)
{
    trienode *root = trienode_create();

    // insert
    printf("'cs' inserted? %i\n", trie_insert_word(root, "cs"));

    // lookup
    printf("'cs' in the trie? %i\n", trie_lookup_word(root, "cs"));

    // lookup, value is missing
    printf("'computer' in the trie? %i\n", trie_lookup_word(root, "computer"));

    // delete
    printf("'cs' deleted? %i\n", trie_delete_word(root, "cs"));
    printf("'cs' in the trie? %i\n", trie_lookup_word(root, "cs"));

    // delete, value is missing
    printf("'cs' deleted? %i\n", trie_delete_word(root, "cs"));

    // cleanup
    printf("'a' inserted? %i\n", trie_insert_word(root, "a"));
    printf("'ab' inserted? %i\n", trie_insert_word(root, "ab"));
    printf("'abc' inserted? %i\n", trie_insert_word(root, "abc"));
    trie_destory(root);

    return 0;
}

/**
 * Trie Header File
 *
 * (!) Header files should #include only the headers required for the function prototypes.
 *
 * @author Kiril Reznik (c) 2018
 */

#ifndef TRIENODE_H
#define TRIENODE_H

#include <stdbool.h>
#include <stdlib.h> // abort(), NULL
#include <ctype.h> // isalpha(), tolower()

/**
 * Trie node structure
 *********************************************************/
#ifndef WORD_MAX_LENGTH
#define WORD_MAX_LENGTH 45
#endif

#ifndef ALPHA_RANGE
#define ALPHA_RANGE 27 // a-z '
#endif

typedef struct _trienode
{
    bool is_word;
    struct _trienode *leafs[ALPHA_RANGE];
}
trienode;

/**
 * Helper Functions
 *********************************************************/
int get_alpha_index(char c);
trienode *get_trienode_by_word(trienode *root, char *word);

/**
 * Create a Trie node
 *
 * @return trienode A new trienode if successfully created
 *         NULL otherwise
 *********************************************************/
trienode *trienode_create(void);

/**
 * Insert a word into the Trie
 *
 * @param root  the root of the trie
 * @param *word pointer to the word string
 *              valid string chars are: a-z and apostrophes
 *
 * @return bool true if word has been successfully inserted
 *              false otherwise
 *
 * (!) don't forget to free up memory when false is returned
 *     since the trie has lost its data integrity
 *********************************************************/
bool trie_insert_word(trienode *root, char *word);

/**
 * Lookup a word in the Trie
 *
 * @param root  the root of the trie
 * @param *word pointer to the word string
 *              valid string chars are: a-z and apostrophes
 *
 * @return bool true if word is inside the trie
 *              false otherwise
 *********************************************************/
bool trie_lookup_word(trienode *root, char *word);

/**
 * Delete a word in the Trie
 *
 * @param root  the root of the trie
 * @param *word pointer to the word string
 *              valid string chars are: a-z and apostrophes
 *
 * @return bool true if word has been deleted from the trie
 *              false otherwise
 *********************************************************/
bool trie_delete_word(trienode *root, char *word);

/**
 * Destory a Trie
 *
 * @param root  the root of the trie
 *********************************************************/
void trie_destory(trienode *root);

#endif // TRIENODE_H

/**
 * Trie Implementation File
 *
 * @author Kiril Reznik (c) 2018
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> // abort(), NULL
#include <ctype.h> // isalpha(), tolower()

#include "trienode.h"

/**
 * Helper Functions
 *********************************************************/
int get_alpha_index(char c)
{
    // apostrophes
    if (c == '\'')
    {
        return ALPHA_RANGE - 1;
    }
    // lowercase letters
    return c - 'a';
}

trienode *get_trienode_by_word(trienode *root, char *word)
{
    // validation and sanitization
    char _word[WORD_MAX_LENGTH] = {};

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!(isalpha(word[i]) || word[i] == '\''))
        {
            return NULL;
        }
        _word[i] = tolower(word[i]);
    }

    // let the trav pointer be equal to the root pointer
    trienode *trav = root;

    // for each letter of the word
    for (int i = 0; _word[i] != '\0'; i++)
    {
        // get the alphabetical index
        int alpha_idx = get_alpha_index(_word[i]);

        // no leaf at the alphabetical index of trav
        if (trav->leafs[alpha_idx] == NULL)
        {
            return NULL;
        }
        else
        {
            // move the trav pointer to the next node
            trav = trav->leafs[alpha_idx];
        }
    }

    // when the for loop finishes, the trav pointer points to the last leaf
    return trav;
}

/**
 * Create a Trie node
 *********************************************************/
trienode *trienode_create(void)
{
    // must use calloc in order to ensure this memory range is initialized with NULL
    trienode *node = calloc(1, sizeof(trienode));
    if (node == NULL)
    {
        fprintf(stderr, "failed to perform %s\n", __func__);
        return NULL;
    }
    node->is_word = false;
    return node;
}

/**
 * Insert a word into the Trie
 *********************************************************/
bool trie_insert_word(trienode *root, char *word)
{
    // validation and sanitization
    char _word[WORD_MAX_LENGTH] = {};

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!(isalpha(word[i]) || word[i] == '\''))
        {
            return false;
        }
        _word[i] = tolower(word[i]);
    }

    // let the trav pointer be equal to the root pointer
    trienode *trav = root;

    // for each letter of the word
    for (int i = 0; _word[i] != '\0'; i++)
    {
        // get the alphabetical index
        int alpha_idx = get_alpha_index(_word[i]);

        // no leaf at the alphabetical index of trav
        if (trav->leafs[alpha_idx] == NULL)
        {
            // create a new node
            trienode *node = trienode_create();

            // validate successful node creation
            if (node == NULL)
            {
                // the trie has lost its data integrity
                return false;
            }

            // point the leaf to the new node
            trav->leafs[alpha_idx] = node;
            // move the trav pointer to the new node
            trav = node;
        }
        else
        {
            // move the trav pointer to the next node
            trav = trav->leafs[alpha_idx];
        }
    }

    // when the for loop finishes, the trav pointer points to the last leaf
    trav->is_word = true;

    return true;
}

/**
 * Lookup a word in the Trie
 *********************************************************/
bool trie_lookup_word(trienode *root, char *word)
{
    trienode *node = get_trienode_by_word(root, word);
    return (node != NULL) ? (node->is_word) : (false);
}

/**
 * Delete a word in the Trie
 *********************************************************/
bool trie_delete_word(trienode *root, char *word)
{
    trienode *node = get_trienode_by_word(root, word);
    if (node != NULL && node->is_word)
    {
        node->is_word = false;
        return true;
    }
    return false;
}

/**
 * Destory a Trie
 *********************************************************/
void trie_destory(trienode *root)
{
    // check each leaf of the root node
    for (int i = 0; i < ALPHA_RANGE; i++)
    {
        // if the node at leafs[index] is not null
        if (root->leafs[i] != NULL)
        {
            // destory the node
            trie_destory(root->leafs[i]);
        }
    }

    // free the root
    free(root);
}

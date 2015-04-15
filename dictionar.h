#ifndef DICTIONAR_H
#define DICTIONAR_H
/****************************************************************************
 * dictionary.h
 *
 * Declares a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

struct nod
{
    char word[LENGTH + 1];
    struct nod* next;
};
static nod* ht[702];
/**
 * Checks all replacementsof alphabets in words for existence in dictionary.
 */
string checker(string word);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word);

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary);

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void);

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void);

#endif // DICTIONAR_H

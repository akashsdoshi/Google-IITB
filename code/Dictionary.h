#ifndef DICTIONARY_H_INCLUDED
#define DICTIONARY_H_INCLUDED
/****************************************************************************
 * dictionary.c
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include "dictionar.h"
#include <ctype.h>
#include <strings.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

/**
 * Returns true if word is in dictionary else false.
 */
class SpellChecker{
public:
string checker(string word)
{
     if(!check(word.c_str()))
     {
         for(int i = word.length()-1;i >= 0;i--)
         {
             string tmp = word;
             for(int j = 'a'; j <= 'z';j++)
             {
                 tmp[i] = j;
                 if(check(tmp.c_str()))
                 return tmp;
             }
         }
         return "";
     }
     else
     return word;
}
bool check(const char* word)
{
    // TODO
    int hf = 0;
    if(strlen(word) > 1)
    {
        char tmp = tolower(word[1]);
        hf = (tolower(word[0]) - 97)*27 + (((tmp == '\'')?96:tmp) - 96);
    }
    else
    hf = ((tolower(word[0]) - 97)*27) + 1;
    nod* cursor = ht[hf];
    while(cursor != NULL)
    {
        if(strcmp(word,cursor->word) == 0)
        return true;
        cursor = cursor->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
    FILE* fp = fopen(dictionary,"r");
    if(fp == NULL)
    {
        printf("Could not open file");
        return 1;
    }
    int count = 0;
    nod* cursor = NULL;
    while(true)
    {
        nod* n = new nod();
        fscanf(fp,"%s",n->word);
        if(strncmp(n->word,"\0000",1)==0)
        {
            delete(n);
            break;
        }
        count++;
        int hf = 0;
        if(strlen(n->word) > 1)
        hf = ((n->word[0]) - 97)*27 + (((n->word[1]== '\'')?96:n->word[1]) - 96);
        else
        hf = ((n->word[0] - 97)*27) + 1;
        if(ht[hf] == NULL)
        {
            ht[hf] = n;
            cursor = ht[hf];
        }
        else
        {
            cursor->next = n;
            cursor = cursor->next;
        }
        n->next = NULL;
    }
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    int count = 0;
    nod* counter = ht[0];
    for(int i = 0; i < 702;)
    {
        if(counter-> word != NULL)
        {
            count++;
            counter = counter-> next;
        }
        else
        counter = ht[++i];
    }
    delete(counter);
    return count;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    int count = 0;
    int count1 = size();
    bool chk = true;
    nod* cursor = ht[0];
    for(int i = 0; i < 702;)
    {
        if(chk)
        cursor = ht[i];
        if(cursor != NULL)
        {
            nod* prev = cursor;
            cursor = cursor-> next;
            delete(prev);
            count++;
            chk = false;
        }
        else
        {
            i++;
            chk = true;
        }
    }
    if(count == count1)
    return true;
    else
    return false;
}

};

#endif // DICTIONARY_H_INCLUDED

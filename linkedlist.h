#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*low list representing list of words of equal length */
typedef struct word{
    char st[30]; //word
    struct word *next;
}word;

/*top list representing list of lists of words*/
typedef struct wordlist{
    int ln; //length
    word *list; //pointer to the list of words
    struct wordlist *next;
}wordlist;

/*function to read from the function and classify and insert into linked list*/
wordlist *read(const char *f);

/*function to destroy linked list and free memory*/
void destroy(wordlist *wl);

#endif // LINKEDLIST_H_INCLUDED

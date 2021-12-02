#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "checking.h"

/*function to check whether character exists inside array or not*/
bool arraysearch(char *guessed, char letter)
{
    for(int i=0; guessed[i]!='\0'; ++i) //checking one-by-one
        {
        if(letter==guessed[i])
        {
            return true;
        }
    }
    return false;
}

/*function to check whether character exists inside linked list or not*/
bool listsearch(wordlist *wl, char letter)
{
    for(int i=0; wl->list->st[i]!='\0'; ++i) //checking one-by-one
        {
        if(letter==wl->list->st[i])
        {
            return true;
        }
    }
    return false;
}

/* function to check whether user's guess is correct or not, and revealing appropriate letters if correct*/
void checking(char *hidden, wordlist *wl, char guess)
{
    for(int i=0; wl->list->st[i]!='\0'; ++i) //checking one-by-one
        {
        if(wl->list->st[i]==guess)
        {
        hidden[i]=wl->list->st[i];
        }
    }
}

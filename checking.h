#ifndef CHECKING_H_INCLUDED
#define CHECKING_H_INCLUDED

/*function to check whether character exists inside array or not*/
bool arraysearch(char *guessed, char letter);

/*function to check whether character exists inside linked list or not*/
bool listsearch(wordlist *wl, char letter);

/* function to check whether user's guess is correct or not, and revealing appropriate letters if correct*/
void checking(char *hidden, wordlist *wl, char guess);

#endif // CHECKING_H_INCLUDED

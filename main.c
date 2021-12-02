#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "checking.h"

/*main game function, which generates random word of given length, and then checks user's guesses until finished*/
int hangman(wordlist *wl, int n, char *hidden, int difficulty, char *guessed)
{
    int mistakes=0;
    int g=0;
    char guess;
    while(wl->ln!=n){ //checking until finding list of words of appropriate length
        wl=wl->next;
    }

    /*generating word*/
    srand(time(NULL));
    int random=rand()%300;
    for(int i=0; wl->list->next!=NULL && i<random; ++i)
    {
    wl->list=wl->list->next;
    }

    /*checking part*/
    while(mistakes<difficulty){

        printf(" \nFIND THIS WORD:\n     %s    \n", hidden);
        if(arraysearch(hidden, '_')==false)
        {
        printf("\nCONGRATULATIONS, YOU WIN!\n");
            return 0;
        }
        printf("please, enter letter:\n");
        scanf(" %c",&guess);
        while(arraysearch(guessed, guess)==true)
        {
            printf("\nthe letter has already been guessed, please enter again\n");
            scanf(" %c", &guess);
        }
        guessed[g]=guess;
        ++g;
        guessed[g]='\0';
        if(listsearch(wl, guess))
        {
        checking(hidden, wl, guess);
        }
        else
        {
        printf("this letter is not found in word, try again!\n");
        ++mistakes;
        }
        printf("all guessed letters:\n");
        /*printing guessed letters*/
        for(int j=0; guessed[j]!='\0'; ++j)
        {
        printf("%c\n", guessed[j]);
        }
    }
    printf("\nHIDDEN WORD IS: %s\n", wl->list->st);
    return 0;
}

int main()
{
    /*declearing variables*/
    int length;       //length of word
    int difficulty=10; //number of misses
    int choice; //to be used in switch case
    wordlist *w=read("words.txt"); //creating linked list of linked list
    wordlist *w_save=w;
    /*initializing*/
    printf(" Welcome to the hangman game\n enter 1: start the game\n enter 2:change difficulty (default is 10)\n enter 0: exit game\n ");
    scanf("%d", &choice);

    /*switch will serves as a menu*/
    switch(choice)
    {
        /*case 2 choosing difficulty*/
        case 2:
            while(1)
                {
                printf("please enter difficulty(7-14):\n");
                scanf("%d", &difficulty); //entering difficulty

                /*difficulty must be appropriate number*/
                if(difficulty<7 || difficulty>14)
                {
                printf("incorrect difficulty!\n");
                continue;
                }
                else
                {
                    break;
                }
            }
        /*no break for case 2 , so it will move directly to case 1 after finishing*/

        /*the game itself*/
        case 1:
          while(true){ //while loop to use later for playing again
            char guessed[50]; //all guessed letters
            guessed[0]='\0'; //empty for now
            printf("\nPlease, enter length of word (2-14): \n PS. 6 is recommended\n");
            scanf("%d", &length); //choosing length of word
            while(length<2 || length>14) //word should be of appropriate length
                {
                printf("\nincorrect length of word! please enter again!\n ");
                scanf("%d", &length);
            }
            size_t size=length+1;/*taking account \0 */

            /*dynamically allocating array of characters that will serve as hidden word, represented by dashes*/
            char *hiddenword=(char*)malloc(size*sizeof(char));

            /* adding dashes that represent letter to the empty array*/
            for(int i=0; i<size-1; ++i)
            {
                hiddenword[i]='_';
            }
            hiddenword[size-1]='\0'; //declaring end of word

            /*hangman game itself*/
            hangman(w, length, hiddenword, difficulty, guessed );

            free(hiddenword);//releasing memory

            /*checking if user wants to play again*/
            char a[5];
            printf("\nDO YOU WANT TO PLAY AGAIN? (yes/no)\n");
            scanf("%s", &a);
            if(strcmp(a, "yes")==0)
            {
                printf("\n ONE MORE TIME!!! \n");
                w=w_save; //reset linked list
            }
            else if(strcmp(a, "no")==0)
            {
                printf("\n bye, bye! \n");
                break;
            }
            else
            {
                printf("\n not correct answer, quitting game \n");
                break;
            }
          }
            break;

        /*case for finishing game*/
        case 0:
            printf("Exiting game, Bye!");
            break;

        default:
            printf("incorrect choice!\n aborting the game");
            break;
    }

    printf("\n COPYRIGHT (C) SALAHOV KAMAL \n");
    destroy(w); //releasing memory by destroying linked lists
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "linkedlist.h"

/*function to read from the function and classify and insert into linked list*/
wordlist *read(const char *f){
    FILE *file=fopen(f, "r");
    if (file==NULL){
        return NULL;
    }
    wordlist *wl=NULL;
    word temp; //temporary
    int n;
    while (fgets(temp.st, 30 , file)!=NULL){ //reading line-by-line
        temp.st[strlen(temp.st)-1]='\0'; //putting end of word to each word
        n=strlen(temp.st);

        wordlist *iter=wl;
        while(iter!=NULL && iter->ln!=n)
            iter=iter->next;
        if(iter==NULL){ //creating new list if does not exist
            iter=(wordlist*)malloc(sizeof(wordlist));
            iter->ln=n;
            iter->next=wl;
            iter->list=NULL;
            wl=iter;
        }
        word *n_w=(word*)malloc(sizeof(word));
        *n_w=temp;
        n_w->next=iter->list;
        iter->list=n_w;

    }
    fclose(file);

    return wl;

}

/*function to destroy linked list and free memory*/
void destroy(wordlist *wl){
    while(wl!=NULL){    //freeing memory one-by-one until finished
        wordlist *temp=wl->next;
        word *w_l=wl->list;
        while(w_l!=NULL){
            word *temp=w_l->next;
            free(w_l);
            w_l=temp;
        }
        free(wl);
        wl=temp;
    }
}

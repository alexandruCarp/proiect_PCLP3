#include "lista.h"
#include <stdio.h>

//functie pentru parcurgerea listei si inlocuirea valorilor daca este cazul
void uniformizare(Dlist lista,size_t size){
    if(lista->head == NULL)
        return;
    List p = lista->head->next;
    while(p != NULL){
        Data *x,*y;
        x=((Data*)(p->val));
        y=((Data*)(p->prev->val));
        int difTemp = x->timestamp - y->timestamp;
        if(difTemp >= 100 && difTemp <= 1000){
            x->timestamp += y->timestamp;
            x->timestamp /= 2;
            x->value += y->value;
            x->value /= 2;
        }
        p = p->next;
    }
}
#include "lista.h"
#include <stdio.h>

//functie pentru parcurgerea listei si inlocuirea valorilor daca este cazul
void uniformizare(Dlist lista){
    if(lista->head == NULL)
        return;
    List p = lista->head->next;
    while(p != NULL){
        int difTemp = p->val.timestamp - p->prev->val.timestamp;
        if(difTemp >= 100 && difTemp <= 1000){
            p->val.timestamp += p->prev->val.timestamp;
            p->val.timestamp /= 2;
            p->val.value += p->prev->val.value;
            p->val.value /= 2;
        }
        p = p->next;
    }
}
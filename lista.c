#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

//functie pentru initializarea listei
Dlist initList(){
    Dlist lista = malloc(sizeof(*lista));
    lista->head = NULL;
    lista->tail = NULL;
    lista->nrElem = 0;
    return lista;
}

//functie pentru adaugarea unui element la finalul listei
void adaugaFinal(Dlist lista, Data x){
    List nou = malloc(sizeof(*nou));
    nou->val = x;
    nou->next = NULL;
    nou->prev = lista->tail;
    if(lista->head == NULL){
        lista->head = nou;
        lista->tail = nou;
    }
    else lista->tail->next = nou;
    lista->tail = nou;
}

//functie pentru eliberarea memoriei alocate listei
void freeList(Dlist lista){
    while(lista->head != NULL){
        List urm = lista->head->next;
        free(lista->head);
        lista->head=urm;
    }
    free(lista);
}

//functie pentru afisarea elementelor din lista
void printList(Dlist lista){
    printf("%d\n",lista->nrElem);
    List p = lista->head;
    while(p != NULL){
        printf("%d %.2lf\n",p->val.timestamp,p->val.value);
        p = p->next;
    }
}

//functie pentru eliminarea unui nod din lista
void removeNode(Dlist lista, List nod){
    if(nod != lista->tail)
        nod->next->prev = nod->prev;
    else
        lista->tail = nod->prev;
    if(nod != lista->head)
        nod->prev->next = nod->next;
    else
        lista->head = nod->next;
    free(nod);
    lista->nrElem--;
}

//functie pentru adaugarea unui nod inaintea unui nod dat
void adaugaInainteDeNod(Dlist lista, List p, Data x){
    List nou = malloc(sizeof(*nou));
    nou->val = x;
    nou->next = p;
    nou->prev = p->prev;
    if(p->prev != NULL){
        p->prev->next = nou;
    }
    else
        lista->head = nou;
    p->prev = nou;
    lista->nrElem++;
}
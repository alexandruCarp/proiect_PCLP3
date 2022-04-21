#include "listaDiviziuni.h"
#include <stdlib.h>
#include <stdio.h>

//functie pentru initializarea listei de diviziuni
DlistDiv initListDiv(){
    DlistDiv lista = malloc(sizeof(*lista));
    lista->head = NULL;
    lista->tail = NULL;
    return lista;
}

//functie pentru eliberarea memoriei alocata listei de diviziuni
void freeListDiv(DlistDiv lista){
    while(lista->head != NULL){
        ListDiv urm = lista->head->next;
        free(lista->head);
        lista->head=urm;
    }
    free(lista);
}

//functie pentru afisarea liste de diviziuni
void printListDiv(DlistDiv lista){
    ListDiv p = lista->head;
    while(p != NULL){
        printf("[%d, %d] %d\n",p->val.left,p->val.right,p->val.nrElemente);
        p = p->next;
    }
}

//functie ce introduce o noua diviziune in lista, pastrand ordinea crescatoare
void insert(DlistDiv lista, Diviziune d){
    ListDiv nou = malloc(sizeof(*nou));
    nou->val = d;
    if(lista->head == NULL){
        nou->prev = NULL;
        nou->next = NULL;
        lista->head = nou;
        lista->tail = nou;
    }
    else{
        ListDiv p = lista->head;
        if(d.right <= p->val.left){
            nou->next = p;
            nou->prev = NULL;
            p->prev = nou;
            lista->head = nou;
            return;
        }
        while(p != lista->tail && !(p->val.right <= d.left && p->next->val.left >= d.right))
            p = p->next;
        if(p == lista->tail){
            nou->next = NULL;
            nou->prev = lista->tail;
            lista->tail->next = nou;
            lista->tail = nou;
        }
        else{
            nou->next = p->next;
            nou->prev = p;
            p->next->prev = nou;
            p->next = nou;
        }
    }
}

//functie ce verifica daca diviziunea din care face parte o valoare se afla in lista,
//si ii incrementeaza numarul de elemente in caz afirmativ
int eInLista(DlistDiv lista, double x){
    ListDiv p = lista->head;
    while(p != NULL){
        if(x >= p->val.left && x <= p->val.right){
            p->val.nrElemente++;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
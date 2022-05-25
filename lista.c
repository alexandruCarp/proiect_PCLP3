#include "lista.h"
//functie pentru initializarea listei
Dlist initList(){
    Dlist lista = malloc(sizeof(*lista));
    lista->head = NULL;
    lista->tail = NULL;
    lista->nrElem = 0;
    return lista;
}

//functie pentru adaugarea unui element la finalul listei
void adaugaFinal(Dlist lista, void* x,size_t nrbytes){
    List nou = malloc(sizeof(Nod));
    nou->val=malloc(nrbytes);
    memcpy(nou->val,x,nrbytes);
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
        if(lista->head->val!=NULL)
            free(lista->head->val);
        free(lista->head);
        lista->head=urm;
    }
    free(lista);
}

//functie pentru afisarea elementelor din lista
void printList(Dlist lista,size_t size){
    printf("%d\n",lista->nrElem);
    List p = lista->head;
    while(p != NULL){
        Data *x;
        x=((Data*)(p->val));
        printf("%d %.2lf\n",x->timestamp,x->value);
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
    if(nod->val!=NULL)
        free(nod->val);
    free(nod);
    lista->nrElem--;
}

//functie pentru adaugarea unui nod inaintea unui nod dat
void adaugaInainteDeNod(Dlist lista, List p, void* x,size_t size){
    List nou = malloc(sizeof(Nod));
    nou->val=malloc(size);  
    memcpy(nou->val,x,size);
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
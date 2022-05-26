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

    if(lista->head == NULL){
        lista->head = nou;
        lista->tail = nou;
        nou->link = NULL;
        return;
    }
    lista->tail->link = XOR(lista->tail->link,nou);
    nou->link = lista->tail;
    lista->tail = nou;
}

//functie pentru eliberarea memoriei alocate listei
void freeList(Dlist lista){
    List prev = NULL;
    while(lista->head != NULL){
        List urm = XOR(prev,lista->head->link);
        prev = lista->head;

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
    List prev = NULL;
    while(p != NULL){
        Data *x;
        x=((Data*)(p->val));
        printf("%d %.2lf\n",x->timestamp,x->value);

        List tmp = p;
        p = XOR(p->link,prev);
        prev = tmp;
    }
}

//functie pentru eliminarea unui nod din lista
void removeNode(Dlist lista, List nod, List prev){
    List next = XOR(nod->link, prev);
    if(nod != lista->tail)
        next->link = XOR( XOR(next->link,nod), prev);
    else
        lista->tail = prev;
    if(nod != lista->head)
        prev->link = XOR( XOR(prev->link, nod), next);
    else
        lista->head = next;
    if(nod->val!=NULL)
        free(nod->val);
    free(nod);
    lista->nrElem--;
}

//functie pentru adaugarea unui nod inaintea unui nod dat
void adaugaInainteDeNod(Dlist lista, List prev, List p, void* x,size_t size){
    List nou = malloc(sizeof(Nod));
    nou->val=malloc(size);  
    memcpy(nou->val,x,size);

    nou->link = XOR(prev,p);

    if(prev != NULL){
        prev->link = XOR(XOR(prev->link,p), nou);
    }
    else
        lista->head = nou;

    p->link = XOR(XOR(p->link,prev), nou);

    lista->nrElem++;
}
//declaratia listei si a functiilor care lucreaza cu aceasta
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct data
{
    int timestamp;
    double value;
}Data;

typedef struct nod
{
    void* val;
    size_t size;
    struct nod *next,*prev;
}Nod,*List;

typedef struct dlist
{
    List head,tail;
    int nrElem;
}*Dlist;

Dlist initList();
void adaugaFinal(Dlist, void*,size_t);
void freeList(Dlist);
void printList(Dlist,size_t);
void removeNode(Dlist, List);
void adaugaInainteDeNod(Dlist, List, void*,size_t);
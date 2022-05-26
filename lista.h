//declaratia listei si a functiilor care lucreaza cu aceasta
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define XOR(a, b) (List)((intptr_t)(a)^(intptr_t)(b))
typedef struct data
{
    int timestamp;
    double value;
}Data;

typedef struct nod
{
    void* val;
    size_t size;
    struct nod *link;
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
void removeNode(Dlist, List, List);
void adaugaInainteDeNod(Dlist, List, List, void*,size_t);
//declaratia listei si a functiilor care lucreaza cu aceasta

typedef struct data
{
    int timestamp;
    double value;
}Data;

typedef struct nod
{
    Data val;
    struct nod *next,*prev;
}Nod,*List;

typedef struct dlist
{
    List head,tail;
    int nrElem;
}*Dlist;

Dlist initList();
void adaugaFinal(Dlist, Data);
void freeList(Dlist);
void printList(Dlist);
void removeNode(Dlist, List);
void adaugaInainteDeNod(Dlist, List, Data);
//declaratia tipului diviziune, a listei de diviziuni si a functiilor care lucreaza cu aceasta
typedef struct div{
    int left,right,nrElemente;
}Diviziune;

typedef struct nodDiv
{
    Diviziune val;
    struct nodDiv *next,*prev;
}NodDiv,*ListDiv;

typedef struct dlistDiv
{
    ListDiv head,tail;
}*DlistDiv;

DlistDiv initListDiv();
void freeListDiv(DlistDiv);
void printListDiv(DlistDiv);
void insert(DlistDiv, Diviziune);
int eInLista(DlistDiv, double);
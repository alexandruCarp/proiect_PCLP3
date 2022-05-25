#include "lista.h"
#include <stdio.h>
#define k 5

//functie pentru calculul valorii mediane
double calcul_median(List nod,Dlist lista,size_t size){
    List startFereastra = nod->prev->prev;
    List finalFereastra = nod->next->next;
    List p = startFereastra;
    for(List p = startFereastra; ; p = p->next){
        int maiMici = 0, maiMari = 0;
        for(List q = startFereastra; ; q = q->next){
            Data *x,*y;
            x=((Data*)(q->val));
            y=((Data*)(p->val));
            if(x->value < y->value)
                maiMici++;
            if(x->value > y->value)
                maiMari++;
            if(q == finalFereastra)
                break;
        }
        Data* x;
        x=((Data*)(p->val));
        if(maiMici <= k/2 && maiMari <= k/2)
            return x->value;
        if(p == finalFereastra)
            break;
    }
}

//functie pentru calculul mediei aritmetice
double calcul_medie(List nod,Dlist lista,size_t size){
    List startFereastra = nod->prev->prev;
    List finalFereastra = nod->next->next;
    List p = startFereastra;
    double medie = 0;
    for(List p = startFereastra; ; p = p->next){
        Data *x;
        x=((Data*)(p->val));
        medie += x->value;
        if(p == finalFereastra)
            break;
    }
    medie /= k;
    return medie;
}

//functie recursiva ce calculeaza pentru fiecare nod noua valoare si i-o atribuie la intoarcerea din recursivitate
void eliminare23(Dlist lista, List nod, double (*calcul)(List,Dlist,size_t), size_t size){
    if(nod->next->next == NULL){
        removeNode(lista,nod->next);
        removeNode(lista,nod);
        return;
    }
    if(nod->prev == NULL || nod->prev->prev == NULL){
        eliminare23(lista,nod->next,calcul,sizeof(Data*));
        removeNode(lista,nod);
        return;
    }
    double valoareNoua = calcul(nod,lista,sizeof(Data*));
    eliminare23(lista,nod->next,calcul,sizeof(Data*));
    ((Data*)(nod->val))->value=valoareNoua;
    return;
}
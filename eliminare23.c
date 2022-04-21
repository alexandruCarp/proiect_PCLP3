#include "lista.h"
#include <stdio.h>
#define k 5

//functie pentru calculul valorii mediane
double calcul_median(List nod,Dlist lista){
    List startFereastra = nod->prev->prev;
    List finalFereastra = nod->next->next;
    List p = startFereastra;
    for(List p = startFereastra; ; p = p->next){
        int maiMici = 0, maiMari = 0;
        for(List q = startFereastra; ; q = q->next){
            if(q->val.value < p->val.value)
                maiMici++;
            if(q->val.value > p->val.value)
                maiMari++;
            if(q == finalFereastra)
                break;
        }
        if(maiMici <= k/2 && maiMari <= k/2)
            return p->val.value;
        if(p == finalFereastra)
            break;
    }
}

//functie pentru calculul mediei aritmetice
double calcul_medie(List nod,Dlist lista){
    List startFereastra = nod->prev->prev;
    List finalFereastra = nod->next->next;
    List p = startFereastra;
    double medie = 0;
    for(List p = startFereastra; ; p = p->next){
        medie += p->val.value;
        if(p == finalFereastra)
            break;
    }
    medie /= k;
    return medie;
}

//functie recursiva ce calculeaza pentru fiecare nod noua valoare si i-o atribuie la intoarcerea din recursivitate
void eliminare23(Dlist lista, List nod, double (*calcul)(List,Dlist)){
    if(nod->next->next == NULL){
        removeNode(lista,nod->next);
        removeNode(lista,nod);
        return;
    }
    if(nod->prev == NULL || nod->prev->prev == NULL){
        eliminare23(lista,nod->next,calcul);
        removeNode(lista,nod);
        return;
    }
    double valoareNoua = calcul(nod,lista);
    eliminare23(lista,nod->next,calcul);
    nod->val.value = valoareNoua;
    return;
}
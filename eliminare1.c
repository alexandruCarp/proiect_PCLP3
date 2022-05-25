#include "lista.h"
#include <stdio.h>
#include <math.h>
#define k 5

//functie care verifica daca un nod trebuie eliminat sau nu, conform cerintei
int eOk(List nod,Dlist lista,size_t size){
    List startFereastra = nod->prev->prev;
    List finalFereastra = nod->next->next;
    double medie = 0,deviatie = 0;
    List p = startFereastra;
    for(List p = startFereastra; ; p = p->next){
        Data *x;
        x=((Data*)(p->val));
        medie += x->value;
        if(p == finalFereastra)
            break;
    }
    medie /= k;
    for(List p = startFereastra; ; p = p->next){
        Data *x;
        x=((Data*)(p->val));
        if(x!=NULL)
        deviatie += (x->value - medie)*(x->value - medie);
        if(p == finalFereastra)
            break;
    }
    deviatie /= k;
    deviatie = sqrt(deviatie);
    Data *x;
        x=((Data*)(nod->val));
    if(x->value >= medie - deviatie && x->value <= medie + deviatie)
            return 1;
    return 0;
}

//functie recursiva care verifica pentru fiecare nod din lista daca trebuie eliminat 
//si il elimina la intoarcerea din recursivitate
void eliminare1(Dlist lista, List nod,size_t size){
    if(nod->next->next == NULL)
        return;
    if(nod->prev == NULL || nod->prev->prev == NULL){
        eliminare1(lista,nod->next,size);
        return;
    }
    int ok = eOk(nod,lista,size);
    eliminare1(lista,nod->next,size);
    if(!ok)
        removeNode(lista,nod);
    return;
}
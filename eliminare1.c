#include "lista.h"
#include <stdio.h>
#include <math.h>
#define k 5

//functie care verifica daca un nod trebuie eliminat sau nu, conform cerintei
int eOk(List nod,List prev,Dlist lista,size_t size){
    List next = XOR(nod->link,prev);
    List startFereastra = XOR(prev->link,nod);
    List finalFereastra = XOR(next->link,nod);
    double medie = 0,deviatie = 0;
    List p = startFereastra;
    List p_prev = XOR(p->link,prev);
    List tmp = p_prev;
    for(List p = startFereastra; ; p = XOR(p->link,p_prev)){
        p_prev = tmp;
        Data *x;
        x=((Data*)(p->val));
        medie += x->value;
        if(p == finalFereastra)
            break;
        tmp = p;
    }
    medie /= k;
    p_prev = XOR(startFereastra->link,prev);
    tmp = p_prev;
    for(List p = startFereastra; ; p = XOR(p->link,p_prev)){
        p_prev = tmp;
        Data *x;
        x=((Data*)(p->val));
        if(x!=NULL)
        deviatie += (x->value - medie)*(x->value - medie);
        if(p == finalFereastra)
            break;
        tmp = p;
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
void eliminare1(Dlist lista, List nod,List prev,size_t size){
    List next = XOR(nod->link,prev);
    if(XOR(next->link,nod) == NULL)
        return;
    if(prev == NULL || XOR(prev->link,nod) == NULL){
        eliminare1(lista,next,nod,size);
        return;
    }
    int ok = eOk(nod,prev,lista,size);
    eliminare1(lista,next,nod,size);
    if(!ok)
        removeNode(lista,nod,prev);
    return;
}
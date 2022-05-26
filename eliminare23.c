#include "lista.h"
#include <stdio.h>
#define k 5

//functie pentru calculul valorii mediane
double calcul_median(List nod,List prev,Dlist lista,size_t size){
    List next = XOR(nod->link,prev);
    List startFereastra = XOR(prev->link,nod);
    List finalFereastra = XOR(next->link,nod);
    List p = startFereastra;
    List p_prev = XOR(startFereastra->link,prev);
    List tmp = p_prev;
    for(List p = startFereastra; ; p = XOR(p->link,p_prev)){
        int maiMici = 0, maiMari = 0;
        p_prev = tmp;

        List q_prev = XOR(startFereastra->link,prev);
        List tmpq = q_prev;
        for(List q = startFereastra; ; q = XOR(q->link,q_prev)){
            q_prev = tmpq;
            Data *x,*y;
            x=((Data*)(q->val));
            y=((Data*)(p->val));
            if(x->value < y->value)
                maiMici++;
            if(x->value > y->value)
                maiMari++;
            if(q == finalFereastra)
                break;

            tmpq = q;
        }
        Data* x;
        x=((Data*)(p->val));
        if(maiMici <= k/2 && maiMari <= k/2)
            return x->value;
        if(p == finalFereastra)
            break;

        tmp = p;
    }
}

//functie pentru calculul mediei aritmetice
double calcul_medie(List nod,List prev,Dlist lista,size_t size){
    List next = XOR(nod->link,prev);
    List startFereastra = XOR(prev->link,nod);
    List finalFereastra = XOR(next->link,nod);
    List p = startFereastra;
    double medie = 0;
    List p_prev = XOR(startFereastra->link,prev);
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
    return medie;
}

//functie recursiva ce calculeaza pentru fiecare nod noua valoare si i-o atribuie la intoarcerea din recursivitate
void eliminare23(Dlist lista, List nod, List prev,double (*calcul)(List,List,Dlist,size_t), size_t size){
    List next = XOR(nod->link,prev);
    if(XOR(next->link,nod) == NULL){
        removeNode(lista,next,nod);
        removeNode(lista,nod,prev);
        return;
    }
    if(prev == NULL || XOR(prev->link,nod) == NULL){
        eliminare23(lista,next,nod,calcul,sizeof(Data*));
        removeNode(lista,nod,prev);
        return;
    }
    double valoareNoua = calcul(nod,prev,lista,sizeof(Data*));
    eliminare23(lista,next,nod,calcul,sizeof(Data*));
    ((Data*)(nod->val))->value=valoareNoua;
    return;
}
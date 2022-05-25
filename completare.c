#include <stdio.h>
#include "lista.h"
#define prag 1000
#define k 3

//functie pentru calculul lui C
double C(int timestamp,int left,int right){
    return ( (double)timestamp - left)/(right - left);
}

//functie pentru calculul lui w
double W(int i){
    double numitor = 0;
    for(int j = 0;j < k;j++)
        numitor += (((double)j/(k-1))*((double)j/(k-1))*0.9+0.1);
    return (((double)i/(k-1))*((double)i/(k-1))*0.9+0.1)/numitor;
}

//functie pentru calculul lui f
double f(List left,List right, double c,size_t size){
    double value = 0;
    for(int i = k-1; i >= 0 ; i--){
        Data *x,*y;
        x=((Data*)(left->val));
        y=((Data*)(right->val));
        value = value + (1-c)*x->value*W(i) + c*y->value*W(i);
        left = left->prev;
        right = right->next;
    }
    return value;
}

//functie ce parcurge lista si calculeaza si introduce noile valori daca este cazul
void completare(Dlist lista,size_t size){
    if(lista->head == NULL)
        return;
    List p = lista->head;
    while(p->next != NULL){
        List urm = p->next;
        Data *x,*y;
        x=((Data*)(urm->val));
        y=((Data*)(p->val));
        if(x->timestamp - y->timestamp > prag){
            int pas = prag/5;
            int time = y->timestamp + pas;
            int timelimit=x->timestamp;
            while(time < timelimit){
                double c = C(time,y->timestamp,x->timestamp);
                Data aux;
                double newval=f(p,urm,c,size);
                aux.timestamp = time;
                aux.value = newval;  
                adaugaInainteDeNod(lista,urm,&aux,size);
                time += pas;
            }
        }
        p = urm;
    }
}
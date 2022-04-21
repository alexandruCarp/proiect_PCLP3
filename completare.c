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
double f(List left,List right, double c){
    double value = 0;
    for(int i = k-1; i >= 0 ; i--){
        value = value + (1-c)*left->val.value*W(i) + c*right->val.value*W(i);
        left = left->prev;
        right = right->next;
    }
    return value;
}

//functie ce parcurge lista si calculeaza si introduce noile valori daca este cazul
void completare(Dlist lista){
    if(lista->head == NULL)
        return;
    List p = lista->head;
    while(p->next != NULL){
        List urm = p->next;
        if(urm->val.timestamp - p->val.timestamp > prag){
            int pas = prag/5;
            int time = p->val.timestamp + pas;
            while(time < urm->val.timestamp){
                double c = C(time,p->val.timestamp,urm->val.timestamp);
                Data x;
                x.timestamp = time;
                x.value = f(p,urm,c);
                adaugaInainteDeNod(lista,urm,x);
                time += pas;
            }
        }
        p = urm;
    }
}
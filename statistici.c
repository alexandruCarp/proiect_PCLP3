#include <stdio.h>
#include "lista.h"
#include "listaDiviziuni.h"

//functie ce verifica pentru fiecare nod daca diviziunea corespunzatoare se afla deja in lista, 
//daca se afla ii creste numarul de aparitii, altfel introduce o noua diviziune in lista de diviziuni
void statistici(Dlist lista, int delta){
    DlistDiv listaDiv = initListDiv();
    List p = lista->head;
    while(p != NULL){
        if(!eInLista(listaDiv,p->val.value)){
            Diviziune d;
            int c = p->val.value / delta ;
            d.left = c * delta;
            d.right = (c+1) * delta;
            if(p->val.value < d.left || p->val.value > d.right){
                d.left -= delta;
                d.right -= delta;
            }
            d.nrElemente = 1;
            insert(listaDiv,d);
        }
        p = p->next;
    }
    printListDiv(listaDiv);
    freeListDiv(listaDiv);
}
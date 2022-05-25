#include <stdio.h>
#include "lista.h"

//functie ce verifica pentru fiecare nod daca diviziunea corespunzatoare se afla deja in lista, 
//daca se afla ii creste numarul de aparitii, altfel introduce o noua diviziune in lista de diviziuni
void statistici(Dlist lista, int delta,size_t size){
    List p = lista->head;
    float min=99999,max=-99999;
    while(p!=NULL)
        {
            Data *x;
            x=((Data*)(p->val));
            if(x->value>max)
                max=x->value;
            if(x->value<min)
                min=x->value;
            p=p->next;
        }
    int i,minint;
    for(i=-9999;i<9999;i++)
        if(i<=min && min<i+1)
            {
                minint=i;
                break;
            }
    while(minint<=max)
    {
        List parc=lista->head;
        int numbers=0;
        while(parc!=NULL)
            {
                Data *x;
                x=((Data*)(parc->val));
                if(x->value>=minint && x->value<=minint+delta)
                    numbers++;
                parc=parc->next;
            }
       
        if(numbers!=0)
            printf("[%d, %d] %d\n",minint,minint+delta,numbers); 
            minint+=delta;
    }

}
#include <stdio.h>
#include "lista.h"
#include "taskuri.h"
#include <string.h>

// functie pentru citirea datelor 
void read_data(Dlist lista){
    scanf("%d",&lista->nrElem);
    for(int i = 0;i < lista->nrElem; i++){
        Data x;
        scanf("%d%lf",&x.timestamp,&x.value);
        adaugaFinal(lista,&x,sizeof(Data));
    }
}

int main(int argc, char *argv[]){
    int delta = 0;
    Dlist lista = initList();
    read_data(lista);

    //parcurg argumente din linia de comanda si apelez functia corespunzatoare
    for(int i = 1; i < argc ; i++){
        if(!strcmp(argv[i],"--e1"))
            eliminare1(lista,lista->head,sizeof(Data));            
        if(!strcmp(argv[i],"--e2"))
            eliminare23(lista,lista->head,calcul_median,sizeof(Data));
        if(!strcmp(argv[i],"--e3"))
            eliminare23(lista,lista->head,calcul_medie,sizeof(Data));
        if(!strcmp(argv[i],"--u"))
            uniformizare(lista,sizeof(Data));
        if(!strcmp(argv[i],"--c"))
            completare(lista,sizeof(Data));
        if(strstr(argv[i],"--st")){
            sscanf(argv[i],"--st%d",&delta);
            statistici(lista,delta,sizeof(Data));
        }
    }
    //in caz ca cerinta nu a fost "statistici", afisez lista dupa prelucrare
    if(delta == 0)
        printList(lista,sizeof(Data*));

    //eliberez memoria alocata listei    
    freeList(lista);
}
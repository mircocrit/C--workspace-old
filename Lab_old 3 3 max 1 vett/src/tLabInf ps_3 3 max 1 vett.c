// Scrivere un programma che calcoli il massimo di un vettore di 10 elementi

#include <stdio.h>
#include <stdlib.h>
#define DIM 10 //DIM=parametrizzazione

int main() {
    int v[DIM],max,i;
    for(i=0;i<DIM;i++){
        printf("Inserire l'elemento: 2");
        scanf("%d",&v[i]);
    }
    max=v[0];
    for(i=1;i<DIM;i++){
        if(max<v[i])        max=v[i];
    }
    printf("Il valore piu grande del vettore e' %d\n",max);
    return 0;
}

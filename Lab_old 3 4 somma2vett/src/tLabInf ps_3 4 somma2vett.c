//Scrivere la somma di 2 vettori di interi di 5 elementi

#include <stdio.h>
#include <stdlib.h>
#define DIM 5

int main() {
    int v1[DIM],v2[DIM],i;
    for(i=0;i<DIM;i++){
        printf("Inserire il valore num %d del 1° vettore: ",i+1);
        scanf("%d",&v1[i]);
    }
    printf("\n");
    for(i=0;i<DIM;i++){
        printf("Inserire il valore nume %d del 2° vettore: ",i+1);
        scanf("%d",&v2[i]);
    }
    printf("L'array somma e':\n");
    for(int i=0;i<DIM;i++){
        printf("%d\n",v1[i]+v2[i]);
    }
    return 0;
}

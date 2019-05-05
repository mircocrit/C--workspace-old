// Scrivere un programma per il calcolo della norma di un vettore di 5 elementi:

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 5

void acquisizione(float[DIM]);
float normavett(float*,int);

int main() {
    float norma,vett[DIM];
    acquisizione(vett);
    norma=normavett(vett,DIM);
    printf("La norma e' %f\n",norma);
    return 0;
}

void acquisizione(float vett[DIM]){
    for(int i=0;i<DIM;i++){
        printf("Inserire l'elemento %d: ",i+1);
        scanf("%f",&vett[i]);
        }
}

float normavett(float *v,int d){
    float n=0;
    for(int i=0;i<d;i++)
        n+=pow(v[i],2); //norma=radice di(somma di tutti gli elementi elevati al quadrato)
    n=sqrt(n);
    return n;
}

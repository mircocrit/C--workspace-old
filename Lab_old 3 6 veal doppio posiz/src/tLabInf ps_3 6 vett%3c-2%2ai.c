//Scrivere un programma che,dato un vettore con n dati elementi, metta in ogni elemento del vettore un numero doppio di quello della sua posizione

#include <stdio.h>
#include <stdlib.h>
#define n 20

int main() {
    int vett[20],i;
    for(i=0;i<n;i++){
        vett[i]=i*2;
        printf("Il valore dell'elemento in posizone %d e' %d\n",i,vett[i]);
    }
    return 0;
}

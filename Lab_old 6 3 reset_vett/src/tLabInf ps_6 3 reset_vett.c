//scrivere un programma che acquisisce un vettore di 10 elem e ne resetta gli elementi

#include <stdio.h>
#include <stdlib.h>

void inserimento(int*);
void resetvett(int*);
void stampa(int *);

int main() {
    int vett[10];
    inserimento(vett);
    resetvett(vett);
    stampa(vett);
    return 0;
}

void inserimento(int v[10]){
    int i;
    for(i=0;i<10;i++){
        printf("Inserire l'elemento %d del vettore ",i+1);
        scanf("%d",&v[i]);
    }
    printf("\n");
}
void resetvett(int *p){
    printf("Resetto gli elementi..\n");
    for(int i=0;i<10;i++){
        *(p+i)=0;
    }
}
void stampa(int *p){
    printf("Il vettore e':\n");
    for(int i=0;i<10;i++)
        printf("%d\n",*(p+i));
    }

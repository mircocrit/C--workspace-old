//Scrivere un programma per fare la somma di 2 vettori,usando i puntatori

#include <stdio.h>
#include <stdlib.h>
#define n 10

void acquisizione(int*,int);
void sommav(int*,int*,int*,int);
void stampa(int*,int);

int main() {
    int dim,vet1[n],vet2[n],vsomma[n];
    printf("Inserire la dimesione dei vettori: ");
    scanf("%d",&dim);
    printf("Acquisizone 1° vettore\n");
    acquisizione(vet1,dim);
    printf("Acquisizone 2° vettore\n");
    acquisizione(vet2,dim);
    sommav(vet1,vet2,vsomma,dim);//vsomma viene creato implicitamente, le copie puntano ai vettori originali
    printf("Il vettore somma e':\n");
    stampa(vsomma, dim);
    return 0;
}
void acquisizione(int *v,int dim){
    for(int i=0;i<dim;i++){
        printf("Elemento %d: ",i+1);
        scanf("%d",(v+i));
    }
    printf("\n");
}

void sommav(int*v1, int*v2, int *vsomma,int d){    //f scriverà su uno spazio di memoria non creato da lei
    for(int i=0;i<d;i++)
        *(vsomma+i)=*(v1+i)+*(v2+i);
}
void stampa(int *v,int dim){
    for(int i=0;i<dim;i++){
        printf("%d\n",*(v+i));
    }
}

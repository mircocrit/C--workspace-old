//Scrivere un programma per il calcolo del fattoriale

#include <stdio.h>
#include <stdlib.h>

int fattoriale(int);

int main() {
    int n,fatt;
    printf("Inserire il valore: ");
    scanf("%d",&n);
    fatt=fattoriale(n);
    printf("Il fattoriale di %d e' %d\n",n,fatt);
    return 0;
}

int fattoriale(int n){
    if(n==0)        return 1;
    else         return n*fattoriale(n-1);
}

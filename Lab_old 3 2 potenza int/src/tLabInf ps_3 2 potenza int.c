// Scrivere l'algoritmo e il programma per il calcolo della potenza intera

#include <stdio.h>
#include <stdlib.h>
int main(){
    int base,exp,i,work,scelta=1;
    float ris;
    do{
        printf("Inserisci la base:\n");
        scanf("%d",&base);
        printf("Inserisci l'esponente:\n");
        scanf("%d",&exp);
        work=exp;
        if(exp<0)    work=-exp;
        ris=1;
        for(i=0;i<work;i++)
            ris*=base;
        if(exp<0)    ris=(1/ris);

        printf("Risultato: \t %f\n",ris);
        printf("Ripetere? S=1 N=0\n");
        scanf("%d",&scelta);
    }while(scelta==1);
    return 0;
}

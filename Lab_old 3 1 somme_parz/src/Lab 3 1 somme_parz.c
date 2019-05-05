/* Scrivere un programma e l'algoritmo per eseguire le somme parziali,cioe' la somma degli elementi pari e il prodotto degli elementi dispari, per almeno 6 numeri
 */
#include <stdio.h>
#include <stdlib.h>

int main(){
    int nop,i=0,somma=0,pr=1,op;
    do{
        printf("Inserire il numero di operandi(>5)\n");
        scanf("%d",&nop); //se n in base 10, il pc prima lo converte in base 2  e poi lo memorizza
    }while(nop<5);
    do{
        printf("Inserire il valore\n");
        scanf("%d",&op);
        if(op%2==0)     somma+=op;
        else      pr*=op;
        i++;
    }while(i<nop);
    printf("La somma dei numeri pari e' %d\n Il prodotto dei numeri disparie ' %d",somma,pr);
    return 0;
}
/* altrimenti:
 * int f2(double),f1(int);
 * {x=f2(x)
 * int f2(double);
 * {
 * f1(x)}
 */

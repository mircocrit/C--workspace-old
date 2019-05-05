/* Dato un vettore di n elementi, il programma deve fare la media degli elementi del vettore in posizione pari e dispari e
 stampare il vettore se la media(dei pari) e' superiore alla media dei primi 6 elementi
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 5

int main() {
    int a[n];
    float med_pari=0,med_disp=0,med_6=0;
    int i;
    for(i=0;i<n;i++){
        printf("Inserire l'elemento num %d: ",i+1);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        if((i%2)==0)    med_pari+=a[i];
        else    med_disp+=a[i];
        if(i<7) med_6+=a[i];
        }
    med_pari/=n;
    med_disp/=n;
    med_6/=6;
    printf("La media degli elementi del vettore in posizone pari e' %f\n",med_pari);
    printf("La media degli elementi del vettore in posizone dispari e' %f\n",med_disp);
    if(med_6<((med_disp+med_pari)/2))
        for(i=0;i<n;i++)
            printf("L'elemento num %d e': %d",i+1,a[i]);
    return 0;
}

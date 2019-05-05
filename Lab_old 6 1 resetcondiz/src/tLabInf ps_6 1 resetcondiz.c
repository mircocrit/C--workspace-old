// Scrivere un programma che resetti  il valore di se e' <0

#include <stdio.h>
#include <stdlib.h>

void resetcondiz(int*);

int main() {
    int a;
    printf("Inserire a:\n");
    scanf("%d",&a);
    int *p=&a;
    resetcondiz(p);
    printf("Il valore di a e':%d\nIl suo indirizzo e'%p\n",a,&a);
    return 0;
}

void resetcondiz(int *p){
    if (*p<0)        *p=0;
}

/*es con struct
 //nome(double pi,*pi)
 creo un nuovo tipo di struct che restituisca la variabile a
 La funzoine restituise il paaraentro in uscita come indirizzo:
 p1=&a,     p2=&b; p3=&c
 a1=&a
typedef struct{
 int a,b,c;
 double f,g,h;
 }ax;
resetcondiz(int a, double b, int *a, int*b, int c; double *f,g,h){}*/

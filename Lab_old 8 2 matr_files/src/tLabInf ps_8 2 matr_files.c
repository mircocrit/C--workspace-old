/* Scrivere un programma che:
 1) Legge un file contenente il numero delle righe e colonne della matrice di double,scritta per righe e allocata dinamicamente
 2) Trova il minimo fra le righe pari e dispari e stampa la somma dei 2 minimi
 3) Controllare il numero degli elementi  minore o uguale alla somma dei 2 minimi
 */

#include <stdio.h>
#include <stdlib.h>

int readMatr(int *r,int *c);
float min_D(int r, int c, float m[][]);
float min_P(int r, int c, float m[][]);
void islower_somma_min(int r,int c,float m[][]);

int main() {
    int i,j,r,c,minP,minD,m,s;

    s=minDisp*minPari;
    printf("la somma dei minimi e' %f",s);
    return 0;
}

int readMatr(&r,&c){
    int *fp;
    double mat[i][j];
    fp=fopen("matrice.txt","r");
    fscanf(fp,"%d,%d",*r,*c);
    matr=malloc(r,sizeof(double)); //puntatore a ciascuna riga, pertanto alloco memoria per ciascuna di esse
    for(int i=0;i<r,i++)
        mat[i]=malloc(sizeof(double)*c);
    for(int i=0;i<r,i++)
        for(int j=0,j<c,j++)
            fscanf(fp,%f,&mat[i][j]);
    return mat;
}

float min_D(int r, int c, float m[][]){
    printf("Minimo fra le righe dispari\n);
    for(i=1;i<r;i+2)
        for(j=0,j<c,j++)
            if(minDisp>m[i][j])        minDisp=m[i][j];
           return minDisp;
       }

float min_P(int r, int c, float m[][]){
    printf("Minimo fra le righe pari\n);
        for(i=0,i<r,i+2)
            for(j=0;j<c;j++)
                if(minPari>m[i][j])        minPari=m[i][j];
         return  minPari;
       }
void islower_somma_min(int r,int c,float m[][]){
    printf("Elem minore di somma fra 2 minimi\n");
    for(i=0;i<r;i++)
       for(j=0;j<c;j++)
            if(s>m[i][j])        i++;
               printf("gli elementi minori di s sono %d",i);
           }

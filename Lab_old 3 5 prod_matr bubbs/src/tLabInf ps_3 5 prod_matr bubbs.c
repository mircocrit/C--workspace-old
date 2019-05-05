//Scrivere un programma che calcoli il prodotto fra matrici

#include <stdio.h>
#include <stdlib.h>
#define n 10
#define m 10
#define l 10

int main(){
    int L,N,M,A[l][m],B[m][n],C[l][n],i,j,k,g=0;
    do{
        printf("Inserire il num righe della 1^ matrice (max 10): ");
        scanf("%d",&L);//l
    }while(L>10);
    do{
        printf("Inserire il num colonne della 1^ matrice (= nm righe della 2^ matrice (max 10)): ");
        scanf("%d",&M);
    }while(M>10);
    do{
        printf("Inserire il num colonne della 2^ matrice (max 10): ");
        scanf("%d",&N);//n
    }while(N>10);

    for(i=0;i<L;i++){
        for(j=0;j<M;j++){
            printf("Inserisci A(%d,%d)\t",i+1,j+1);
            scanf("%d",&A[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            printf("Inserisci B(%d,%d)\t",i+1,j+1);
            scanf("%d",&B[i][j]);
        }
    }
    printf("\n");
    for(i=0;i<L;i++)
        for(k=0;k<N;k++){
            C[i][k]=0;
            for(j=0;j<M;j++)
                C[i][k]=C[i][k]+A[i][j]*B[j][k];    //ij*jk+quelli di prima
        }
    printf("Matrice prodotto:\n");
    for(i=0;i<L;i++){
        for(k=0;k<N;k++){
            printf("%-15d ",C[i][k]);
            g++;
            if(g>=N) {
                printf("\n");
                g=0;
            }

        }
    }
    return 0;
}


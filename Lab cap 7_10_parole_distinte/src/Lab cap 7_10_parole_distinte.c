//Scrivere un programma che legge un vettore di parole e stampa a video le parole distinte memorizzate in tale vettore
//CALLOC

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10

void inserimento(char*[],int*);
int rimoz_duplicati(char*[],int);
void stampa(char*[],int);

int main(){
	int tot=0;
	char *array[MAX];
	inserimento(array,&tot);
	tot=rimoz_duplicati(array,tot);
	stampa(array,tot);
	system("pause");
	return 0;
   }

void inserimento(char*parola[],int *dim){
	int i=0;
	int flag=1;
	for(i=*dim;i<MAX && flag==1;i++){
		printf("Inserire parola:	");
		//parola[i]=calloc(20,sizeof(char));
		scanf("%s",parola[i]);
		printf("Continuare? S=1 N=0:		");
		scanf("%d",&flag);
		(*dim)++;
	}
}

int rimoz_duplicati(char*vet[],int dim){
	int i=0,j=0,k=0;
	int dup=0;
	for(i=1;i<dim;i++){
		dup=0;
		for(j=0;j<i;j++){
			if(strcmp(vet[j],vet[i])==0)
				dup=1;
		}
		if(!dup){
			strcpy(vet[k],vet[i]);
			k++;
		}
	}
	return k;
}

void stampa(char*vett[],int dim){
	for(int i=0;i<dim;i++)
		printf("%s\n",vett[i]);
}

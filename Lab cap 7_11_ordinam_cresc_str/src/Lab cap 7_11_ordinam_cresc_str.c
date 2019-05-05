//Scrivere un programma in C che legge un vettore  di parole e lo ordina in maniera crescente

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10

void inserimento(char*[],int*);
void bubble_sort(char*[],int);
void stampa(char*[],int);

int main() {
	int tot=0;
	char *array[MAX];
	inserimento(array,&tot);
	bubble_sort(array,tot);
	stampa(array,tot);
	system("pause");
	return 0;
}

void inserimento(char*parola[],int *dim){
	int i=0;
	int flag=1;
	for(i=*dim;i<MAX && flag==1;i++){
		printf("Inserire parola\n");
		parola[i]=calloc(20,sizeof(char));
		scanf("%s",parola[i]);
		printf("Continuare?\n");
		scanf("%d",&flag);
		(*dim)++;
	}
}

void bubble_sort(char *arr[], int num){
	int i,j;
	char *temp=NULL;
	for(i=0;i<num;i++){
		for(j=0;j<(num-i-1);j++){
			if(strcmp(*(arr+j),*(arr+j+1))==1){	//arr[j]>arr[j+1]
				temp=*(arr+j);
				*(arr+j)=*(arr+j+1);
				*(arr+j+1)=temp;
				}
			}
		}

}

void stampa(char *arr[],int num){
	for(int i=0;i<num;i++){
		printf("%s\n",arr[i]);
	}
}

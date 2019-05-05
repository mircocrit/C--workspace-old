/*Ordinamento persone caratterizzate da eta,reddito altezza.
dove la relazone d'ordine e' definita sulla base di eta' e,a parita di eta',di reddito(il piu basso prima)
 -Usare operatore di confronto da implementare nella relzione d'ordine
 -l'array conterra' valori di tipo struttutrato persona, percio la relazione d'ordine valutera l'ordine tra due valori persona */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PATH "D:\\C-workspace old\\Lab 4 ordinam pers\\insertion.txt"

typedef struct{
    int eta;
    float reddito;
    float altezza;
}persona;

int read_file(persona*);
void copy_array(persona*,persona);
void insertion_sort(persona[],int);
void print_array(persona[],int);

int main(){
	int n=0;
    persona arr[10];

    n=read_file(arr);
    print_array(arr,n);
    printf("\n");
    insertion_sort(arr,n);
    print_array(arr,n);
    system("pause");
    return 0;
}
int read_file(persona *arr){
	FILE*p=NULL;
	int i=0;
    p=fopen(PATH ,"r");
    if(p==NULL) printf("Errore\n");
    else{
    	while(!feof(p)){
            fscanf(p, "%d    %f  %f",&arr[i].eta,&arr[i].reddito,&arr[i].altezza);
    		i++;
    	}
    }
   return i;
}


void insertion_sort(persona p[],int n){
	void copy_array(persona*,persona);
    int i,j;
    persona key;

    for(i=1;i<n;i++){
        copy_array(&key,p[i]);
        j=i-1;
        while((j>=0) && ((p[j].eta>key.eta) || (p[j].eta==key.eta && p[j].reddito>key.reddito))){
            copy_array(&p[j+1],p[j]);
            j=j-1;
            }
        copy_array(&p[j+1],key);
        }
}

void copy_array(persona*struct1,persona struct2){
    *struct1=struct2;
}

void print_array(persona p[],int n){
    int i;
    printf("Eta    Reddito      Altezza\n");
    for(i=0;i<n;i++){
        printf("%d      %.2f    %.2f\n",p[i].eta,p[i].reddito,p[i].altezza);
    }
}

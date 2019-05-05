#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 15
#define MAXC 10
#define TETTO 500
#define PATH "D:\\C-workspace 2\\Lab cap 8 8_Banca\\archivio.txt"
#define WRITE "w"
#define APPEND "a"

typedef struct{
	int key;
	char nome[MAX];
	float saldo;
}conto_corrente;

int leggi_file(conto_corrente c[MAXC]){
	FILE *q;
    int i=0;
	if((q=fopen(PATH,"r"))==NULL)
		puts("Errore apertura\n");
	else{
		while(!feof(q)){
			fscanf(q,"%d %s %f\n",&c[i].key,c[i].nome,&c[i].saldo);
			i++;
		}
		fclose(q);
	}
	return i;
}

conto_corrente inserimento(){
	conto_corrente c;
	printf("Codice: ");
	scanf("%d",&c.key);
    printf("Nome: ");
	scanf("%s",c.nome);
	printf("Saldo disponibile: ");
	scanf("%f",&c.saldo);
	return c;
}

void scrivi_file(conto_corrente c,char TYPE[]){
	FILE *q;
	if((q=fopen(PATH,TYPE))==NULL)
		puts("Errore apertura");
	else
		fprintf(q,"%d %s %.2f\n",c.key,c.nome,c.saldo);
	fclose(q);
}

void stampa(conto_corrente c[],int dim){
	printf("%-10s%-10s%-10s\n","Codice","Nome","Saldo disp");
	for(int i=0;i<dim;i++){
		printf("%-10d%-10s%-10.2f\n",c[i].key,c[i].nome,c[i].saldo);
	}
}

void prelievo(conto_corrente c[],int dim,int search){
	int i;
	float prel;

	for(i=0;i<dim;i++){
		if(search==c[i].key){
			do{
				printf("Denaro da prelevare: ");
				scanf("%f",&prel);
				if(prel>TETTO)
					puts("Superato tetto massimo, riprovare\n");
				else
					if(c[i].saldo<prel)
						puts("Impossibile prelevare,denaro insufficiente\n");
			}while(prel>TETTO ||c[i].saldo<prel);

			c[i].saldo-=prel;
			scrivi_file(c[0],WRITE);
			for(i=1;i<dim;i++)
				scrivi_file(c[i],APPEND);
			}
		}
}

void accredito(conto_corrente c[],int dim,int search){
	int i;
	float accr;

	for(i=0;i<dim;i++){
		if(search==c[i].key){
			do{
				printf("Denaro da accreditare: ");
				scanf("%f",&accr);
				if(accr>TETTO)
					puts("Superato tetto massimo, riprovare\n");

			}while(accr>TETTO);

			c[i].saldo+=accr;
			scrivi_file(c[0],WRITE);
			for(i=1;i<dim;i++)
				scrivi_file(c[i],APPEND);
			}
		}
}

void info_conto(conto_corrente c[],int dim,int search){
	for(int i=0;i<dim;i++)
		if(search==c[i].key){
			printf("Codice: %d\n",c[i].key);
	    	printf("Nome:	%s\n",c[i].nome);
	    	printf("Saldo disponibile:	%f\n",c[i].saldo);
		}
}

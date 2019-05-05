#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 15
#define MAXC 10
#define TETTO 500
#define PATH "D:\\ec 2\\Lab cap 8_10_Es banca Ninny\\archivio.txt"

typedef struct{
	int key;
	char nome[MAX];
	float saldo;
}conto_corrente;

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
void scrivi_file(conto_corrente c,FILE* q){
	int i=0;
	if((q=fopen(PATH,"ab+"))==NULL) 	puts("Errore apertura");
	else{
		while(!feof(q)){
			fwrite(&c,sizeof(conto_corrente),1,q);
			i++;
		}
	}
	fclose(q);
}

void leggi_file(FILE* q,conto_corrente c[MAXC]){
    int i=0;
	if((q=fopen(PATH,"rb"))==NULL)	 puts("errore apertura");
	else{
	 printf("%-10s%-13s%s\n","Codice","Nome","Saldo disponibile");
	 while(!feof(q))
	 {
	  	fseek(q,i*sizeof(conto_corrente),SEEK_SET);
	  	fread(&c[i],sizeof(conto_corrente),1,q);
	  	if(!feof(q))
	  		printf("%-10d%-13s%.2f\n",c[i].key,c[i].nome,c[i].saldo);
	  	i++;
	 }
	 fclose(q);
	}
}

void prelievo(conto_corrente c[MAXC],int* search,FILE* q){
	int i=0,p;
	float prel;
	if((q=fopen(PATH,"rb+"))==NULL) puts("Errore apertura");
	else{
		while(!feof(q)){
			fseek(q,i*sizeof(conto_corrente),SEEK_SET);
			fread(&c[i],sizeof(conto_corrente),1,q);
			if(*search==c[i].key){
				printf("Denaro da prelevare: ");
				scanf("%f",&prel);
				if(prel>TETTO) puts("Prelievo non disponibile");
				else{
					if(c[i].saldo<prel) puts("Impossibile prelevare");
					else{
						p=i;
						c[i].saldo-=prel;
						fwrite(&c[p],sizeof(conto_corrente),1,q);
					}
			}
		}
		i++;
		}
		fclose(q);
	}
}

void accredito(conto_corrente c[MAXC],int* search,FILE* q){
	int i=0,p;
	float acc;
	if((q=fopen(PATH,"rb+"))==NULL) puts("Errore apertura");
	else{
		while(!feof(q)){
			fseek(q,i*sizeof(conto_corrente),SEEK_SET);
			fread(&c[i],sizeof(conto_corrente),1,q);
			if(*search==c[i].key){
				printf("Denaro da depositare: ");
				scanf("%f",&acc);
				p=i;
				c[i].saldo+=acc;
				fseek(q,i*sizeof(conto_corrente),SEEK_SET);
				fwrite(&c[p],sizeof(conto_corrente),1,q);
			}
			i++;
		}
		fclose(q);
	}
}

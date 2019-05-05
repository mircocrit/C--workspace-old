#define N 1
#define IBAN 28

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[10];
	char cognome[15];
	}titolare;

typedef struct{
	char iban[IBAN];
	titolare user;
	float saldo;
	}conto_banc;


conto_banc inserimento(){
	conto_banc archivio;
	printf("Nome e cognome utente\n ");
	scanf("%s %s",archivio.user.name,archivio.user.cognome);
	printf("Saldo:  ");
	scanf("%f",&archivio.saldo);
	printf("Iban:  ");
	scanf("%s",archivio.iban);
	return archivio;
}

void stampa(conto_banc archivio){
	printf("il nome e cognome dell'utente e' %s %s\n",archivio.user.name, archivio.user.cognome);
	printf("l'iban e': %s\n",archivio.iban);
	printf("il saldo e': %f\n",archivio.saldo);
}

void prelievo(conto_banc archivio[],int n,char search[]){
	float prel;
	int i;
		for(i=0;i<n;i++){
		if(strcmp(search,archivio[i].iban)==0){
			do{
				printf("Quanto denaro prelevare?");
				scanf("%f",&prel);
				if(prel<0) 		printf("Errore,digitare valore superiore a 0\n");
				else if(prel>archivio[i].saldo) 	printf("Il prelievo supera il saldo, riprovare\n");
			}while(prel>archivio[i].saldo && prel<0);
			archivio[i].saldo-=prel;
			printf("il saldo aggiornato e' %f\n", archivio[i].saldo);
			}
		}
}

void accredito(conto_banc archivio[],int n,char search[]){
	float accr;
	int i;
	for(i=0;i<n;i++){
		if(strcmp(search,archivio[i].iban)==0){
			do{
				printf("quanto denaro accreditare?");
				scanf("%f",&accr);
				if(accr<0)		 printf("Errore,digitare valore superiore a 0\n");
				else if(accr>10000)		 printf("Superato limite accreditabile di 10.000 euro\n");
			}while(accr<0 || accr>10000);
			archivio[i].saldo+=accr;
			printf("il saldo aggiornato e' %f\n", archivio[i].saldo);
			}
		}
	}

void stampa_iban(conto_banc archivio[],int n,char search[]){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(search,archivio[i].iban)==0)
			stampa(archivio[i]);
	}
}

/*
 Facendo uso di funzioni e procedure, scrivere un programma che permette di
 1) Caricare un vettore di conti correnti bancari da file: ogni conto e' descritto in termini di:
 	 numero del conto, titolare del conto, (una variabile di tipo persona) e del saldo;
 	 Aggingerne altri da tastiera;
 2) Stampare l'intero archivio
 3) Dato il numero di conto effettuare prelievo/accredito
 4) Dato il numero di conto stampare info conto
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"

#define TRUE 1
#define FALSE 0
#define MAX_CONTI 10
#define APPEND "a"

int main(){
	conto_corrente conto[MAX_CONTI],work;
	int scelta,chiudi=FALSE,flag=TRUE,dim=0;
	int ricerca;
	do{
		printf("0-Esci\n");
		printf("1-Lettura conti da file\n");
		printf("2-Aggiunta nuovo conto\n");
		printf("3-Prelievo denaro\n");
		printf("4-Accredito denaro\n");
		printf("5-Info conto\n");
		printf("Scelta: ");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=TRUE;
			    break;
			case 1:
				dim=leggi_file(conto);
				stampa(conto,dim);
				break;
			case 2:
			    do{
			        work=inserimento();
			        scrivi_file(work,APPEND);
			        printf("Continuare? si=1 no=0	");
			        scanf("%d",&flag);
				}while(flag==TRUE);
			    break;
			case 3:
				printf("Numero di conto: ");
				scanf("%d",&ricerca);
				prelievo(conto,dim,ricerca);
				break;
			case 4:
				printf("Numero di conto: ");
				scanf("%d",&ricerca);
				accredito(conto,dim,ricerca);
				break;
			case 5:
				printf("Numero di conto: ");
				scanf("%d",&ricerca);
				info_conto(conto,dim,ricerca);
				break;

		}
	}while(scelta>0 && scelta<6 && chiudi==FALSE);
	system("pause");
	return 0;
}

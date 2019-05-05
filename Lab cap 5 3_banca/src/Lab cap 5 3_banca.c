/*
 Facendo uso di funzioni e procedure, scrivere un programma che permette di
 1) Caricare un vettore di conti correnti bancari: ogni conto e' descritto in termini di:
 	 numero del conto, titolare del conto, (una variabile di tipo persona) e del saldo;
 2) Stampare l'intero archivio
 3) Dato il numero di conto effettuare prelievo/accredito
 4) Dato il numero di conto stampare info conto
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "banca.h"
#define N 1
#define IBAN 28 //l'iban ha 27 caratteri

int main() {
	char search[20];
	conto_banc archivio[N];
	int scelta,i=0, flag=0, chiudi=1;
	do{
		printf("Menu\n");
		printf("0 Esci\n");
		printf("1 Inserimento conti correnti\n");
		printf("2 Stampa intero archivio\n");
		printf("3 Prelievo da conto\n");
		printf("4 Accredito a conto\n");
		printf("5 Visualizzazione conto da iban\n");
		scanf("%d", &scelta);
		switch(scelta){
			case 0:
				chiudi=0;
				break;
			case 1:
				for(i=0;i<N;i++){
					archivio[i]=inserimento();
					flag=1;
				}
				break;
			case 2:
				if(i==0) printf("Inserire elementi");
				else
					for(i=0;i<N;i++)
						stampa(archivio[i]);
				break;
			case 3:
				if(flag==0)	 printf("Inserire prima i dati del conto");
				else{
					printf("Inserire l'iban del conto\n");
					scanf("%s",search);
					prelievo(archivio,N,search);
				}
				break;
			case 4:
				if(flag==0) printf("Inserire prima i dati del conto");
				else{
					printf("Inserire l'iban del conto\n");
					scanf("%s",search);
					accredito(archivio,N,search);
				}
				break;
			case 5:
				if(flag==0) printf("Inserire prima i dati del conto");
				else{
					printf("Inserire l'iban del conto\n");
					scanf("%s",search);
					stampa_iban(archivio,N,search);
				}
				break;
			}
	}while(scelta>=0 &&scelta <=5 && chiudi==1);
	system("pause");
	return 0;
	}

/*
Scrivere un progr che acquisisce e visualizzi i dati di una collezione di 5 studenti, ciascuno descritto da:
nome cognome data di nascita, voti esami
1) considerare casi limite per data di nascita e i voti esami
2) calcolare e visualizzare la media dei voti di esami per ciascun studente
3) visualizzare lo studente con media esami piu' alta
 */

#include <stdio.h>

#include <stdlib.h>
#include "studenti.h"
#define N_ESAMI 7
#define MAX 20
#define NUM_STUD 5

int main() {
	int i,scelta,chiudi=1;
	studente stud[NUM_STUD];
	int imax=0;
	do{
		printf("Menu\n");
		printf("0 Esci\n");
		printf("1 Inserimento studenti\n");
		printf("2 Stampa studenti\n");
		printf("3 Media voti studente\n");
		printf("4 Massima media voti fra studenti\n");
		printf("Scelta\n");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=0;
				break;
			case 1:
				for(i=0;i<NUM_STUD;i++)
					stud[i]=inserimento();
				break;
			case 2:
				printf("%-10s%-15s%-12s%-6s%-6s%-6s%-6s%-6s%-6s%-6s,%-6s\n","Nome","Cognome","Data di nasc","Arch","Discr","Progr","Lab","Ling","Analisi","Ingl","Media");
				for(i=0;i<NUM_STUD;i++){
					stampa(stud[i]);
				}
				break;
			case 3:
				media_voti(stud);
				printf("%-10s%-15s%-12s%-6s%-6s%-6s%-6s%-6s%-6s%-6s,%-6s\n","Nome","Cognome","Data di nasc","Arch","Discr","Progr","Lab","Ling","Analisi","Ingl","Media");
				for(i=0;i<NUM_STUD;i++){
					stampa(stud[i]);
					}
				break;
			case 4:
				imax=max_media(stud);
				printf("Studente con media piu alta: n. %d, media %f \n",imax+1,stud[imax].med);
				break;
			}
	}while(scelta>0 && scelta<5 && chiudi==1);
	system("pause");
	return 0;
}


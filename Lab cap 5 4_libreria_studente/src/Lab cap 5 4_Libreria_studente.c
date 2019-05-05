/*
 Scrivere la libreria studente che include gli operatori per la:
 1) verbalizzazione di un esame
 2) calcolo media esami
 3) calcolo voto max degli esami
 4) calcolo esami restanti
 Lo studente e' descritto da matricola, elenco esami del piano di studi,
 elenco esami sostenuti, elenco voti degli esami sostenuti; *=gia visti
 */

#include <stdio.h>
#include <stdlib.h>
#include "stud.h"
#define NUM_STUD 5

int main() {
	studente stud[NUM_STUD];
	int i,scelta,chiudi=1,voto=0;
	do{
			printf("Menu\n");
			printf("0-Esci\n");
			printf("1-Inserimento studenti\n");
			printf("2-Visual studenti\n");
			printf("3-Verbalizzazione voti\n");
			printf("4-Voto massimo studente\n");
			printf("5-Esami restanti\n");
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
					for(i=0;i<NUM_STUD;i++)
						stampa(stud[i]);
					break;
				case 3:
					 printf("Verbalizzazione esami\n");
					 for(i=0;i<NUM_STUD;i++)
						 stud[i]=verbalizzazione(stud[i]);
					break;
				case 4:
					for(i=0;i<NUM_STUD;i++){
						voto=max_voto(stud[i]);
						printf("Voto massimo %s %s: %d\n",stud[i].nome,stud[i].cognome,voto);
					}
						break;
				case 5:
					for(i=0;i<NUM_STUD;i++)
						esami_restanti(stud[i]);
					break;
			}
		}while(scelta>0 && scelta<7 && chiudi==1);
	system("pause");
	return 0;
}

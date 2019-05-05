/*prog in c che fornisca le seguenti funzonalita:
 1)acquisire sequenza di interi e memoriazzarla in 1 file
 2)ordinare sequenza in maniera crescente e memorizzare di un secondo file
 3)scrivere in un terzo file i valori maggiori di uno detto da un utente*/

#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#define MAX 20

int main() {
    int vett[MAX],n,search,scelta,esci=0;
    do{
		printf("Menu:\n");
		printf("1: Inserimento array\n");
		printf("2: Ordinamento crecente\n");
		printf("3: Valori maggiori di inserito\n");
		printf("4: Visualizzazione contenuto files\n");
		printf("Scelta:		");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				esci=1;
				break;
			case 1:
				n=acquisizione(vett);
				for(int i=0;i<n;i++)
					scrivi_file(vett[i],PATH1);
				break;
			case 2:
				insertion_sort(vett,n);
				for(int i=0;i<n;i++)
					scrivi_file(vett[i],PATH2);
				break;
			case 3:
				printf("Inserire da tastiera l'elemento di cui cercarne i maggiori\n");
				scanf("%d",&search);
				ricerca_magg(vett,n,search);
				break;
			case 4:
				printf("Stampa dei files\n");
				printf("File 1\n");
				leggi_file(PATH1);
				printf("File 2\n");
				leggi_file(PATH2);
				printf("File 3\n");
				leggi_file(PATH3);
				break;
			}
    }while(scelta>0 && scelta<5 && esci==0);
    system("pause");
    return 0;
}

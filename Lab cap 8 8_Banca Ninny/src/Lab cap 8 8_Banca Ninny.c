//es banca con i files
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "function.h"

#define TRUE 1
#define FALSE 0
#define MAXC 10

int main(){
	FILE* p;
	conto_corrente conto[MAXC];
	conto_corrente prova;
	int scelta,chiudi=FALSE,risp,count=0,ricerca,i;
	do{
		puts("0-Esci");
		puts("1-Inserimento conto corrente");
		puts("2-Prelievo denaro");
		puts("3-Accredito denaro");
		puts("4-Visualizza archivio");
		printf("scelta: ");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=TRUE;
			    break;
			case 1:
			    do{
			        prova=inserimento();
			        count++;
			        i++;
			        printf("Done (1-si/0-no) ");
			        scanf("%d",&risp);
			        puts("");
				}while(risp==FALSE);
				scrivi_file(prova,p);
			    break;
			case 2:
				printf("Inserire il codice da cercare: ");
			    scanf("%d",&ricerca);
			    prelievo(conto,&ricerca,p);
				break;
			case 3:
				printf("Inserire il codice da cercare: ");
			    scanf("%d",&ricerca);
			    accredito(conto,&ricerca,p);
			    break;
			case 4:
				leggi_file(p,conto);
			    puts("");
			    break;
		}
	}while(scelta>0 && scelta<5 && chiudi==FALSE);
	system("pause");
	return 0;
}

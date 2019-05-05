//Calcolare quanti giorni sono passati dal 1 gennaio al giorno inserito

#include <stdio.h>
#include <stdlib.h>
#include "anno.h"

int main(){
	data d;
	int r;
	do{
		d=inserimento_data();
		printf("I giorni trascorsi dall'1 Gennaio sono: %d.", elabora_dati(d));
		printf("Vuoi ripetere? (s=1/n=0)\n");
		scanf("%d",&r);
	}while(r==1);
	system("pause");
	return 0;
}

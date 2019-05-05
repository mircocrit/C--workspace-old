/* Facendo uso di funzioni, scrivere un programma che,usando una matrice,
 1) acquisisca le calorie assunte in una settimana da un insieme di 5 individui
 2) ne identifica il massimo per individuo e complessivo
 3) ne calcoli la media per individuo e comlessiva
 4) ne identifichi il giorno in cui vi e' il massimo per individuo e il massimo complessivo
 */
#include <stdio.h>
#include <stdlib.h>
#include "calorie.h"

int main(){
	int pers=5,scelta,chiudi=1,max_compl;
	float cal[pers][7];
	do{
		printf("Menu\n");
		printf("0 Esci\n");
		printf("1 Inserimento calorie assunte dagli individui\n");
		printf("2 Visualizzazione massimo individuale e complessivo delle calorie\n");
		printf("3 Visualizzazione media per individuo e comlessiva delle calorie\n");
		printf("4 Visualizzazione del giorno in cui vi e' il massimo per individuo e il massimo complessivo delle calorie\n");
		printf("5 Visualizzazione calorie assunte da individui\n");
		printf("Inserire scelta\n");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=0;
				break;
			case 1:
				printf("Quanti individui inserire?\n");
				scanf("%d",&pers);
				inserimento(cal,pers);
				break;
			case 2:
				max_compl=calcola_max(cal,pers);
				break;
			case 3:
				calcola_med(cal,pers);
				break;
			case 4:
				giorno_max(cal,pers,max_compl);
				break;
			case 5:
				stampa(cal,pers);
				break;
			}
	}while(scelta>0 && scelta<4 && chiudi==1);
	system("pause");
	return 0;
}

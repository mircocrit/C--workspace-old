/*
Riscrivere la libreria mate che include gli operatori per il calcolo del
1) minimo tra 2 interi
2) massimo tra 2 interi
3) media tra 2 interi
4) val assoluto di un numero,
in modo che gli operatori lavorino su argomenti ottennuti tramite passaggio per riferimento
il risultato di ogni calcolo sia consegnato usando il passaggio di valore per riferimento
 */

#include <stdio.h>
#include <stdlib.h>

#include "mat.h"

int main() {
	int scelta,chiudi=1;
	int a,b,max,min,ass;
	float med;
	do{
		printf("Menu\n");
		printf("0 Esci\n");
		printf("1 Inserimento\n");
		printf("2 Calcola max\n");
		printf("3 Calcola min\n");
		printf("4 Media \n");
		printf("5 Val assoluto\n");
		printf("inserire scelta\n");
		scanf("%d",&scelta);
		switch(scelta){
			case 0:
				chiudi=0;
				break;
			case 1:
				printf("inserire valore di a:	");
				scanf("%d",&a);
				printf("inserire valore di b:	");
				scanf("%d",&b);
				break;
			case 2:
				calcola_max(&a,&b,&max);
				printf("il val max di a e b e' %d\n",max);
				break;
			case 3:
				calcola_min(&a,&b,&min);
				printf("il val min di a e b e' %d\n",min);
				break;
			case 4:
				calcola_med(&a,&b,&med);
				printf("il val med di a e b e' %f\n",med);
				break;
			case 5:
				val_ass(&a,&ass);
				printf("il val ssoluti di a e' %d\n",ass);
				break;
				}
		}while(scelta>0 && scelta<6 && chiudi==1);
	system("pause");
	return 0;
}

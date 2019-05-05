#include <stdio.h>
#include <stdlib.h>

char *giorni[7]={"Lunedi","Martedi","Mercoledi","Giovedi","Venerdi","Sabato","Domenica"};

void inserimento(float cal[][7],int pers){
	int i,j;
	for(i=0;i<pers;i++){
		for(j=0;j<7;j++){
			printf("Calorie %s:	 ", giorni[j]);
			scanf("%f", &cal[i][j]);
		}
		printf("\n");
	}
}

void stampa(float cal[][7],int pers){
	int i,j;
	for(i=0;i<pers;i++){
		for(j=0;j<7;j++)
			printf("le calorie accumulate della persona n%d nel giorno %d sono %.2f\n",i+1,j+1,cal[i][j]);
		printf("\n");
	}
}

int calcola_max(float cal[][7],int pers){
	int i,j;
	float max,max_compl=0;
	for(i=0;i<pers;i++){
		max=cal[i][0];
		for(j=1;j<7;j++){
			if(cal[i][j]>cal[i][j-1])	 max=cal[i][j];
		}
		printf("il massimo individuale e'%f\n",max);
		if(max>max_compl) max_compl=max;
	}
	printf("il max complessivo e' %f",max_compl);
	return max_compl;
}

void calcola_med(float cal[][7],int pers){
	int i,j;
	float sum_compl,sum_ind=0;
	for(i=0;i<pers;i++){
		sum_ind=0;
		for(j=0;j<7;j++){
			sum_ind+=cal[i][j];
		}
		printf("la media individuale per l'individuo %d e' %f\n",i+1,sum_ind/7);
		sum_compl+=sum_ind;
	}
	printf("\n");
	printf("La media complessiva vale %f\n", sum_compl/=(pers*7));
}

void giorno_max(float cal[][7],int pers,int max_compl){
	int i,j;
	for(i=0;i<pers;i++){
		for(j=0;j<7;j++){
			if(cal[i][j]==max_compl)
				printf("il valore massimo assoluto di calorie e'stato assunto il giorno num %d dall'individuo %d\n",j+1,i+1);
		}
	}
}

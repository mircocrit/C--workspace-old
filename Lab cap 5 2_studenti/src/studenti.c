#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define N_ESAMI 7
#define MAX_CHAR 20
#define NUM_STUD 5

char esame[N_ESAMI][MAX_CHAR]={"Architettura","Matematica","Programmazone","Laboratorio","Analisi","Inglese","Linguaggi"};

typedef struct{
	int giorno;
	int mese;
	int anno;
	}data;

typedef struct{
	char nome[MAX_CHAR];
	char cognome[MAX_CHAR];
	int voto[N_ESAMI];
	data date;
	float med;
}studente;

studente inserimento(){
	data controlla_data();
	studente stud;
	int j;
	printf("Nome e Cognome:		");
	scanf("%s %s",stud.nome,stud.cognome);

	printf("Voti:\n");
	for(j=0;j<N_ESAMI;j++){
		do{
			printf("Voto %s: ",esame[j]);
			scanf("%d",&stud.voto[j]);
			if(stud.voto[j]<0 || stud.voto[j]>30)  printf("Errore\n");
			}while(stud.voto[j]<0 || stud.voto[j]>30);
		};
	stud.date=controllo_data();
	return stud;
}


data controlla_data(){
	data date;
	printf("Data di nascita:\n");
	printf("Anno: ");
	do{
		scanf("%d",&date.anno);
		if(date.anno<1900 || date.anno>2018) 	printf("Errore\n");
	}while(date.anno<1900 || date.anno>2018);

		printf("Mese: ");
		do{
			scanf("%d",&date.mese);
			if(date.mese<1 || date.mese>12)  printf("Errore\n");
		}while(date.mese<1 || date.mese>12);

		printf("Giorno: ");
		do{
		scanf("%d",&date.giorno);
		if(date.giorno<1 || date.giorno>31)	printf("Errore\n");
			else

			switch(date.giorno){
				case 31:		//mesi con 31 giorni: gennaio1,marzo3,maggio5,luglio7,agosto8,ottobre10,dicembre12
					if(date.mese==4||date.mese==6||date.mese==9||date.mese==11||date.mese==2){
						printf("Errore\n");
					}
						break;
				case 30:		//mesi con 30 giorni: aprile4 giugno6 settembre9,novembre11;
					if(date.mese==2)	printf("Errore\n");
						break;
				case 29:			//febbraio 28/29 giorni
					if(date.mese==2 && !((date.anno%4==0 && date.anno%100!=0) || date.anno%400==0)){
						printf("Errore\n");
					}
						break;
				}
		}while(date.giorno<1 || date.giorno>31);

	return date;
}

void stampa(studente stud){
	int j;
	printf("%-10s%-15s%-12s%-6s%-6s%-6s%-6s%-6s%-6s%-6s\n","Nome","Cognome","Data di nasc","Arch","Discr","Progr","Lab","Ling","Analisi","Ingl");
	printf("%-10s%-15s%-3d%-3d%-6d",stud.nome,stud.cognome,stud.date.giorno,stud.date.mese, stud.date.anno);
	for(j=0;j<N_ESAMI;j++)
		printf("%-6d",stud.voto[j]);
	printf("%-6.2f",stud.med);
	printf("\n");
}

void media_voti(studente stud[]){
	int i,j;
	float med=0;
	for(i=0;i<NUM_STUD;i++){
		for(j=0;j<N_ESAMI;j++){
			med+=stud[i].voto[j];
		}
		stud[i].med=med/N_ESAMI;
	}
}

int max_media(studente stud[], int num_stud){
	int i,imax=0;
	for(i=0;i<num_stud;i++){
		if(stud[i].med>stud[imax].med)
			imax=i;
		}
	return imax;
}

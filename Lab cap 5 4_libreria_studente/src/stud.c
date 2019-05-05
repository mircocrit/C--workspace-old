#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N_ESAMI 7
#define MAX_CHAR 18
#define NUM_STUD 5

char esame[N_ESAMI][MAX_CHAR]={"Architettura","Matematica","Programmazone","Laboratorio","Analisi","Inglese","Linguaggi"};

typedef struct{
	char esame[MAX_CHAR];
	int sostenuto;
	int voto;
}exam;

typedef struct{
	char nome[MAX_CHAR];
	char cognome[MAX_CHAR];
	int matricola;
	exam esami[N_ESAMI];
	float media;
	}studente;

studente inserimento(){
	studente stud;
	int j;
	printf("Nome e cognome studente\n");
	scanf("%s %s",stud.nome,stud.cognome);
	printf("Matricola studente\n");
	scanf("%d",&stud.matricola);
	for(j=0;j<N_ESAMI;j++){
		strcpy(stud.esami[j].esame,esame[j]);
		stud.esami[j].sostenuto=0;
		stud.esami[j].voto=0;
		}
	stud.media=0;
	printf("\n");
	return stud;
}

void stampa(studente stud){
	int j;
	printf("%-10s,%-15s,%-10s","Nome","Cognome","Matricola");
	for(int i=0;i<N_ESAMI;i++)
		printf("%-6s",esame[i]);
	printf("%-6s\n","Media");
	printf("%-10s,%-15s%-10d", stud.nome,stud.cognome,stud.matricola);
	for(j=0;j<N_ESAMI;j++)
		if(stud.esami[j].sostenuto==1)
			printf("%-6d",stud.esami[j].voto);
		else printf("%-6s","NO");
	printf("%-6d\n",stud.media);
	printf("\n");
}

 studente verbalizzazione(studente stud){
	float media_esami(studente);
	int j;
	for(j=0;j<N_ESAMI;j++){
		printf("L'esame di %s e' stato sostenuto? (0=no, 1=si) \n",stud.esami[j].esame);
		scanf("%d",&stud.esami[j].sostenuto);
		if(stud.esami[j].sostenuto==1){
			printf("Voto esame %s:		",stud.esami[j].esame);
			scanf("%d",&stud.esami[j].voto);
			if(stud.esami[j].voto<18){
				printf("Esame non convalidabile\n");
				stud.esami[j].voto=0;
				stud.esami[j].sostenuto=0;
				}
			else
				printf("Esame convalidato\n");
			}
		}
	stud.media=media_esami(stud);
	return stud;
}

float media_esami(studente stud){
	float med=0;
	int j,i=0;
	for(j=0;j<N_ESAMI;j++)
		if(stud.esami[j].sostenuto==1){
			med+=stud.esami[j].voto;
			i++;
		 }
	 med/=i;
	 return med;
}

int max_voto(studente stud){
	int j;
	int max_voto=0;
 	for(j=0;j<N_ESAMI;j++){
 		if(stud.esami[j].voto>max_voto){
 			max_voto=stud.esami[j].voto;
 		}
 	}
 	return max_voto;
 }

 void esami_restanti(studente stud){
	 int j;
	 printf("Lo studente deve sostenere gli esami di:\n");
	 for(j=0;j<N_ESAMI;j++)
	 	if(stud.esami[j].sostenuto==0)
	 		("%s ",stud.esami[j].esame);
 }

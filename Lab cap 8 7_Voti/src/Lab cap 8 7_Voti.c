/* Implementare un programma che acquisisca da tastira nome(o matricola)  e voto d'esame per 5 individui e li scriva su file.
 il programma deve poi leggere il file dall'inizio e stampare a schemro i nomi degli studenti che hanno superato l'esame.
 */

#include <stdio.h>
#include <stdlib.h>

#define PATH "D:\\C-workspace 2\\Lab cap 8 7_Voti\\votistud.txt"
#define MAX_CHAR 25
#define MAX_STUD 25

typedef struct{
	char nome[MAX_CHAR];
	int voto;
}studente;

void leggi_tastiera(studente[],int);
int leggi_file(studente[]);
void scrivi_file(studente[],int);
void visual_stud(studente[],int);
void esame_superato(studente[],int);

int main(){
	int dim;
	studente s[MAX_STUD];
	leggi_tastiera(s,5);
	scrivi_file(s,5);
	dim=leggi_file(s);
	visual_stud(s,dim);
	esame_superato(s,dim);
	system("pause");
	return 0;
}

void leggi_tastiera(studente s[],int dim){
	int i;
	for(i=0;i<dim;i++){
		printf("Nome studente:	");
		scanf("%s",s[i].nome);
		do{
			printf("Voto:	");
			scanf("%d",&s[i].voto);
			if(s[i].voto<1 || s[i].voto>30)
				printf("Errore, voto deve essere fra 0 e 30!\n");
		}while(s[i].voto<1 || s[i].voto>30);
	}
}

int leggi_file(studente s[]){
	int i=0;
	FILE *fp;
	if((fp=fopen(PATH,"r"))==NULL)
			puts("Errore di apertura\n");
		else{
			while(!feof(fp)){
				fscanf(fp,"%s %d",s[i].nome,&s[i].voto);
			i++;
			}
		}
	return i-1;
}

void scrivi_file(studente s[],int dim){
	int i=0;
	FILE *fp;
	if((fp=fopen(PATH,"w"))==NULL)
		puts("Errore di apertura\n");
	else{
		for(i=0;i<dim;i++)
			fprintf(fp,"%s %d\n",s[i].nome,s[i].voto);
		}
	fclose(fp);
}

void visual_stud(studente s[],int dim){
	int i;
	printf("Nome		Voto\n");
	for(i=0;i<dim;i++){
		printf("%s		%d\n",s[i].nome,s[i].voto);
	}
}

void esame_superato(studente s[],int dim){
	for(int i=0;i<dim;i++)
		if(s[i].voto>18)
			printf("Lo studente %s ha superato l'esame\n",s[i].nome);
		else
			printf("Lo studente %s non ha superato l'esame\n",s[i].nome);
}

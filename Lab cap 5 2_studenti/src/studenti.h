#ifndef STUDENTI_H_
#define STUDENTI_H_

#include <stdio.h>
#include <stdlib.h>
#define num_voti 7
#define MAX 20
#define N_ESAMI 7
#define MAX_CHAR 15
#define NUM_STUD 5

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

studente inserimento();
data controlla_data();
void stampa(studente);
void media_voti(studente[]);
int max_media(studente[]);


#endif /* STUDENTI_H_ */

#ifndef STUD_H_
#define STUD_H_
#define max 8

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char esame[15];
	int sost;
	int voto;
}exam;

typedef struct{
	char nome[15];
	char cognome[15];
	int matricola;
	exam esami[max];
	}studente;

studente inserimento();
void stampa(studente);
studente verbalizzazione(studente);
float media_esami(studente);
int max_voto(studente);
void esami_restanti(studente);

#endif /* STUD_H_ */

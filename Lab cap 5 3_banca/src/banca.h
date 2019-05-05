#ifndef BANCA_H_
#define BANCA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1
#define IBAN 28

typedef struct{
	char name[10];
	char cognome[15];
	}titolare;

typedef struct{
	char iban[IBAN];
	titolare user;
	float saldo;
	}conto_banc;

conto_banc inserimento();
void stampa(conto_banc);
void prelievo(conto_banc[],int,char[]);
void accredito(conto_banc[],int,char[]);
void stampa_iban(conto_banc[],int,char[]);

#endif /* BANCA_H_ */

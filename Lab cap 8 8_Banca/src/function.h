#ifndef FUNCTION_H_
#define FUNCTION_H_

#include<stdio.h>

#define MAX 15

typedef struct{
	int key;
	char nome[MAX];
	float saldo;
}conto_corrente;

int leggi_file();
void stampa(conto_corrente[],int);
conto_corrente inserimento();
void scrivi_file(conto_corrente,char[]);
void prelievo(conto_corrente[],int,int);
void accredito(conto_corrente[],int,int);
void info_conto(conto_corrente[],int,int);

#endif /* FUNCTION_H_ */

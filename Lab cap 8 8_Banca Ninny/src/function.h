#ifndef FUNCTION_H_
#define FUNCTION_H_

#include<stdio.h>
#define MAX 15
typedef struct{
	int key;
	char nome[MAX];
	float saldo;
}conto_corrente;

conto_corrente inserimento(void);
void scrivi_file(conto_corrente,FILE*);
void leggi_file(FILE*,conto_corrente[]);
void prelievo(conto_corrente[],int*,FILE*);
void accredito(conto_corrente[],int*,FILE*);

#endif /* FUNCTION_H_ */

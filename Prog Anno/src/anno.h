#ifndef ANNO_H_
#define ANNO_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int giorno;
	int mese;
	int anno;
}data;

data inserimento_data();
int controllo_giorno(int,int,int);
int elabora_dati(data);

#endif /* ANNO_H_ */

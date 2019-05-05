/*
Semaforo binario: semaforo il cui valore intero può essere solo 0 o 1 Gestione più complessa che non con semafori contatore
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct {
	boolean val;
	struct processo *P; //lista dei processi in coda
}semaforo_bin;

int main(v) {

	return 0;
}

void wait(semaforo_bin s) {
	if (s.val==1)	  s.val=0;
	else{
		<poni processo in coda a P>
		<blocca questo processo: running->blocked >
			}
}

void signal (semaforo_bin s) {
	if(*P==NULL)  s.val=1; //coda vuota
	else{
		<rimuovi un processo in coda>
		<sveglia il processo: blocked->ready >
	}
}

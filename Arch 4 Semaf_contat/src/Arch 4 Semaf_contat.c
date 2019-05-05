/*
 ============================================================================
 SEMAFORO: variabile (intera) sulla quale sono possibili 3 operazioni:
1. Inizializzazione ad un valore non negativo
2. Operazione atomica wait(): decrementa il valore della variabile. Se il valore della variabile diventa negativa, il processo che ha eseguito la wait viene bloccato.
3. Operazione atomica signal(): incrementa il valore della variabile. Se il valore della variabile è negativo, uno dei processi bloccati sull’operazione di wait viene sbloccato
 • Si associa un semaforo ad ogni risorsa condivisa
• Il processo che vuole utilizzare la risorsa effettua
una operazione di wait
• Il processo che rilascia la risorsa effettua il signal
• La variabile numerica indica il numero di istanze di
una specifica risorsa condivisa (semaforo contatore)
• Se la variabile è negativa, essa rappresenta (presa
in valore assoluto) il numero di processi in attesa
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int istanze;
	struct processo *P; //lista dei processi in coda
	}semaforo;

int main(void) {
	wait (S);
	<Critical Section>
	signal (S);
	return 0;
}

void wait(semaforo s){
	s.istanze--;
	if(s.istanze<0){
		<poni processo in coda>
		<blocca questo processo: running->blocked >
		}
}

void signal(semaforo s){
     s.istanze++;
     if(s.istanze<=0){
		<rimuovi un processo in coda>
		<sveglia il processo: blocked->ready>
     }
}

/*
 ============================================================================
Utilizzo di test&set per garantire la mutua esclusione
sia lock una variabile boolean condivisa inizializzata a falso (la risorsa è libera).
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
	while (true) {
	while ( TestAndSet (&lock )) ;
			// do nothing
	<critical section>
	lock = FALSE; //rilascio
	//...
	}
	return 0;
}

boolean TestAndSet (boolean *target){
   boolean val = *target;
   *target = TRUE;
   return val;
}

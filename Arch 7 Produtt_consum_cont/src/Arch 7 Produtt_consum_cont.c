/*
 ============================================================================
produttore
	<produce dato>
	buffer[in]=dato;
	in++;

consumatore
   while(in >= out){
   	   w = buffer[out];
   	   out++;
   	   <consuma w>
}
 ============================================================================*/
/*program producer consumer */

#include <stdio.h>
#include <stdlib.h>

int n;
semaphore n=0; //gestisce il caso di nessun elemento nel buffer
semaphore s=1; //gestisce l'accesso al buffer

int main() {
	parbegin(producer,consumer);
	return 0;
}

void producer(){
	while(true){
		produce();
		semWait(s);
		append();
		semSignal(s);
		semSignal(n);
	}
}

void consumer(){
	while(true){
		semWait(n);
		semWait(s);
		take();
		semSignal(s);
		consume();
	}
}

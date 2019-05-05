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
binary semaphore s=1; //gestisce l'accesso al buffer
binary semaphore delay=0; //gestisce il caso di nessun elemento nel buffer

int main() {
	n=0;
	parbegin(producer,consumer);
	return 0;
}

void producer(){
	while(true){
		produce();
		semWaitB(s);
		append();
		n++;
		if(n==1)		semSignalB(delay);
		semSignalB(s);
	}
}

void consumer(){
	int m;//var locale
	semWaitB(delay);
	while(true){
		semWaitB(s);
		take();
		n--;
		m=n;
		semSignalB(s);
		consume();
		if(m==0)		semWaitB(delay);
	}
}

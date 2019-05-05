/*
 ============================================================================
Istanze multiple per le risorse.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct state{
	int resources[m]; //stato del sistema
	int available[m];
	int claim[n][m];
	int alloc[n][m];

};
int main() {//resource alloc algorithm
	if(alloc[i,*]+request[*]>claim[i,*])		<error>;	//total request>claim,Si verifica che la somma tra le risorse attualmente assegnate e richieste non superi la dichiarazione iniziale
	else	 if(request[*]>available[*])		<suspend process>;//Se non ci sono risorse sufficienti, il proceso viene sospeso
	else{
		<define newstate by://Si definisce il nuovo stato ipotizzando di assegnare le risorse al processo richiedente
		alloc[i,*]=alloc[i,*]+request[*];
		available[*]=available[*]-request[*]; >
	}
	if(safe(newstate))	<carry out allocation>;//Si verifica se il nuovo stato è sicuro
	else {
		<restore original state>;
		<suspend process>;
	}

	return 0;
}

boolean safe(state S){ //test for safety algorithm (banker's algorithm)
	int currentvail[m];
	process rest[<number of processes>];
	currentvail=available;
	rest={all processes};
	possible=true;
	while(possible){
	//<find a process Pk in rest such that:
		claim[k,*]-alloc[k,*] <=currentvail; //>
		if(found){ //simulate execution of Pk
			currentvail=currentvail+alloc[k,*];
			rest=rest-{Pk};
		}else	possible=false;
		}
	return(rest==null);
}

/*
 ============================================================================
Ogni processo ha una propria variabile flag che indica se vuole andare nella sezione critica o meno
Variabile turno specifica chi ha il diritto di insistere nel tentativo di entrare nella propria sezione critica.
Es.:
P0 vuole entrare (pone il suo flag a true) P0 controlla il flag di P1
se falso entra nella sezione critica se vero controlla il turno
Ogni processo ha una propria variabile flag che indica se vuole andare nella sezione critica o meno
Variabile turno specifica chi ha il diritto di insistere nel tentativo di entrare nella propria sezione critica
se turno è 0 (il suo) continua a controllare periodicamente il flag di P1 se turno è 1 pone il suo flag a falso lasciando il passo a P1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
boolean flag[2];
int turno;
void main() {
	Flag[0]=false;
	flag[1]=false;
	turno=1; //turno=0;
	//...
	processo P0; processo P1;
	//...
	}

	processo P0 {
	//...
		flag[0]=true;
		while(flag[1]) {
			if (turno==1) {
				flag[0]=false;
				while(turno==1)
				 	 {<nulla...ATTESA ATTIVA>}
				flag[0]=true;
			}
		}
	<sezione critica>
	flag[0]=false;
}

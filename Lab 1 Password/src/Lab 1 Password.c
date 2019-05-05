/*
 1)acquisire informazioni immesse da tastiera relative a 5 utenti, caratterizzati da nome,cognome,indirizzo,password.
 2)calcolo sicurezza password ,eseguito come segue:
	 Password poco sicura, numero di caratteri numerici e punteggiatura <=2
	 Password medio sicura,numero di caratteri numerici e punteggiatura <=4 e >2
	 Password sicura numero di caratteri numerici e punteggiatura
 3)scrivere su file e su righe consecutive la stringa "password"+"livello" composta da password immessa da ciascun utente e livello associato  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funzioni.h"

#define NUM_UTENTI 10

int main() {
    int i,flag=0,scelta,n=0,level=0;
    utente u[NUM_UTENTI];
    do{
        printf("Menu\n");
        printf("0-Esci\n");
        printf("1-Lettura da file\n");
        printf("2-Visualizzazione utenti\n");
        printf("3-Calcolo livello protezione\n");
        printf("4-Scrittura password + livello\n");
        printf("Scelta\n");
        scanf("%d",&scelta);
        switch(scelta){
            case 0:
                flag=1;
                break;
            case 1:
            	n=lettura_file(u);
            	break;
            case 2:
            	printf("%-12s%-12s%-15s%-12s%-5s\n","Nome","Cognome","Indirizzo","Password","Protezione");
            	for(i=0;i<n;i++)
            		visual_utente(u[i]);
                break;
            case 3:
            	for(i=0;i<n;i++){
            		level=controllo_psw(u[i]);
            		scrivi_livello(&u[i],level);
            	}
				break;
            case 4:
            	for(i=0;i<n;i++)
            		scrittura_file(u[i]);
                break;
        	}
    	}while(scelta>0 && scelta<5 && flag==0);
    system("pause");
    return 0;
}

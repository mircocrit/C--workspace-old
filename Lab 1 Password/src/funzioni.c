#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30
#define NUM_UTENTI 10
#define PATH1 "D:\\C-workspace old\\Lab 1 Password\\archivio.txt"
#define PATH2 "D:\\C-workspace old\\Lab 1 Password\\lvl+psw.txt"
#define LOW 0
#define MEDIUM 1
#define HIGH 2

typedef struct{
    char nome[MAX];
    char cognome[MAX];
    char email[MAX];
    char password[MAX];
    char level[MAX];
}utente;

int lettura_file(utente u[]){
	int controllo_psw(utente);
	void scrivi_livello(utente*,int);
	FILE *p;
    int i=0,level=0;

    if((p=fopen(PATH1,"r"))==NULL) 	printf("Errore apertura");
    else{
        printf("File aperto\n");
        while(!feof(p)){
        	fscanf(p,"%s %s %s %s",u[i].nome,u[i].cognome,u[i].email,u[i].password);
        	level=controllo_psw(u[i]);
        	scrivi_livello(&u[i],level);
            i++;
        }
        fclose(p);
    }
    return i;
}

void visual_utente(utente u){
	printf("%-12s%-12s%-15s%-12s%-5s\n",u.nome,u.cognome,u.email,u.password,u.level);
}

int controllo_psw(utente u){
    int digit=0,alpha=0,j;
    int level=0;
    for(j=0;j<strlen(u.password);j++){
        if((isdigit(u.password[j]))==0) 		digit++;
        else if((isalpha(u.password[j]))==0)	alpha++;
    }

    if(digit+alpha<2)           level=LOW;
    else if (digit+alpha<4)     level=MEDIUM;
    else    					level=HIGH;
    return level;
}

void scrivi_livello(utente* u,int level){
    switch(level){
    	case LOW:
    		strcpy(u->level, "Basso");
            break;
        case MEDIUM:
            strcpy(u->level, "Medio");
            break;
        case HIGH:
            strcpy(u->level, "Alto");
            break;
         }
 }

void scrittura_file(utente u){
	FILE* p;
    if((p=fopen(PATH2,"a"))==NULL)	    printf("Errore apertura");
    else
    	fprintf(p,"%s %s %s\n",u.nome,u.password,u.level);
    fclose(p);
}

#ifndef funzioni_h
#define funzioni_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

typedef struct{
    char nome[MAX];
    char cognome[MAX];
    char email[MAX];
    char password[MAX];
    char level[MAX];
}utente;

int lettura_file(utente[]);
void visual_utente(utente);
int controllo_psw(utente);
void scrivi_livello(utente*,int);
void scrittura_file(utente);

#endif

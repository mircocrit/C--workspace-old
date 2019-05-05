/*
 * GestioneCaratteri.c
 *
 *  Created on: 08/dic/2009
 *      Author: Acer
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LUNG 20

int
main()
{

     char stringa[LUNG]= "Studente Matr.33965";
     char ch;
     if (isalpha(stringa[0]))
        printf("\nIl carattere --> %c e' un carattere alfabetico", stringa[0]);
     if (isdigit(stringa[14]))
        printf("\nIl carattere --> %c e' un numero", stringa[14]);
     if (islower(stringa[10]))
        printf("\nIl carattere --> %c e' un carattere minuscolo", stringa[10]);
     ch=toupper(stringa[10]);
     printf("\nIl carattere  e' trasformato in maiuscolo --> %c", ch);
     if (isupper(stringa[9]))
        printf("\nIl carattere --> %c e' un carattere MAIUSCOLO", stringa[9]);
     ch=tolower(stringa[9]);
     printf("\nIl carattere  e' trasformato in minuscolo --> %c", ch);
     if (ispunct(stringa[13]))
        printf("\nIl carattere --> %c e' un carattere di punteggiatura", stringa[13]);
    if (isspace(stringa[8]))
        printf("\nIl carattere --> %c e' uno spazio\n", stringa[8]);

     system("pause");
     return 0;
}

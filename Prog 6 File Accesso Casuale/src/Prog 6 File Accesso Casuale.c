/*
 * File Accesso Casuale.c
 *
 *  Created on: 15/dic/2009
 *      Author: Acer
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
        char cognome[10];
        char nome[10];
        char matricola[10];
        char corso_di_laurea[20];
}studente_t;



int
main ()
{
        FILE *primo_file;
		studente_t stud ={"","","",""};
		char risp;

        primo_file=fopen("Studenti.txt", "w+");
        printf("Il programma memorizza in un file Studenti.txt le informazioni di un elenco di studenti \n\n");
        if (primo_file==NULL)
             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
        else
        {
          do
        {
        	  printf("\nInserisci i dati dello studente (cognome, nome, matricola, corso di laurea): \n");
        	  scanf("%s%s%s%s", stud.cognome, stud.nome, stud.matricola, stud.corso_di_laurea );
        	  fwrite(&stud, sizeof(studente_t), 1, primo_file);
        	  printf("\nVuoi Continuare? (s/n)");
        	  scanf("\n%c", &risp);
          }while ((risp=='s') || (risp=='S'));


           printf("***************Inserimento Terminato******************\n\n");
          fclose(primo_file);
        }

        system("pause");
        return(0);

}

/*
 * File Accesso Casuale Lettura.c
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


        primo_file=fopen("Studenti.txt", "r");
        printf("Il programma legge un file Studenti.txt le informazioni di un elenco di studenti \n\n");
        if (primo_file==NULL)
             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
        else
        {
        	  printf(" %-10s %-10s %-10s %-10s\n\n", "Cognome", "Nome", "Matricola", "Corso di Laurea");
        	  fread(&stud, sizeof(studente_t), 1, primo_file);
        	  while (!feof(primo_file))
        	  {
        		 printf(" %-10s %-10s %-10s %-10s\n\n", stud.cognome, stud.nome, stud.matricola, stud.corso_di_laurea );
        		 fread(&stud, sizeof(studente_t), 1, primo_file);
        	  }
           printf("***************File Terminato******************\n\n");
          fclose(primo_file);
        }

        system("pause");
        return(0);

}

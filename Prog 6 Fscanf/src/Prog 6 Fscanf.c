/*
 * Fscanf.c
 *
 *  Created on: 15/dic/2009
 *      Author: Acer
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Programma di esempio di creazione e scrittura di un file utilizzando la fprintf. Il programma richiede all'utente di
immettere una lista di insegnamenti e votazioni riportate. */
int
main ()
{
        FILE *primo_file;
        char insegnamento[60];
        int voto;
        primo_file=fopen("Esami.txt", "r");
         printf("Il programma memorizza in un file Esami.txt le votazioni riportate \n da un singolo studente nei vari insegnamenti\n\n");
        if (primo_file==NULL)
             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
        else
        {
          printf(" %-20s %-6s\n\n", "Insegnamento", "Voto");
          fscanf(primo_file,"%s%d", insegnamento, &voto);
           while (!feof (primo_file))
           {
        	   printf(" %-20s %d\n\n", insegnamento, voto);
        	   fscanf(primo_file,"%s %d", insegnamento, &voto);
           }
           printf("***************File Terminato******************\n\n");
          fclose(primo_file);
        }

        system("pause");
        return(0);

}

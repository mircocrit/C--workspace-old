/*
 * Fprintf.c
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
        primo_file=fopen("Esami.txt", "a+"); // appende le informazioni alla fine del file
         printf("Il programma memorizza in un file Esami.txt le votazioni riportate \n da un singolo studente nei vari insegnamenti\n\n");
        if (primo_file==NULL)
             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
        else
        {
          printf("Inserire gli insegnamenti e le rispettive votazioni riportate (Es. Programmazione 30) \n\n Per terminare l'inserimento digitare CRTL+Z (win) CRTL+D (mac):\n\n");
          scanf("%s %d", insegnamento, &voto);
           while (!feof (stdin))
           {
                 fprintf(primo_file, "%s %d\n", insegnamento, voto);
                 scanf("%s %d", insegnamento, &voto);
           }
           printf("File creato\n\n");
          fclose(primo_file);
        }

        system("pause");
        return(0);

}

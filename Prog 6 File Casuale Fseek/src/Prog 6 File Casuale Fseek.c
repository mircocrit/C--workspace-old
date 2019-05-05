/*
 * File Casuale Fseek.c
 *
 *  Created on: 16-dic-2009
 *      Author: Veronica
 */
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
        int codice;
		char cognome[10];
        char nome[10];
        char matricola[10];
        char corso_di_laurea[20];
}studente_t;



int
main ()
{
        FILE *primo_file;
		studente_t stud ={0,"","","",""};

        primo_file=fopen("Studenti.txt", "w+");
        printf("Il programma memorizza in un file Studenti.txt le informazioni di un elenco di studenti \n\n");
        if (primo_file==NULL)
             printf("\n\n\n*********** Impossibile aprire il file************* \n\n");
        else
        {

          do
          {
        	  printf("Inserire i dati dello studente (-1 nel codice per terminare) -->");
        	  printf("\n\n       CODICE   --> " );
        	  scanf("%d", &stud.codice);
        	  if (stud.codice!=-1)
        	  {
        		  printf("         COGNOME   --> " );
        		  scanf("%s", stud.cognome);
        		  printf("       NOME   --> " );
        		  scanf("%s", stud.nome);
        		  printf("      MATRICOLA   --> " );
        		  scanf("%s", stud.matricola);
        		  printf("\n       CORSO DI LAUREA IN   --> " );
        		  scanf("%s", stud.corso_di_laurea);
        		  /* (stud.codice-1)*sizeof(studente_t) mi consente di calcolare la posizione
        		   * in cui inserire il record. In altre parole moltiplico la dimensione di ogni
        		   * singolo record per il numero di record che precedono il record che
        		   * cerco di inserire.
        		   */
        		  fseek(primo_file,(stud.codice-1)*sizeof(studente_t), SEEK_SET);
        		  fwrite(&stud, sizeof(studente_t), 1, primo_file);
        	  }

          }while (stud.codice!=-1);
          rewind(primo_file);
          printf("I dati memorizzati nel file sono i seguenti \n");
          printf("%-10s %-10s %-10s %-10s %-10s\n\n", "Codice", "Cognome", "Nome", "Matricola", "Corso di Laurea");
                  	  while (!feof(primo_file))
                  	  {
                  		  fread(&stud, sizeof(studente_t), 1, primo_file);
                  		  if (!feof(primo_file))
                  			  printf(" %d %-10s %-10s %-10s %-10s\n\n", stud.codice, stud.cognome, stud.nome, stud.matricola, stud.corso_di_laurea );
                  	  }

           printf("***************Inserimento Terminato******************\n\n");
          fclose(primo_file);
        }

        system("pause");
        return(0);

}



/*
 * AnalisiStringa.c
 *
 *  Created on: 08/dic/2009
 *      Author: Acer
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LUNG 80


int
main()
{

     char stringa[LUNG];
     int lunghezza,i, alpha_lower=0,alpha_upper=0,num=0,punt=0;
     printf("************************************************************************\n");
     printf("****   Il programma analizza i singoli caratteri di una stringa     ****\n");
     printf("****   restituendo per il numero di caratteri alfabetici contenuti, ****\n");
     printf("****   e di questi dica quanti sono maiuscoli o minuscoli, il numero****\n");
     printf("****    di cifre contenute o di caratteri di punteggiatura          ****\n");
     printf("************************************************************************\n\n");
     printf("Inserire la stringa da analizzare (max 80 caratteri senza spazi)-->");
     scanf("%s", stringa);
     lunghezza=strlen(stringa);
     printf("La stringa inserita contiene: \n");
     for (i=0;i<=lunghezza;i++)
     {
    	 if(isalpha(stringa[i]) && islower(stringa[i]))
    		 alpha_lower++;
    	 else if (isalpha(stringa[i]) && isupper(stringa[i]))
    		 alpha_upper++;
    	 else if (isdigit(stringa[i]))
    		 num++;
    	 else if (ispunct(stringa[i]))
    		 punt++;
     }
	 printf("   - %d caratteri, di cui %d minuscoli e %d maiuscoli \n", alpha_lower+alpha_upper, alpha_lower, alpha_upper);
	 printf("   - %d numeri\n", num);
	 printf("   - %d segni di punteggiatura", punt);
     system("pause");
     return 0;
}

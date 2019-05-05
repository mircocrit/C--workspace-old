/*Scrivere un programma che
1) Acquisisca in input la password inserita da un utente,
2) Verifichi se la password contiene almeno una lettera maiuscola ed almeno un numero,
3) Stampi in output un messaggio di conferma se la password è corretta, in alternativa, stampare un messaggio di errore.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int main() {
	char password[20];
	int i=0,count=0,num,low;
	do{
		num=FALSE;
		low=FALSE;
		printf("Inserire la password (deve contenere almeno un carattere maiuscolo e un numero)\n");
		gets(password);
		count=strlen(password);
		for(i=0;i<count;i++){
			if(isdigit(password[i]))		num=TRUE;
			if(isupper(password[i]))		low=TRUE;
		}

		if (low==FALSE)	 	printf("Inserire almeno un carattere maiuscolo\n");
		else if(num==FALSE)	printf("Inserire almeno un carattere numerico\n");
		else				printf("Password accettata\n");
	}while(low==FALSE || num==FALSE);
	system("pause");
	return 0;
}

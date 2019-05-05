/*
Scrivere un programma che acquisisca una stringa password e converta le vocali in $ e le consonanti in *,
restituendo la stringa finale.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 26

void inserimento(char*);
int isvowel(char);
void conversione(char*);

int main() {
	char string[MAX];
	inserimento(string);
	conversione(string);
	printf("%s",string);
	system("pause");
	return 0;
}

void inserimento(char* y){
	printf("Inserire la password:\n");
	scanf("%s",y);
}

void conversione(char *string){
	int isvowel(char);
	for(int i=0;i<strlen(string);i++){
		if(isalpha(string[i])){
			if(isvowel(string[i])){
				string[i]='$';
			}
			else{
				string[i]='*';
			};
		}
	}
}

int isvowel(char c){
	char vocali[10] = {'a','A','e','E','i','I','o','O','u','U'};
    for(int i=0;i<10;i++)
        if(c==vocali[i])  	return 1;
    return 0;
}

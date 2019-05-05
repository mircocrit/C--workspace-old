//stringhe,funz principali

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char lettera,s1[7]={"Miriam"},s2[7]={"Leone"};
    int n=7;
    lettera= getchar();
    putchar(lettera);
    strcpy(s1,s2);    //copia stringa 2 in stringa 1
    strncpy(s1,s2,n);    //copia non piu di n caratteri di str 2 in str 1
    strcmp(s1,s2);
    strcat(s1,s2);    //trasporma str1 in str1+str2
    strlen(s1);
    return 0;
}


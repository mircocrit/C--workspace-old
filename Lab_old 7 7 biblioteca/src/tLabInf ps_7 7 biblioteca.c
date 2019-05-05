/* Scrivere un programma che prende i dati da un catalogo di una bibloteca nel seguente modo:
 1) catalogo biblioteca: stato(presente/assente), LIBRO: titolo, autore, casa editrice, prezzo.
 2) archivio abbonati e che l'utente abbia al massimo 3 libri in carico,
 *l'utente puo prendere al massimo 1 libro per volta
 *l'archivio gestisca la circostanza di un libro dato a qualcuno, sapendo chi sia e quando ha intezione di riconsegnarlo
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[40];
    char cognome[40];
    int carico; //quanti
}abbonato;

typedef struct{
    char titolo[40];
    char autore[40];
    char casa_editrice[40];
    float prezzo;
    abbonato utenza;// chi ha il libro
    int time;
}libro;

typedef struct{
    libro b[20];
    int state[20];
}catalogo;

catalogo inserimento();

int main(){
    abbonato a[30];
    catalogo c;

    //titolo = new char(strelen param);
    //strcpy(titolo,param);
    return 0;
}

catalogo inserimento(void){
    catalogo c;
    int i;
    for(i=0;i<20;i++){
        printf("Inserire il libro:\n ");
        printf("Inserore l'autore: ");
        scanf("%s",c.b[i].autore);
        printf("Inserire il titolo: ");
        scanf("%s",c.b[i].titolo);
        printf("Inserire la casa editrice: ");
        scanf("%s",c.b[i].casa_editrice);
        printf("Inserisce prezzo: ");
        scanf("%f",&c.b[i].prezzo);
        printf("Inserire l'utenza: ");

          }
    }


/* Scrivere un programma che legge da un file un certo numero di dati legati ad un certo catalogo.txt con: nome,codice,prezzo,aliquota iva
 Il programma stampera il prezzo dell'articolo che l'utente vuole, al netto dell'iva
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 20

typedef struct{
    char nome[15];
    char codice[15];
    float prezzo;
    float iva;
}articolo;

void scrivi_file(void);
int leggi_catalogo(articolo[MAX]);
void stampa_prezzo(articolo[MAX],char[15],int dim);
void stampa_array(articolo);

int main(){
    int dim;
    articolo a[MAX];
    char search[15];
    scrivi_file();
    printf("\n");
    dim=leggi_catalogo(a);
    printf("\n");
    printf("Inserire il codice dell'articolo da cercare\n");
    scanf("%s",search);
    printf("\n");
    stampa_prezzo(a,search,dim);
    for(int i=0;i<dim;i++)
        stampa_array(a[i]);
    return 0;
}

void scrivi_file(){
    int i,n;
    FILE *q;
    articolo a[MAX];
    printf("Quanti articoli inserire?  ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Inserire nome articolo: ");
        scanf("%s",a[i].nome);
        printf("Inserire codice articolo: ");
        scanf("%s",a[i].codice);
        printf("Inserire prezzo articolo: ");
        scanf("%f",&a[i].prezzo);
        printf("Inseirire iva da applicare: ");
        scanf("%f",&a[i].iva);
        printf("\n");
    }
    printf("Inizio caricamento articoli\n");
    if((q=fopen("/Users/mircocrit/Documents/Xcode/__old/cap 7/7 2 archivo_file/archivio.txt","ab+"))==NULL)
        puts("Errore apertura");
    else{
        printf("File aperto\n");
        for(i=0;i<n;i++)
            fwrite(&a[i],sizeof(articolo),1,q);
        printf("Articoli caricati\n");
            }
    fclose(q);
}

int leggi_catalogo(articolo a[MAX]){
    printf("Inizio lettura articoli da file\n");
    FILE* q;
    int i=0;
    if((q=fopen("/Users/mircocrit/Documents/Xcode/__old/cap 7/7 2 archivo_file/archivio.txt","rb"))==NULL){
        puts("Errore apertura");
        return 0;
        }
    else{
        printf("File aperto\n");
        while(!feof(q)){
            fseek(q,i*sizeof(articolo),SEEK_SET);
            fread(&a[i],sizeof(articolo),1,q);
            i++;
        }
        printf("File letto\n");
        return i-1;
    }
}

void stampa_prezzo(articolo a[MAX],char search[15],int dim){
    int flag=0;
    for(int i=0;i<dim;i++){
        if(strcmp(a[i].codice,search)==0)
            printf("Il prezzo dell'articolo %s al netto dell'iva e' %f\n",a[i].nome,a[i].prezzo-a[i].prezzo*(a[i].iva*0.01));
            flag=1;
        }
    if(flag==0) printf("Articolo non trovato\n");
}

void stampa_array(articolo a){
    printf("Nome articolo: %s\n",a.nome);
    printf("Codice articolo: %s\n",a.codice);
    printf("Prezzo articolo: %f\n",a.prezzo);;
    printf("Iva da applicare: %f\n",a.iva);
    printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define PATH1 "D:\\eclipse-workspace\\Lab 5 Seq interi\\array.txt"
#define PATH2 "D:\\eclipse-workspace\\Lab 5 seq interi\\ordinato.txt"
#define PATH3 "D:\\eclipse-workspace\\Lab 5 Seq interi\\magg.txt"

int acquisizione(int vett[]){
	int n;
	printf("Numerosita elementi:   ");
	scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Elemento  num %d   ",i+1);
        scanf("%d",&vett[i]);
    }
    return n;
}

void scrivi_file(int vett,char* PATH){
	FILE *fp=NULL;
	fp=fopen(PATH,"a");
    if(fp==NULL)
    	printf("Apertura file non riuscita\n");
    else{
        fprintf(fp, "%d  ",vett);
        fclose(fp);
    }
}

void insertion_sort(int vett[],int dim){
    int i,key,j;
    for(i=1;i<dim;i++){
        key=vett[i];
        j=i-1;
        while(j>=0 && vett[j]>key){
            vett[j+1]=vett[j];
            j=j-1;
        }
        vett[j+1]=key;
    }
}

void ricerca_magg(int vett[],int n,int search){
    int i;

    for(i=0;i<n;i++){
        if(vett[i]>search){
        	scrivi_file(vett[i],PATH3);
        }
    }
}

void leggi_file(char PATH[]){
	FILE *fp=NULL;
	int temp[MAX],j=0;
	fp=fopen(PATH,"r+");
	if(fp==NULL)    printf("Apertura file non riuscita\n");
	else{
		while(!feof(fp)){
			fscanf(fp,"%d   ",&temp[j]);
			printf("%d  ",temp[j]);
			j++;
		}
	printf("\n");
	fclose(fp);
	}
}

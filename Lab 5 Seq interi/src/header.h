#ifndef header_h
#define header_h

#include <stdio.h>
#include <stdlib.h>
#define PATH1 "D:\\eclipse-workspace\\Lab 5 Seq interi\\array.txt"
#define PATH2 "D:\\eclipse-workspace\\Lab 5 Seq interi\\ordinato.txt"
#define PATH3 "D:\\eclipse-workspace\\Lab 5 Seq interi\\magg.txt"

int acquisizione(int[]);
void scrivi_file(int,char*);
void insertion_sort(int vett[],int n);
void ricerca_magg(int vett[],int,int);
void leggi_file(char*);

#endif /* header_h */

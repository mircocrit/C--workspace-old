//FILES

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    FILE *fp;
    int argom,j,n,err;
    fp=fopen("nomefile.txt","r");
    if(fp==NULL)    printf("File inesistente\n");
    fscanf(fp,"%d",&argom);
    while(fscanf(fp,"%d",&j))
        j+1;
    if(j==0)        printf("file vuoto\n");
    fprintf(fp,"%d",argom);
    fclose(fp);
    //binary
    n=fread(fp,sizeof(int),1,&argom);
    n=fwrite(fp,sizeof(int),1,&argom);

    err=fseek(fp,sizeof(int),SEEK_SET);
    ftell(fp);
    rewind(fp);//=fseek(fp,0,0)
    append(fp);//l'append accoda i file l'uno all'altro
    fgetc(fp);
    fputc(3, fp);
   // n=remove(fp,...);
    //n=rename("","");
    return 0;
}


//malloc,calloc,sizeof

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *v,*s,p,n;
    printf("Inserire numero elementi\n");
    scanf("%d",&n);
    v=malloc(4*n);
    s=calloc(4,sizeof(n));
    free(v);
    free(s);
    p=sizeof(v); //restituira la dimesione di v
    return 0;
}

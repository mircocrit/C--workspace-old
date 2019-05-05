#include <stdio.h>
#include <stdlib.h>

int main() {
	int b[]={10,20,30,40};
	int  *bPtr=b;
	int i;
	int offset;

	printf("array to be printed\n");

	for(i=0;i<4;i++){
		printf("b[%d] - %d\n",i,b[i]);
	}
	printf("\n");
	printf("pointer offste notation where the pointer is the array name\n");
	for(offset=0;offset<4;offset++){
		printf("(b+ %d) =%d\n",offset, *(b+offset));
	}

	/*printf("prova con +4\n");
	for(offset=0;offset<4;offset++){
			printf("(b+ %d) =%d\n",offset, *(b+4*offset));
		}
	*/
	printf("pointer subscript notation\n");
	for(i=0;i<4;i++){
		printf("bPtr[%d] = %d\n",i,bPtr[i]);
	}

	printf("Pointer offset notation\n");
	for(offset=0;offset<4;offset++){
		printf("(bPtr + %d) = %d\n",offset,*(bPtr+offset));
	}
	system("pause");
	return 0;
}

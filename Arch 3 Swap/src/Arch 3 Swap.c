#include <stdio.h>
#include <stdlib.h>

int main() {
	while (true){
	//...
	key = TRUE;
	while (key == TRUE)
		swap (&lock, &key ); //in key torna false
	<critical section>
	lock = FALSE;
	//...
	}
	return 0;
}

void swap (boolean *a, boolean *b){
	boolean temp = *a;
    *a = *b;
    *b = temp:
}

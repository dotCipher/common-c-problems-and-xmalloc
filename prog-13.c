#include <stdio.h>
#include <stdlib.h>

/*
13: using pointers that are not aligned on word boundaries (SIGBUS)
*/

int main(int argc, char** argv){
	int* a;
	void* b;
	printf("- - - TEST PROGRAM 13 - - -\n");
	a = (int*)malloc(sizeof(int));
	printf("Address \'a\' initialized at = %p\n", a);
	printf("Initializing Address \'b\' to 1 over word boundry...\n");
	b = ((char*)a)+1;
	printf("Address \'b\' set to = %p\n", b);
	printf("Value of a = %i\n", *a);
	printf("Value of b now cannot be deferenced\n");
	free(a);
	return 0;
<<<<<<< prog-13.c
}
=======
}

>>>>>>> 1.2

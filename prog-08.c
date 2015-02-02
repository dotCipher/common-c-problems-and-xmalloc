#include <stdio.h>
#include <stdlib.h>

/*
08: double-freeing memory
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 8 - - -\n");
	addr = (char*)(malloc(10));
	printf("Address initialized at = %p\n", addr);
	free(addr);
	printf("Address freed\n");
	printf("Freeing address again:\n");
	free(addr);
	printf("Address freed again...\n");
	return 0;
<<<<<<< prog-08.c
}
=======
}

>>>>>>> 1.3

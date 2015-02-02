#include <stdio.h>
#include <stdlib.h>

/*
17: reading uninitialized memory
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 17 - - -\n");
	addr = (char*)(malloc(10));
	printf("Allocated memory for address at = %p\n", addr);
	printf("Reading memory without initializing...\n");
	printf("Data: %s\n", addr);
	free(addr);
	return 0;
<<<<<<< prog-17.c
}
=======
}

>>>>>>> 1.2

#include <stdio.h>
#include <stdlib.h>

/*
06: freeing a NULL pointer (which really is a zero...)
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 6 - - -\n");
	addr = (char*)(malloc(10));
	printf("Address initialized at = %p\n", addr);
	addr = NULL;
	printf("Address changed to = %p\n", addr);
	free(addr);
	printf("Address freed\n");
	return 0;
<<<<<<< prog-06.c
}
=======
}

>>>>>>> 1.3

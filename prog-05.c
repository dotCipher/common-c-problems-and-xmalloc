#include <stdio.h>
#include <stdlib.h>

/*
05: freeing an illegal zero (0) address
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 5 - - -\n");
	addr = (char*)(malloc(10));
	printf("Address initialized at = %p\n", addr);
	addr = 0;
	printf("Address changed to = %p\n", addr);
	free(addr);
	printf("Address freed\n");
	return 0;
<<<<<<< prog-05.c
}
=======
}

>>>>>>> 1.3

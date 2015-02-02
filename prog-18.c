#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
18: memcpy passed a NULL pointer in FIRST ARG
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 18 - - -\n");
	addr = (char*)(malloc(4));
	addr = "abc\0";
	printf("Allocated memory for address at = %p\n", addr);
	printf("Data: %s\n", addr);

	printf("Using memcpy with NULL in first arg...\n");
	memcpy(NULL, addr, 4);
	printf("After memcpy:\n");

	printf("Allocated memory for address at = %p\n", addr);
	printf("Data: %s\n", addr);
	free(addr);
	return 0;
<<<<<<< prog-18.c
}
=======
}

>>>>>>> 1.2

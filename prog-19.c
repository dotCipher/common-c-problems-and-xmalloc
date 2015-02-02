#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
19: memcpy passed a NULL pointer in SECOND ARG
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 19 - - -\n");
	addr = (char*)(malloc(4));
	addr = "abc\0";
	printf("Allocated memory for address at = %p\n", addr);
	printf("Data: %s\n", addr);

	printf("Using memcpy with NULL in first arg...\n");
	memcpy(addr, NULL, 4);
	printf("After memcpy:\n");
	
	printf("Allocated memory for address at = %p\n", addr);
	printf("Data: %s\n", addr);
	free(addr);
	return 0;
}


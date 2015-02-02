#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
20: memcpy passed a NULL pointer but with zero copy length
*/

int main(int argc, char** argv){
	char* addr;
	char* addr2;
	printf("- - - TEST PROGRAM 20 - - -\n");
	addr = NULL;
	addr2 = NULL;
	printf("Allocated memory for address at = %p\n", addr);
	printf("Data: %s\n", addr);
	printf("Allocated memory for address2 at = %p\n", addr2);
	printf("Data2: %s\n", addr2);

	printf("Using memcpy with NULL pointers and zero copy length...\n");
	memcpy(addr, addr2, 0);
	printf("After memcpy:\n");
	
	printf("Allocated memory for address at = %p\n", addr);
	printf("Data: %s\n", addr);
	printf("Allocated memory for address2 at = %p\n", addr2);
	printf("Data2: %s\n", addr2);
	free(addr); free(addr2);
	return 0;
<<<<<<< prog-20.c
}
=======
}

>>>>>>> 1.2

#include <stdio.h>
#include <stdlib.h>

/*
11: using illegal pointer addresses (using "0")
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 11 - - -\n");
	addr = (char*)(malloc(10));
	printf("Address initialized at = %p\n", addr);
	addr = 0;
	printf("Address changed to = %p\n", addr);
	printf("Value at Address = %s\n", addr);
	printf("Address of 0 = %p\n", (void*)0);
	return 0;
<<<<<<< prog-11.c
}
=======
}

>>>>>>> 1.2

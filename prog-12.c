#include <stdio.h>
#include <stdlib.h>

/*
12: same as #11, but using small positive/negative integers.
*/

int main(int argc, char** argv){
	char* addr;
	printf("- - - TEST PROGRAM 12 - - -\n");
	addr = (char*)(malloc(10));
	printf("Address initialized at = %p\n", addr);
	addr = (char*)-1;
	printf("Address changed to = %p\n", addr);
	printf("Value at Address = %s\n", addr);
	printf("Address of 1 = %p\n", (void*)1);
	return 0;
<<<<<<< prog-12.c
}
=======
}

>>>>>>> 1.2

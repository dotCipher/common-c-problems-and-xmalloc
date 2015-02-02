#include <stdio.h>
#include <stdlib.h>

/*
16: creating an illegal pointer when using pointer arithmetic
*/

int main(int argc, char** argv){
	int* _int = (int*)malloc(5);
	printf("- - - TEST PROGRAM 16 - - -\n");
	*_int = -100;
	printf("INT pointer address = %p\n", _int);
	printf("Value of (int)INT = %i\n", *_int);
	printf("Changing pointer address to illegal value...\n");
	_int -= 9999;
	printf("New Values below:\n");
	printf("INT pointer address = %p\n", _int);
	printf("Value of (int)INT = %i\n", *_int);
	free(_int);
	return 0;
<<<<<<< prog-16.c
}
=======
}

>>>>>>> 1.2

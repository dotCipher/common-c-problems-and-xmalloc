#include <stdio.h>
#include <stdlib.h>

/*
15: comparing pointers to objects of different/incompatible types
*/

int main(int argc, char** argv){
	int* _int = (int*)malloc(1);
	char* _char = (char*)malloc(1);
	printf("- - - TEST PROGRAM 15 - - -\n");
	*_int = -100;
	*_char = 100;
	printf("INT pointer address = %p\n", _int);
	printf("CHAR pointer address = %p\n", _char);
	printf("Value of (int)INT = %i\n", *_int);
	printf("Value of (char)CHAR = %c\n", *_char);
	if((void*)_int == (void*)_char){
		printf("Values are the same.\n");
	} else if((void*)_int > (void*)_char){
		printf("INT > CHAR\n");
	} else if((void*)_int < (void*)_char){
		printf("CHAR > INT\n");
	}
	free(_int); free(_char);
	return 0;
<<<<<<< prog-15.c
}
=======
}

>>>>>>> 1.2

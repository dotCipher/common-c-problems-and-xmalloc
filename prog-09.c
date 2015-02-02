
#include <stdio.h>
#include <stdlib.h>

/*
09: realloc'ing a non-heap memory
*/

int main(int argc, char** argv){
	int i=0;
	char array[3] = {'a', 'b', 'c'};
	printf("- - - TEST PROGRAM 9 - - -\n");
	printf("Array Length = %d\n", (int)(sizeof(array) / sizeof(array[0])));
	for(; i<=3; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	printf("Now realloc\'ing Array...\n");
	array[0] = (char)malloc(4); // GCC compiler catches realloc
	printf("Done!\n");
	return 0;
<<<<<<< prog-09.c
}
=======
}

>>>>>>> 1.6

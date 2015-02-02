#include <stdio.h>
#include <stdlib.h>

/*
07: freeing a non-heap memory
*/

int main(int argc, char** argv){
	int i=0;
	char array[3] = {'a', 'b', 'c'};
	printf("- - - TEST PROGRAM 7 - - -\n");
	printf("Array Length = %d\n", (int)(sizeof(array) / sizeof(array[0])));
	for(; i<=3; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	printf("Now freeing Array...\n");
	free(array); // GCC compiler catches free
	printf("Done!\n");
	return 0;
<<<<<<< prog-07.c
}
=======
}

>>>>>>> 1.5

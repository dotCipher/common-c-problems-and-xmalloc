#include <stdio.h>
#include <stdlib.h>

/*
01: Check the index of a statically-allocated array when overflowing
    (index is the offset within an array)
*/

int main(int argc, char** argv){
	int i=0;
	char array[3] = {'a', 'b', 'c'};
	printf("- - - TEST PROGRAM 1 - - -\n");
	printf("Array Length = %d\n", (int)(sizeof(array) / sizeof(array[0])));
	for(; i<=3; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	return 0;
<<<<<<< prog-01.c
}
=======
}

>>>>>>> 1.4

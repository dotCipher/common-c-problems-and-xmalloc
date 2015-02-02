#include <stdio.h>
#include <stdlib.h>

/*
02: Check the index of a statically-allocated array when under-flowing
*/

int main(int argc, char** argv){
	int i=0;
	char array[3] = {'a', 'b', 'c'};
	i = (int)(sizeof(array) / sizeof(array[0])-1);
	printf("- - - TEST PROGRAM 2 - - -\n");
	printf("Array Length = %d\n", i);
	for(; i>0; i--){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	return 0;
<<<<<<< prog-02.c
}
=======
}

>>>>>>> 1.4

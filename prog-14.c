#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
14: partially overlapping memcpy() arguments
*/

int main(int argc, char** argv){
	int i;
	char array[] = {'a', 'b', 'c'};
	int len = sizeof(array) / sizeof(char);
	printf("- - - TEST PROGRAM 14 - - -\n");
	printf("Array Length = %d\n", len);
	for(i=0; i<len; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	printf("Using Memcpy partly over itself...\n");
	memcpy(array, array+1, 2);
	printf("Done!  New Array data below:\n");
	len = sizeof(array) / sizeof(char);
	printf("Array Length = %d\n", len);
	for(i=0; i<len; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	return 0;
<<<<<<< prog-14.c
}
=======
}

>>>>>>> 1.2

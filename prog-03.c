#include <stdio.h>
#include <stdlib.h>

/*
03: Check the index of a dynamically-allocated array when overflowing
*/

int main(int argc, char** argv){
	int i=0, len=0;
	char* array;
	printf("- - - TEST PROGRAM 3 - - -\n");
	printf("Enter Array Length = ");
	scanf("%d", &len);
	// Dynamically build array
	if(!(array = (char *)malloc(sizeof(char) * len))) return -1;
	for(; i<len; i++){
		array[i] = i+97; // a, b, c, ...
	}
	for(i=0; i<=len; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	return 0;
<<<<<<< prog-03.c
}
=======
}

>>>>>>> 1.3

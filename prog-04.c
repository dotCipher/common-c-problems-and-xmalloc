#include <stdio.h>
#include <stdlib.h>

/*
04: Check the index of a dynamically-allocated array when under-flowing
*/

int main(int argc, char** argv){
	int i=0, len=0;
	char* array;
	printf("- - - TEST PROGRAM 4 - - -\n");
	printf("Enter Array Length = ");
	scanf("%d", &len);
	// Dynamically build array
	if(!(array = (char *)malloc(sizeof(char) * len))) return -1;
	for(; i<len; i++){
		array[i] = i+97; // a, b, c, ...
	}
	for(i=len-1; i>0; i--){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	free(array);
	return 0;
<<<<<<< prog-04.c
}
=======
}

>>>>>>> 1.3

#include <stdio.h>
#include <stdlib.h>

/*
10: using dynamic memory after it has been free()'ed
*/

int main(int argc, char** argv){
	int i=0, len=0;
	char* array;
	printf("- - - TEST PROGRAM 10 - - -\n");
	printf("Enter Array Length = ");
	scanf("%d", &len);
	// Dynamically build array
	if(!(array = (char *)malloc(sizeof(char) * len))) return -1;
	for(; i<len; i++){
		array[i] = i+97; // a, b, c, ...
	}
	for(i=0; i<len; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	printf("Freeing Array...\n");
	free(array);
	printf("Iterating through Array after free...\n");
	for(i=0; i<len; i++){
		printf("Array[%d] = %c\n", (int)i, array[i]);
	}
	printf("Done!\n");
	return 0;
<<<<<<< prog-10.c
}
=======
}

>>>>>>> 1.3

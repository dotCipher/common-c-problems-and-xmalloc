#include <stdio.h>
#include <stdlib.h>

/*
21: referring to an automatic stack object that has been popped from the
    stack (the object is not valid in the scope it is being referenced)
*/

int main(int argc, char** argv){
   char *a = NULL;
   printf("- - - TEST PROGRAM 21 - - -\n");
   printf("CHAR pointer \'a\' initialized to address of = %p\n", a);
   printf("Going into loop...\n");
   while(1){
   		char b;
   		printf("Creating CHAR \'b\'...\n");
   		a = &b;
   		printf("Setting \'a\' to deferenced \'b\'...\n");
   		break;
   		printf("Breaking out of loop\n");
   	}
   	printf("CHAR \'b\' is not out of scope\n");
   	printf("CHAR pointer \'a\' address = %p\n", a);
   	printf("CHAR pointer \'a\' is now a dangling pointer.\n");
   	return 0;
<<<<<<< prog-21.c
}
=======
}

>>>>>>> 1.2

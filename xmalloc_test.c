#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "xmalloc.h"

void initlib(){
	int ret;
	printf("Initializing XMEM library...\n");
	ret = initxmem();
	printf("initxmem return = %i\n", ret);
	return;
}

void test_doublefree(){
	int s = 13;
	char* ptr;
	ptr = (char*)xmalloc(sizeof(char) * (s));
	printf("- - - DOUBLE FREE - - -\n");
	memset(ptr, 0, s);
	strcpy(ptr, "Hello World!");
	printf("ptr addr = %p\n", ptr);
	printf("ptr data = %s\n", ptr);
	xfree(ptr);
	xfree(ptr);
	printf("- - - END - - -\n");
	return;
}

void test_freeinvalidaddr(){
	int s = 13;
	char* ptr;
	char* ptr_backup;
	ptr = (char*)xmalloc(sizeof(char) * (s));
	ptr_backup = ptr;
	printf("- - - FREE INVALID PTR - - -\n");
	memset(ptr, 0, s);
	strcpy(ptr, "Hello World!");
	printf("ptr addr = %p\n", ptr);
	printf("ptr data = %s\n", ptr);
	xfree(++ptr);
	xfree(ptr_backup);
	printf("- - - END - - -\n");
	return;
}

void test_memoryleak(){
	int s = 13;
	char* ptr;
	ptr = (char*)xmalloc(sizeof(char) * (s));
	printf("- - - MEMORY LEAK - - -\n");
	memset(ptr, 0, s);
	strcpy(ptr, "Hello World!");
	printf("ptr addr = %p\n", ptr);
	printf("ptr data = %s\n", ptr);
	printf("- - - END - - -\n");
	return;
}

int main(int argc, char** argv){
	// Load the xmalloc/xfree library
	initlib();
	// Test double free
	test_doublefree();
	// Test freeing invalid addr (pointer in middle of allocated block)
	test_freeinvalidaddr();
	// Test memory leaking
	test_memoryleak();
	return 0;
<<<<<<< xmalloc_test.c
}
=======
}

>>>>>>> 1.4

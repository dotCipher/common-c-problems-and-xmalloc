#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

#if defined(__sun) || defined(__sun__)
#include <sys/inttypes.h>
#else
#include <stdint.h>
#endif

// Interface include
#include "xmalloc.h"

// Output macros
#define _xmem_err(msg) fprintf(stderr, "XMEM_ERROR: " msg);
#define _xmem_warn(msg) fprintf(stderr, "XMEM_WARNING: " msg);
#define _xmem_lib_err(msg) fprintf(stderr, "XMEM_LIB_ERROR: " msg);
#define _xmem_print_node(a, s) fprintf(stderr, "Allocated memory at: %p\nAllocation size of: %lu\n",a,s);
// Defaults
#define _default_node_size 0
#define _default_node_addr NULL
#define _default_node_next NULL


/* - - - - - - GLOBAL DECLARATIONS - - - - - - */

// xmem data structure
typedef struct xmem_node{
	void* addr;
	size_t size;
	struct xmem_node* next;
}xmem_node;
xmem_node* xmem_root;

// Old sigaction structures
struct sigaction old_sigterm, old_sigint, old_sigquit, old_sighup;

/* - - - - - - INTERNAL HELPER FUNCTIONS - - - - - - */

// Wrapper for output macro
void printnode(xmem_node* node){
	_xmem_print_node(node->addr, node->size);
	return;
}

// Iterates and prints all currently allocated nodes
void printxmem(){
	// Initialize node pointer
	xmem_node* xmem_ptr = xmem_root;
	_xmem_warn("Dumping memory allocations:\n");
	// Iterate through nodes and print out values
	while(xmem_ptr != NULL){
		// Ignore unallocated nodes (aka. tail node)
		if(xmem_ptr->size != _default_node_size)
			printnode(xmem_ptr);
		// Go to next node
		xmem_ptr = (xmem_node*)xmem_ptr->next;
	}
	return;
}

// Proper memory cleanup for all nodes in link list
void freeallnodes(){
	xmem_node* ptr = xmem_root;
	xmem_node* prevnode = NULL;
	while(ptr != NULL){
		if(ptr->next){
			// Case 1: There is a node after this one
			prevnode = ptr;
			ptr = ptr->next;
			free(prevnode);
		} else {
			// Case 2: There is only one node left, so free it
			free(ptr);
			break;
		}
	}
	return;
}

// Caller program termination handler function
void onxmemexit(){
	// Check if xmem_node root is empty, if so, memory leak
	if((xmem_root->size != _default_node_size) 
		&& (xmem_root->addr != _default_node_addr)){
		_xmem_err("Memory leak.\n");
		// Print allocations
		printxmem();
	}
	// Return all signals to default state
	// SIGTERM
	if(sigaction(SIGTERM, &old_sigterm, NULL))
		_xmem_err("Failed to restore old sigaction() structure: SIGTERM\n");
	// SIGINT
	if(sigaction(SIGINT, &old_sigint, NULL))
		_xmem_err("Failed to restore old sigaction() structure: SIGINT\n");
	// SIGQUIT
	if(sigaction(SIGQUIT, &old_sigquit, NULL))
		_xmem_err("Failed to restore old sigaction() structure: SIGQUIT\n");
	// SIGHUP
	if(sigaction(SIGHUP, &old_sighup, NULL))
		_xmem_err("Failed to restore old sigaction() structure: SIGHUP\n");
	// Instead of just freeing the head node, 
	//	iterate through all nodes and free each one.
	// If you only free the head node, then all the other
	//	nodes will stay allocated, therefore causing a
	//	memory leak.
	freeallnodes();
	return;
}

// Allocates memory for a new xmem node and inits defaults
xmem_node* allocxmemnode(){
	xmem_node* newnode = xmem_root;
	xmem_node* prevnode = NULL;
	while(newnode != NULL){
		prevnode = newnode;
		newnode = newnode->next;
	}
	newnode = malloc(sizeof(xmem_node));
	newnode->size = (size_t)_default_node_size;
	newnode->addr = _default_node_addr;
	newnode->next = _default_node_next;
	if(prevnode){
		prevnode->next = newnode;
	}
	return newnode;
}

// Frees an xmem node and properly re-links the list
void unallocxmemnode(xmem_node* n){
	xmem_node* ptr = xmem_root;
	xmem_node* prev = NULL;
	while(ptr != NULL){
		if(ptr->addr == n->addr)
			break;
		prev = ptr;
		ptr = ptr->next;
	}
	// Internal error for no pointer
	if(ptr == NULL){
		_xmem_lib_err("Cannot unallocxmemnode().\n");
		return;
	}
	// Check if there is more than one node
	if(prev){
		prev->next = (xmem_node*)ptr->next;
		free(n);
	} else {
		// If only root node, reset it.
		n->size = (size_t)_default_node_size;
		n->addr = _default_node_addr;
		n->next = _default_node_next;
	}
	return;
}

/* - - - - - - EXPORTED LIBRARY FUNCTIONS - - - - - - */

// Must be called first to initialize the library
int initxmem(){
	// Declare signal handling structures
	struct sigaction new_action;
	// Set up new action structure
	new_action.sa_handler = onxmemexit;
	if(sigemptyset(&new_action.sa_mask)){
		_xmem_err("Failed to register atexit() function.\n");
		return -1;
	}
	new_action.sa_flags = 0;
	// Register atexit() function
	if(atexit(onxmemexit)){
		_xmem_err("Failed to register atexit() function.\n");
		return -1;
	}
	// Register new signal handling for all program termination signals
	// SIGTERM
	if(sigaction(SIGTERM, &new_action, &old_sigterm)){
		_xmem_err("Failed to register new sigaction() structure: SIGTERM\n");
		return -1;
	}
	// SIGINT
	if(sigaction(SIGINT, &new_action, &old_sigint)){
		_xmem_err("Failed to register new sigaction() structure: SIGINT\n");
		return -1;
	}
	// SIGQUIT
	if(sigaction(SIGQUIT, &new_action, &old_sigquit)){
		_xmem_err("Failed to register new sigaction() structure: SIGQUIT\n");
		return -1;
	}
	// SIGHUP
	if(sigaction(SIGHUP, &new_action, &old_sighup)){
		_xmem_err("Failed to register new sigaction() structure: SIGHUP\n");
		return -1;
	}
	// Initialize root node
	xmem_root = allocxmemnode();
	// Successfully initialized xmem
	return 0;
}

// malloc wrapper function
void* xmalloc(size_t n){
	// Init temp pointer
	void* temp_ptr;
	// Initialize node pointer
	xmem_node* xmem_ptr = xmem_root;
	// Do case checks
	if(!(xmem_ptr)){
		//	Case 1: xmem_root is uninitialized
		_xmem_err("Must call initxmem() before any other library calls.\n");
		return NULL;
	} else if(xmem_ptr->next){
		//	Case 2: node# >= 1
		//	Iterate through all nodes, until end is found
		while(xmem_ptr != NULL){
			// Go to next node
			xmem_ptr = xmem_ptr->next;
		}
		//	Init node to store malloc data
		xmem_ptr = allocxmemnode();
	}
	// If node# == 0, assume xmem_root has been initialized
	//	Malloc memory
	if(!(temp_ptr = malloc(n))){
		_xmem_err("Could not malloc().\n");
		return NULL;
	}
	//	Store size and address in end node
	xmem_ptr->size = n;
	xmem_ptr->addr = temp_ptr;
	//	Return address
	return temp_ptr;
}

// free wrapper function
void xfree(void* ptr){
	// Initialize temp max range
	uintptr_t range;
	//	Initialize node pointer
	xmem_node* xmem_ptr = xmem_root;
	// Do case checks
	if(!(xmem_ptr)){
		//	Case 1: xmem_root is uninitialized
		_xmem_err("Must call initxmem() before any other library calls.\n");
		return;
	}
	//	Iterate through each xmem_node
	while(xmem_ptr != NULL){
		if(xmem_ptr->size != _default_node_size)
			range = ((uintptr_t)(xmem_ptr->addr)) + (xmem_ptr->size);
		else
			range = 0;
		//	Check if size+addr of xmem_node is in range of ptr
		if((uintptr_t)xmem_ptr->addr < (uintptr_t)ptr && (uintptr_t)ptr <= range){
			//	Invalid free address (middle of memory)
			_xmem_err("Invalid xfree() address, address is pointing to middle of memory block.\n");
			return;
		}
		//	If address is found, free it
		if((uintptr_t)xmem_ptr->addr == (uintptr_t)ptr){
			free(ptr);
			//	Unallocate node from list
			unallocxmemnode(xmem_ptr);
			//	Return success
			return;
		}

		xmem_ptr = (xmem_node*)xmem_ptr->next;
	}
	// No address found:
	//	free before malloc/double free error
	if(!(xmem_ptr))
		_xmem_err("Invalid memory address used for xfree().\n");
	return;
}


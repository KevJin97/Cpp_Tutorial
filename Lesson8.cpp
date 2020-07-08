//Lesson 8: Memory Allocation

/*
	When memory is manually allocated, it's allocated from the heap. However, this memory is basically inaccessible without a reference
	so this allocated memory comes with its own memory address. Luckily there's a variable that can hold memory addresses.
	
	Why allocate memory? When a variable is declared, it sets that memory in the stack. Unfortunately, parameters in the stack is basically static and it
	cannot be modified. However, data allocated on the heap can be sized and resized as necessary. Full applications of this can be discussed in the next
	lesson.
	
	malloc("number of bytes")				//will allocate memory requested from the heap`
	realloc("pointer", "new size")			//will reallocate the requested memory without losing previous values
	free("pointer")							//frees allocated memory stored in pointer
*/


#include <stdio.h>
#include <stdlib.h>		//standard C library. Holds memory allocation functions

int main()
{
	int *p_pointer;
	
	//C method
	p_pointer = malloc(sizeof(int));	//allocate enough memory for one int
	
	*p_pointer = 5;	//at reserved memory, store "5"
	
	realloc(p_pointer, 2 * sizeof(int));	//reallocate for with enough size for 2 integers
	
	free(p_pointer);	//free all allocated memory, anything done before is now inaccessible
	
	
	//C++ method
	p_pointer = new int;	//allocate memory of 1 int
	
	*p_pointer = 10;	//at allocated memory, store value "10"
	
	delete p_pointer;	//free all memory, same as before
	//how to allocate larger amounts of data will be discussed later
	
	return 0;
}
//Lesson 9: Arrays and Dynamic Arrays

/*
	Arrays are vectors of data of the same type. The bad thing about arrays is that they are stored on the stack making them impossible to resize.
	Luckily, pointers come to help out and any amounts of data can be allocated as needed. The [] operator will let us access different points of the
	stored bytes to read the values.
	
	Due to the contraints of the array, arrays should be used when there is a set number of values to be held. If the size of the array will be constantly
	changed, using pointers will be a better idea.
	
	It's important to note that pointers and arrays index from 0 so an array of 5 spaces (size == 5) will have the spaces 0, 1, 2, 3, 4.
	
	A benefit of arrays is that, since they are allocated on the stack, using the sizeof() command on them will definitely return the full bytesize of the 
	array. Using sizeof() on a pointer will simply return the size of the pointer variable.
*/

//When initializing an array (setting a value in the same line it's created), they can only be initialized all at once when they're created. Otherwise, they must
//be initialized individually.

/*
	Strings:
	Strings are just a sequence of characters stored as an array. However, they MUST end with a nullspace character at the end as that's how the computer
	knows when to stop reading the string when printing. So the word "string" with 6 characters must allocate 7 spaces where the last space has the value
	0 == '\0' denoted by the key NULL
*/

#include <stdio.h>

int main()
{
	int intarray[5];
	//intarray = { 1, 2, 3, 4, 5 };	//this doesn't work since it wasn't initialized
	
	printf("Notice how intarray returns a memory address like pointers: %p\n", intarray);
	for (int i = 0; i < 4; i++)	//change each value individually
	{
		intarray[i] = i + 1;	//at index 'i', set value
	}
	
	int intarray2[5] = { 1, 2, 3, 4, 5 };	//initialized all values all at once
	int intarray3 = { 0 };	//initialize all to one value
	
	
	int *p_array = new int[5];	//allocate 5 array spaces of size 5
	delete[] p_array;	//slightly different new and delete commands for arrays
	
	//using malloc
	p_array = malloc(sizeof(int) * 5);	//allocate 5 int spaces
	p_array[0] = 1;
	p_array[1] = 2;
	p_array[2] = 3;
	p_array[3] = 4;
	p_array[4] = 5;
	free(p_array);
	
	
	char *p_string;
	p_string = new char[7];	
	p_string[6] = NULL;
	p_string = "string";	//"string" automatically has the NULL space but it's always good to set it yourself
	delete[] p_string;
	//character values are always represented by '' while strings are represented with ""
	
	
	//dynamic array values
	p_array = new int[5];
	for (int i = 0; i < 5; i++)		//copy contents of intarray into p_array
	{
		p_array[i] = intarray[i];
	}
	
	/*
		Say a value of 6 wants to be added to p_array. The array must be resized. Typically not recommended to mix the use of new/delete
		with malloc/realloc/free
		
		Using realloc
		realloc(p_array, sizeof(int) * 6);
		p_array[5] = 6;
		
		
		Using new/delete
		1) Existing data must be held somewhere. A new pointer holds onto the memory address of p_array (which has the data).
		2) Larger memory is assigned to p_array
		3) Old data is copied into the new array
		4) Old memory is then erased
		5) New value of 6 is added to p_array
	*/
	int *p_hold = p_array;		//1)
	p_array = new int[6];		//2)
	for (int i = 0; i < 5; i++)	//3)
	{
		p_array[i] = p_hold[i];
	}
	delete[] p_hold;			//4)
	p_array[5] = 6;				//5)
	
	
	delete[] p_array;	//release memory. Exiting the program would automatically do it anyways but it's good practice
	
	return 0;
}
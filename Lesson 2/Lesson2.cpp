//Lesson 2: Libraries
#include <stdio.h>	//standard I/O Library (C)

//The '#' symbol is an instruction to the compiler.

//In between the <> is a file library located in the reference folder the compiler checks. This tells the compiler to check this library before
//determing that an undefined function has no definition.

//If the programmer is the one that created a library located in the same folder as the main function, that library is referenced to in the code as
//"file". Example: if you created a library called mylibrary.h, it would be referenced to in the code as: #include "mylibrary.h"


int main()
{
	//Libraries contain several functions to aid in algorithm design
	//Library files (header files) are typically denoted with .h for C or .hpp for C++
	
	//In C++, to name libraries rather than reference the actual file name, they added 'c' in front of it.
	//since stdio.h is a C library, in C++ it can be referenced as <cstdio> which is the same as <stdio.h>
	
	printf("Hello World");	//printf() is a function that prints to a console.
	
	int age = 4;
	
	printf("\nHello, I am %d", age);	//age replaces %d in the printed statement
	/*
		printf Specifiers:
			%d or %i	signed integer
			%u			unsigned integer
			%o			octal integer
			%x			hexadecimal integer
			%f			float, double
			%e			scientific notation (float, double)
				%E			scientific notation (capital)
			%a			float, double in hexadecimal
				%A			float/double hex capitalized
			%c			character
			%s			string (sequence of characters)
			%p			pointer (will discuss later)
			\n			new line
			%%			prints '%'
			\\			prints '\'
	*/
	
	printf("Get Age: ");
	scanf("%d", age);	//scanf takes a certain input of a specified type and then places it in age
	printf("My age is: %d\n", age);
	
	return 0;
}
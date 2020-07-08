//Lesson 5: Header Files

//As seen in the previous lesson, the code can get quite messy extremely quickly.
//The use of header files lets the code be split up and separate to help with organization

#ifndef LESSON5_HPP	//if the program hasn't defined LESSON4_HPP
#define LESSON5_HPP	//define it

// ^ These are instructions to the compiler. The commands must not have '.' so the file names are conventionally dictated with '_'
//The name defined in the header file doesn't necessarily have to be the same as the file name but it's often done by convention

//Some systems simply use the statement: #pragma once
//This statement isn't standard in all compilers but serves the same purpose as ifndef, define, and endif but ensures the file is only ever included once.

#include "Lesson5 a.hpp"	//this contains function defintion for subtract(x, y)
							//a header file can #include other libraries so that the main folder doesn't have to include several #include statements

#include "Lesson5 b.cpp"	// the header file can also hold a source file. This one contains the multiply(x, y) function

int add(int x, int y)	//any source file that has #include "Lesson5.hpp" and has this file in its directory can use the functions in this file
{
	return x + y;
}

int subtract(int x, int y);	//function prototypes can be stored in here as well.


#endif	//ends the if statement from before
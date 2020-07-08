//Lesson 1:	Introduction

// <- Comment code with two backslashes

//Source files (such as this one) are typically denoted with .cpp for C++ programs and .c for C programs
//Example: filename.cpp

int main()	//All C++ programs contain a main() function.
{	//Opening and closing brackets contain function definition. No semicolon needed for these

	return 0;	//This means it returns an int value of zero at the end of the program. Returns an int due to the function type declared next to main()

}

/*	<- Comment with these to create brackets of comments

	Basic Datatypes:
		-void	(no size, use will be discussed later)
		
		-int	(integer values, 4 bytes, -2147483648 to 2147483647)
			-unsigned int	(non-negative integer values, 4 bytes, 0 to 4294967295)
			-long int		(larger int, 8 bytes, -2,147,483,648 to 2,147,483,647) (some systems have it as 4 bytes)
			-short int		(smaller xint, 2 bytes, -32768 to 32767)
			-long long int	(guaranteed 8 bytes)
		
		-float	(partial numbers, 4 bytes, (-)1.175494351 e -38 to (-)3.402823466 e 38)
			-double			(larger float, 8 bytes,	(-)2.2250738585072014 e -308 to (-)1.7976931348623158 e 308)
			
		-char	(contains integer read as a character from ASCII chart, 1 byte, 0 to 255)
			-wchar_t	(larger char for UNICODE, 2 or 4 bytes depending on system)
			
		-bool	(used to hold true or false, 1 byte, true or false)
		
*/
//These basic datatypes can be combined to make even more complex datatypes. This will be discussed later

//	sizeof("datatype")	<- This is a built-in function that returns the byte size of a given datatype (ex. sizeof(char);)

//All variable declarations must be preceded with a declaration of the datatypes


/*
	
	HOW C++ WORKS IN THE COMPUTER
	-The CPU	(combination of arthimetic and queueing in Von-Neumann Architecture)
		
		-The CPU receives a sequence of 0's and 1's. Specific sequences will activate commands which the computer then executes. 
		(Design of digital components at this low-level can be discussed as a part of digital circuit design)
		
		-Since plugging in 1's and 0's is extremely tedious, a programming language was created known as assembly.
		 Assembly language contains commands that directly manipulate the bits (1's, 0's).
		 (Before the widespread use of digital electronics, computations were done with mechanical machines that accepted slips of paper
		  with punched out holes that represented 1's and 0's)
		
		-Assembly language was still incredible painful to use. As a result, "higher-level" programming languages were created. These higher-level
		 programming languages contained "syntax" that was much easier to use and manipulate when developing these algorithms (instructions). 
		 Once these algorithms were written, they would be sent through a compiler which would translate these programming languages into assembly
		 and then the assembly commands would be interpreted by the CPU to execute them.
		 
		-The C compiler has been optimized, over the years, to be almost as efficient hand-designing an equivalent assembly program. Although personally
		 designing an assembly code would be the most computationally efficient method of designing algorithms, it is a process that would take an incredible
		 amount of time.
		 
		-C++ is simply the C language adapted to allow for object-oriented programming design. The compiler(g++) for this uses the same base as the 
		 C compiler(gcc) but hasn't yet been optimized to be as fast as gcc resulting in a slightly slower system.
		
	-Von-Neumann Architecture
		-The basic design most computers follow
		-The Architecture
			-Inputs and Outputs	(to give commands and receive results)
			-Memory				(stores processes, data, etc)
			-Arthimetic			(runs the basic commands)
			-Process Queueing	(determines which processes to do first)
	
	-Structure of the Memory
		-The memory in the computer always refers to the RAM memory. The RAM memory is significantly faster than the hard-drive in the computer (the hard-drive
		 often causing the most bottle-necking in most processes).
		
		-When the computer boots up, it will have a BIOs (Basic Inputs Outputs) system which will handle any basic system functions such as printing
		 to a screen, keyboard and mouse inputs, and hard-drive memory. The BIOs will then pull operating system algorithms from the hard-drive onto 
		 the RAM which will then run the computer that you're familiar with.
		
		-The Memory
			-When a process is written, there's 2 forms of memory that the computer often deals with: the stack and the heap
			
			-The Stack
				-Whenever a function is run, it will set aside a certain amount of memory and "stack" them into an organized list. When that function is
				 is completed, it will take off the reserved data off the top of that stack.
				
				-example:
					int main()											int add(int a, int b)
					{													{
						int number1;										int c = a + b;
						int number2;										return c;
						int number3 = add(number1, number2);			}
						return 0;
					}
					When the main function is run, it will reserve 4 bytes in the stack labeled "main". Then it will stack on 4 bytes of number1, then number2,
					then number 3.
					Since the function "add" was called, it will reserve 4 bytes for add and stack variables a & b as well. int c is then also created and stacked
					on. An additional few bytes are then stacked on for the + operation but then removed after c's value is set.
						
						The Stack (currently)
						-int c
						-int b
						-int a
						-int add
						-int number3
						-int number2
						-int number1
						-int main
						
					When return is called, it sets the value of int c to add before removing c, then b, then a from the stack.
					add's value is then set to number3 before add is also removed.
					After the main function ends (at return), it will remove number3, number2, and number1. It finally sends the 0 value to the CPU before it
					deletes main from the stack, completing the program.
			
			-The Heap
				-The heap operates slightly different from the stack. The heap refers to the remaining "unorganized" memory outside of the stack. While the
				 memory of each variable/process created in the stack is set until it gets removed later, a user can "reserve" memory on the heap for use
				 and may continue to allocate and deallocate memory as much as they wish.
				 
				-The main disadvantage of the heap is that if the programmer forgets to deallocate the memory, the memory stays reserved until the very end of
				 the program. If the algorithm requires memory allocation which then gets constantly reserved but isn't deallocated, the computer memory slowly
				 gets filled up with unusable memory. This is what's known as a memory leak.
*/


/*
	
	REVIEW
	-datatypes
		-void
		-integers
		-floating point numbers
		-characters
		-booleans
	
	-built-in functions
		-sizeof()
		
	-memory
		-heap
		-stack
		
*/
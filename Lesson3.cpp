//Lesson 3: Basic Operations

/*
	3 Types of Computing:
	-Sequential
		-Almost all programming languages must read from up to down
	
	-Iterative
		-Some code will run inside of a loop. Two types: for loops and while loops
	
	-Conditional
		-The segment of code will run only if a certain condition is met
*/
#include <stdlib.h>

int main()
{
	int a = 5;
	int b = 10;
	
	for (int i = 0; i < 10; i++)	//hints for for-loop: final value(10) - initial value(0) is the number of times the loop runs
	{								//maximum i value that can be used in loop is i == 9. Using <= instead of < will let loop run one more time
		a++;
		printf("%d, %d\n", a, i);
		/*
			Output:
			6, 0
			7, 1
			8, 2
			9, 3
			10, 4
			11, 5
			12, 6
			13, 7
			14, 8
			15, 9
		*/
	}
	//outside of for-loop, variable i doesn't exist
	
	while (b != 15)
	{
		b++;
	}
	printf("b = %d\n", b);	//should print b = 15
	
	
	if (a == b)	//run if a is equal to b
	{
		printf("a is equal to b\n");
	}
	if (a == b)	//run if a is equal to b
	{
		printf("Yay, it worked");
	}
	else if (a == b)	//run if a is equal to be AND if the previous if statement wasn't run
	{
		printf("This statement will never be printed\n");
		printf("This is because the if above will skip it\n");
	}
	else if (a > b)	//run if a is greater than b
	{
		printf("a is greater than b");
	}
	else	//run if nothing else is satisfied
	{
		printf("Doesn't satisfy any condition");
	}
	
	return 0;
}

/*

	Basic Operators:
	=		Set variable
	+		Add values
	-		Subtract values
	*		Multiply values
	/		Divide values
	%		Divides values but returns the remainder
	
*/

/*

	Compound Operators:
	a += b	(is the same as)	a = a + b
	a -= b	(is the same as)	a = a - b
	a *= b	(is the same as)	a = a * b
	a /= b	(is the same as)	a = a / b
	
	The ++ operator adds one to the variable
	The -- operator subtracts one to the variable
	
	int a = 0;
	a++;	//a is now 1
	a--;	//a is now 0
	
		-Positioning of the ++ and -- operators
			-Example: say b is 5
		a = b++;	//a will be set to 5 and then b has one added
		a = ++b;	//b has one added and then a will be set to 6
	

/*

	Basic Boolean Statements:
	==		Equivalence statement
	!=		Not Equal
	>		Greater Than
	<		Less Than
	>=		Greater Than or Equal To
	<=		Less Than or Equal To
	||		OR:		if either statement is true, return true
	&&		AND:	if either statement is false, return false
	
*/

/*

	Conditional Statements:
	
	if (condition1)			//if condition is true, run this. After, it will skip any lines that start with "else"
	{
		instruction
	}
	else if (condition2)		//if the first statement didn't satisfy condition, check this one
	{
		
	}
	else					//if and if-statements weren't satisfied, run this one
	{
		instruction
	}
	
	
	This is completely allowed to do:
			-this is typically done when multiple conditions may be satisfied. Unlike using the else-if statement, if the first one is satisfied,
			 it will continue to check all the other if statements rather than skip them.
	if (condition1)
	{
		
	}
	if (condition2)
	{
		
	}
	if (condition3)
	{
		
	}
	
*/

/*
	
	Loops:
	-Important thing to note for any loop structure. Any variables created inside of a loop will be placed on the stack and removed
	 after the loop ends. No variables should be created inside of a loop unless that result is intended to be erased later.
	 Placing and removing objects from the stack take processing time so variables should be created before if it can be helped.
	 
	
	-for loops
		-for loops are designed to run a set number of times
		-The initial instruction will run once at the start of the loop, the end-of-loop will run at the end of the instructions at every
		 iteration, and the loop will run as long as the condition in the middle is satisfied.
		
		for (initial instruction; conditional; end-of-loop instruction)			for (int i = 0; i < 5; i++)		//loop runs 5 times
		{																		{
			instructions
		}																		}
	
	
	-while loops
		-while loops will run as long as the condition is satisfied
		
		while (condition)
		{
			instruction
		}
	
	
	-do-while loops
		-In do-while loops, the command inside is run at least once before condition is checked
		-Remember that the condition is checked at the end of every loop, not at the beginning
		
		do
		{
			instruction
		} while (condition);
	
	
	-Infinite loops
		-these loops will run indefinitely. There are two ways to implement these
		
		while (true)		for (;;)
		{					{
			
		}					}
	
	-BREAKING LOOPS
		-if a loop must be suddenly broken but the end condition hasn't been met yet, the "break" command will instantly end the loop and the program will
		 continue.
		 
		for (int i = 0; i < 10; i++)
		{
			if (i == 5)
			{
				break;
			}
		}
		
*/
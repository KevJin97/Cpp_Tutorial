//Lesson 4: Creating functions

//Sometimes, writing a code that does advanced things all in one place can make the code hard to edit later down the road.
//Especially, if that operation is done repeatedly.

#include <stdlib.h>


void functionprototype();	//function prototype. Lets the code know that this function exists so that it can be defined later



void add(int num1, int num2, int num3)		//this function is fully defined and is ready to use
{
	num3 = num1 + num2;	//although c was inputted into num3, the value of c won't change in main()
	//void isn't returning any value so it will complete the tasks and then erase itself off the stack
}

void function();	//these are prototypes
void nestedfunction();

int main()
{
	int a = 10;
	int b = 5;
	int c = 0;
	//thiswontrun();	//this will create an error in the compiler. 
	
	add(a, b, c);	//calls function add() and sets num1 = a and num2 = b
	
	return 0;
}

void thiswontrun()	//this won't run because C++ runs sequentially so it checks above the text to see if the function has been created
{
	printf("won't run");
}

void functionprototype()	//the function prototype from before has been fully defined down here
{
	printf("This worked\n");
	//function prototypes are often used to keep the code cleaner and easier to manage
}


void function()
{
	nestedfunction();	//call the nestedfunction() function (see below)
}

void nestedfunction()
{
	printf("The function ran");	//another function can call a function that you wrote
}

/*
	The "void" declaration
	
	In C++, all functions must have a certain datatype that it returns so that it can "return" the value into the function that called it.
	In void functions, it's not allowed to return a value so it does all operations within itself. This is useful for checking some operations without
	changing any of the values in the main code.
	
	It is, however, able to manipulate and change the data outside of the function (as is every other function type). This makes void very useful to
	hold procedural information without having to return a value.
*/
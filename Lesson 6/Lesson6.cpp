//Lesson 6: Overloads and Overflows

#include <stdio.h>
int add(int a, int b);
double add(double a, double b);
//When a function is "overloaded", it means that the function name has more than one definition.
//This can often be used for having the function be able to handle different number of inputs or different data types
//If needed, the function can also contain a completely different instruction set

int main()
{
	int a = 0;
	//all data in computers are handled by bits. Since int is 4 bytes in most 64-bit systems, the range is -2147483648 to 2147483647
	//where (11111111 11111111 11111111 111111111) is -214783648 and (01111111 11111111 11111111 111111111) is 2147483647
	
	//signed refers to whether or not the first bit represents positive or negative_sign
	
	//when a variable overflows, it means that the variable has reached its maximum (or minimum) value possible so adding (or subtracting) one more will 
	//cause it to "overflow" meaning it won't be holding the expected value.
	
	int a = 2147483647;
	a++;
	printf("%d", a);
	
	return 0;
}

int add(int a, int b)
{
	return a + b;
}

double add(double a, double b)
{
	return a + b;
}
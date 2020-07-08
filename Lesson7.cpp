//Lesson 7: Pointers and Memory Addresses

/*
	When a variable is created, it is stored on the computer memory and it remembers where in the memory it's referenced by using a "memory address"
	If "int a" is declared, it reserves a memory address where the value of 'a' is stored.
	
	The variable name 'a' is simply for ease on our end. What the compiler really does is it reads 'a' in our code and knows to access the memory
	at an address it set aside for us.
	
	Say "int a" is declared. To see which part of the memory it has been reserved in, we use the syntax '&'. This returns the hexadecimal address where
	the data is stored. 
	
	Why hexadecimal when the computer is binary? The hexadecimal number structure goes from 0 to 15 (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, b, c, d, e). That means
	each hexadecimal "digit" represents 4 bits at a time. So a 16-bit system (2 bytes) can be represented by 4 hexadecimal numbers rather than 16 whole bytes.
	0x1ae9 == 0b(0001 1010 1110 1001)		Where 0x tells you it's hexadecimal and 0b says it's binary.
*/

/*
	Pointer variables are able to hold onto memory addresses of certain types.
	int *p_pointer;		The '*' in front of the int declaration declares that variable type to be a pointer of the integer type.
						This means that p_pointer can only hold memory addresses of the type "int".
						The "p_" is added as a reminder that the variable is a pointer and is completely optional.
	
	int a = 5;						p_a is now holding the memory address of 'a'.
	int *p_a; 						To access the data stored at memory address &a, we use '*' in front of the variable.
	p_a = &a; (or int *p_a = &a)
	printf("%d", *p_a);	
	
	
	Structure of the pointer:
						Pointer			Variable
		Memory Address	 0x00			   0x01
		Variable name	 p_a				a
		Value			 0x01				5
		
	a		returns 5
	&a 		returns 0x01
	
	p_a		returns 0x01
	&p_a 	returns 0x00
	*p_a 	returns 5
	
	
	We can take this one step further and create a pointer for a pointer (and so on and so on).
	This double pointer can only hold memory addresses of pointers of the same type.
	
	int a = 5;
	int *p_a = &a;
	int **pp_a = &p_a;
	
						Variable	Pointer		Double Pointer
		Memory Address	 0x00	   0x01			0x02
		Variable name	  a		    p_a			pp_a
		Value			  5			0x00		0x01
		
		a 		returns 5
		&a 		returns 0x00
		
		p_a		returns 0x00
		&p_a	returns 0x01
		*p_a	returns 5
		
		pp_a	returns 0x01
		&pp_a	returns 0x02
		*pp_a	returns 0x00
		**pp_a	returns 5
	
*/

#include <stdlib.h>

void add_one(int *p_pointer);	//application of pointers. void function can directly manipulate value of input (in this case 'a' declared in main() )

int main()
{
	int a;
	a = 9;
	
	printf("Value stored in a: %d\n", a);		//print value
	printf("Memory address of a: %p\n", &a);	//print memory address
	
	add_one(&a);	//pass memory address of 'a' instead of value of 'a'
	
	printf("Value in a is now: %d", a);
	
	return 0;
}

void add_one(int *p_pointer)
{
	p_pointer += 1;
}
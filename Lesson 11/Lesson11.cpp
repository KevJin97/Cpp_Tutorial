//Lesson 11: C vs C++

#include <stdio.h>
#include <iostream>
#include <string>
/*
	The previous vector structure created from before had one huge flaw: size could be accidentally accessed and changed.
	To prevent this from occurring, C++ implemented "class". Essentially, it is the same as a "struct" but creates a distinction
	between public and private data types.
	
	Public data and all functions in public are accessible by anything outside of the class. Private data, however, can only be accessed by the class members.
	This allows for size() to return size for viewing but doesn't allow anything except for the processes inside of vector to access the vectorsize variable.
	
	The concept of operator overloading is also a C++ addition as is exception handling.
	
	
	
	class vector
	{
	private:
		int *p_int;
		int vectorsize;
	
	public:
		vector();
		vector(int iarray[]);
		vector(vector in);
		~vector();
	
		void push_back(int value);
		void pop_back();
		int size();
		int dot(vector vec);
	
		void operator=(vector vec);
		vector operator+(vector vec);
		int operator[](int index);
	};
		
		ALL OTHER SYNTAXES REMAIN THE SAME
*/

/*
	The "wrapping," so to speak, of the functions and related processes inside of these classes is what's referred to as Object-Oriented Programming.
	The class is treated as its own object and comes with several functions that manipulate that class.
	
*/

/*
	C++ also added other functionalities to C offering it much more flexibility.
	
	Templates:
	-A way of taking one set of code and allowing that code to be compatible with any datatype.
	-So, instead of rewriting the same vector code for all known data types, templates offer a simple solution for any type of data, including
	 new classes that were built.
	
	Namespaces:
	-By having standard functions come in it's own "namespace," other functions can contain the same function name and the compiler won't have
	 any confusion about which function it's referring to.
	 
	Inheritance and Polymorphism
	-C++ allows for classes to "inherit" previously defined functionalities from other classes, and allows for its member functions to execute different
	 methods for each class by simply changing the type (polymorphism).
	-This will be covered in the next lesson.
*/

//creating templates

template<typename T>	//Just add this at the top to create a template. "typename T" declares what kind of data type it is.
class vector			//When in use, "vector<int> vec" will create a vector of type "int"
{
private:
	T *p_pointer;
	int vectorsize;

public:
	vector();
	vector(int iarray[]);
	vector(vector in);
	~vector();
	
	void push_back(int value);
	void pop_back();
	int size();
	T dot(vector vec);
	
	void operator=(vector vec);
	vector operator+(vector vec);
	T operator[](int index);
};

	//luckily, C++ offers a fully functional vector template library located in <vector> under the standard namespace.
	//to use, syntax is std::vector<"datatype"> "vectorname" and most of the functions we defined earlier should exist inside of the class
	

//creating namespaces

//namespaces allow developers to create functions and variables without having to worry about whether or not that name has already been used

namespace mynamespace	//this creates a namespace named "mynamespace"
{
	void printf()	//although stdio.h offers a printf() function, calling mynamespace::printf() will only print "I suck".. which is pretty useless but still
	{
		::printf("I suck");	//"::" is used to note that the function is called from outside the namespace since there's a functon in the namespace
							//with the same name
	}
}


/*
	Almost all standard libraries offered by C++ is located inside of the "std" namespace. This means that whenever a function is called from a standard
	library from C++, they must be specified that they exist in the std namespace.
	
	If typing std:: in front of every function and object is annoying (and it should be), the "using namespace" command can be added to add a namespace
	to the list of areas a compiler will search through when looking for a command.
*/


//Switching from C functions to C++ functions
/*
	C has stdio.h for its main input/output system. C++ has implemented a newer library called iostream. Although the stdio.h input/output functions
	are much faster than iostream (since iostream uses stdio.h as part of its functionality), iostream is much easier to use, without the need for
	string specifiers
*/

//std::cout		Console out: prints out without needing to know specifiers
//std::cin		Console in: receives inputs (also see: std::cin.getline)
//std::endl		Ends line (adds a \n at the end

using namespace std;	//to check the std namespace for all function calls

int main()
{
	string input;	//a part of the standard string library, similar to the vector library
	
	cout << "Hello world" << endl;
	cout << "Get input: ";
	cin >> input;
	cout << "You just typed in: " << input << endl;
	
	return 0;
}


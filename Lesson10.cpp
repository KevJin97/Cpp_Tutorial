//Lesson 10: New Datatypes

/*
	New datatypes can be created by combining any of the basic datatypes.
	
	struct person
	{
		char *p_name;		string for name
		int height[2];		height in feet and inches
		int age;			self-explanatory
		bool sex;			false: male, true: female
	};			<- note the comma
	
	
	Components are accessed by using the dot(.) operator
*/

struct person	//learn about the person struct before reading the vector section
{
	char *p_name;
	int height[2];
	int age;
	bool sex;
	
	void operator=(person otherperson);	//operator overload, see below main() after reading through main()
	
	void operator=(char *p_name);
	void operator=(int height[2]);
	void operator=(int age);
	void operator=(bool sex);
};


struct vector	//let's create a vector of ints. Since allocating memory doesn't let us know how much, we can create a data type that handles all that for us
{
	int *p_int;
	int vectorsize;	//note: can't create variable named size because there's a function with the same name
	
	vector();				//constructor
	vector(int iarray[]);	//constructor with parameters
	vector(vector in);		//constructor with parameters
	~vector();				//destructor
	
	void push_back(int value);
	void pop_back();
	int size();
	int dot(vector vec);
	
	void operator=(vector vec);
	vector operator+(vector vec);
	int operator[](int index);
};



int main()
{
	person personA;
	
	char *p_name = new char[5];
	p_name[4] = NULL;
	p_name = "John";
	
	personA.p_name = p_name;	//no need to delete p_name since personA will be holding it
	personA.height[0] = 5;
	personA.height[1] = 2;
	personA.age = 47;
	personA.sex = false;
	
	person personB;
	/*
		Say we want to set all the values of personA into personB. Usually, the statement personB = personA would work fine.
		However, the '=' operator has no idea what to do when a datatype "person" is called.
		The solution for this is to overload the '=' operator.
		
		Since '=' doesn't return any values and is purely procedural, it can be a type void. The operator overload prototype can be left in the
		struct declaration and defined outside of the struct declaration.
	*/
	personB = personA;
	
	person personC;
	
	personC = p_char;
	personC = {5, 2};
	personC = 47;
	personC = false;
	//note that all 3 people share the reserved memory address of p_char. That means that a change to p_char will change the name of all 3 people
	
	return 0;
}

void person::operator=(person otherperson)	//the "person::" prefix is just to let the compiler know that the overload is located in the struct "person"
{											//Of course, the function can be defined inside of the struct
	/*
		"operator" keyword signifies that the operator that follows it is going to be overloaded.
		
		"this" is a pointer that points at the struct. It specifies which one the recipient variable is.
		(*this).p_name is long to write so a shorthand notation was created:	this->p_name 	is equivalent to 	(*this).p_name
	
	*/
	this->p_name = otherperson.name;
	this->height[0] = otherperson.height[0];
	this->height[1] = otherperson.height[1];
	this->age = otherperson.age;
	this->sex = otherperson.sex;
}

/*
	In the main(), everyone can probably agree that it's annoying to type out all member variables of person when setting the values.
	To ease this, the operator '=' has been overloaded for every variable type (which is easy to do since all the types are different).
	This way, the statement personC = 56 can be written and it'd be valid rather than type of personC.age = 56 every single time.
*/

//notice how input names are identical to the member variables. Although, overloading variables isn't allowed, the "this" pointer allows us to specify
//which variable belongs to where
void person::operator=(char *p_char)
{
	this->p_char = p_char;
}

void person::operator=(int height[2])
{
	this->height[0] = height[0];
	this->height[1] = height[1];
}

void person::operator=(int age)
{
	this->age = age;
}

void person::operator=(bool sex)
{
	this->sex = sex;
}

//VECTOR FUNCTION DEFINITIONS
vector::vector()	//constructor
{
	/*
		What is a constructor?
		When a variable is created, it has an initialization process. Here, we specify what the datatype does when it's created but not initialized
		example code:
			vector a;		The vector a has been created but not initialized. So we should probably set some things so that it doesn't behave weird later on.
	*/
	
	//When it's created, it will automatically do the following;
	this->vectorsize = 0;
}

vector::vector(int iarray[])	//constructor with parameters
{
	/*
		Say the vector is created but then it gets initialized with an integer array. Now we must figure out how to manage this new input.
		example codes:
			vector a = iarray;
			vector a(iarray);		either one works
	*/
	this->vectorsize = sizeof(iarray) / sizeof(int);		//luckily, the input is an array so we can properly determine the size
	this->p_int = new int[vectorsize];
	
	for (int i = 0; i < this->vectorsize; i++)	//after allocating the appropriate amount of data, iarray components are copied into p_int
	{
		this->p_int[i] = iarray[i];	//again, "this->" is optional, but good habits
	}
}

vector::vector(vector in)
{
	//now the input is a vector. Luckily, it's easy to accomplish
	this->p_int = in.p_int;
	this->vectorsize = in.vectorsize;
}

vector::~vector()	//destructor
{
	/*
		What is a destructor?
		A destructor is what the function calls before it removes data off of the stack.
		Why do we need it?
		Notice that the vector has constructors that may allocate data. If the variable is removed off the stack without
		deallocating the memory, it could cause a memory leak.
		We can deallocate any memory here in the destructor so that the function can call this before it removes it from the stack.
	*/
	if (this->vectorsize != 0)	//if size isn't zero, that means memory has been allocated
	{
		delete[] this->p_char;
	}
}

void vector::push_back(int value)	//push_back() is a common function that adds a new component to the array
{
	this->vectorsize++;	//first we increase the size;
	
	int *p_hold = this->p_int;	//pointer holds onto the allocated memory
	
	this->p_int = new int[this->vectorsize];	//allocate new memory
	
	for (int i = 0; i < this->vectorsize - 1; i++)	//copy old data (which is one index smaller than the new one)
	{
		this->p_int[i] = p_hold[i];
	}
	delete[] p_hold;	//delete old memory
	
	p_hold[this->vectorsize - 1] = value;	//add the new component
}

void vector::pop_back()	//pop_back() is also a standard function that deletes the last component of the vector
{
	size--;	//decrease the size
	if (this->vectorsize > 0)	//let's make sure that the size isn't zero or less
	{
		int *p_hold = this->p_int;	//holds onto data from p_int
		this->p_int = new int[this->vectorsize];	//new smaller array space
		for (int i = 0; i < this->vectorsize; i++)	//copy data
		{
			this->p_int[i] = p_hold[i];
		}
		delete[] p_hold;
	}
	else	//if the size is zero, just erase everything
	{
		delete[] this->p_int;
	}
}
int vector::size()	//by calling this function, we can tell what size the vector is
{
	return this->vectorsize;	//just simply return the size... yeah, that's all
}

int vector::dot(vector vec)	//say we wanted to do a dot product
{
	int c = 0;
	if (this->vectorsize == vec.size())		//ensure the vectors are the same size
	{
		for (int i = 0; i < this->vectorsize; i++)	//add the multiplied components
		{
			c += this->p_int[i] * vec[i];	//[] operator overloaded later
		}
	}
	else
	{
		//this is where you put an error message
	}
	return c;
}
	
void vector::operator=(vector vec)	//overload for when = operator is used with another vector as input
{
	this->p_int = vec.p_int;
	this->vectorsize = vec.vectorsize;
}

vector operator+(vector vec);	//add two vectors
{
	vector added;
	
	if (this->vectorsize == vec.vectorsize)	//equal size
	{
		for (int i = 0; i < this->vectorsize; i++)
		{
			added.push_back(this->p_int[i] + vec[i]);	//[] operator defined later, push_back() defined earlier
		}
	}
	else
	{
		//this where an error message would go if needed
	}
	return added;
	//sample code: vector a = b + c;
}

int operator[](int index)	//in arrays, [] is used to return the value at a certain index. We will make it so vector does the same thing
{
	if ((index < this->vectorsize) && (index >= 0))	//if the inputted value isn't negative or greater than the max index allowed
	{
		return p_int[index];
	}
	else
	{
		//add an error
		return 0;	//it must return something
	}
}
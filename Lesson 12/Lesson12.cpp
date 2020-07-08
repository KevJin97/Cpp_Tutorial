//Lesson 12: Inheritance

/*
	There are 3 types of data classifications inside of the class.
	-public
		-anyone can access
	-private
		-only member functions can access
	-protected
		-private, but allows derived functions to also access
	
	So it stands to reason that there are also the same types of inheritance
	
	What is inheritance?
	Inheritance allows for classes to add additional functionalities or specifications to an existing class.
	
	class base
	{
	private:
		int x;
	
	protected:
		int y;
		
	public:
		int z;
	};
	
	class inherit : public base			Although inherit has nothing written inside of it, it is able to access y and z from base
	{
	
	};
	
	Public inheritance:		public inheritance will share all public data publically and protected data as protected
	-x	: inherit can't access x from base
	-y	: inherit can access y from base as protected
	-z	: inherit can access z from base as public
	
	Protected inheritance:	protetected inheritance will share all public data and protected data as protected
	-x	: inherit can't access x from base
	-y	: inherit can access y from base as protected
	-z	: inherit can access z from base as protected
	
	Private inheritance:	private inheritance will share public data and protected data privately
	-x	: inherit can't access x from base
	-y	: inherit can access y from base as private
	-z	: inherit can access z from base as private
	
*/

class Animal
{
protected:
	int age;
	
public:
	Animal(int age)	//constructor, is not inherited (since inheriting class won't necessarily be the same)
	{
		this->age = age;
	}
};

class Cat : public Animal	//publically inherit
{
protected:
	int number_of_legs;		//New data in addition this->age from Animal
	
public:
	Cat(int number_of_legs)
	{
		this->number_of_legs = number_of_legs;
	}
	Cat(int age)
	{
		this->age = age;	//Cat still has access to this->age from Animal
	}
};
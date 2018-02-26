#include"Domain.h"
//#include<sstream>
#include<assert.h>
//#include<iostream>
//#include<Windows.h>
using namespace std;

Animal::Animal(string breed, string name, int age, string photo)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photo = photo;
}

Animal::Animal(){}

string Animal::getBreed()
{
	return this->breed;
}

void Animal::setBreed(string breed)
{
	this->breed = breed;
}

string Animal::getName()
{
	return this->name;
}

void Animal::setName(string name)
{
	this->name = name;
}

int Animal::getAge()
{
	return this->age;
}

void Animal::setAge(int age)
{
	this->age = age;
}

string Animal::getPhoto()
{
	return this->photo;
}

void Animal::setPhoto(string photo)
{
	this->photo = photo;
}

string Animal::toString()
{
	string str = "";
	//string age = "";
	//stringstream ss;
	//ss << this->age;
	//ss >> age;
	str = "Breed: " + this->breed + "    Name: " + this->name + "    Age: " + to_string(this->age) + "    Photo link: " + this->photo + "\n";
	return str;
}

void testDomain()
{
	Animal a = Animal::Animal("Dog", "Rex", 10, "www.htp.com");
	assert(a.getName() == "Rex");
	assert(a.getAge() == 10);
	a.setName("Dada");
	assert(a.getName() == "Dada");
	//cout << a.toString() << endl;
}

/*
int main()
{
	testDomain();
	system("pause");
	return 0;
}
*/
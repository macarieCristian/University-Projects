#pragma once
#include<string>
#include<iostream>
#include<vector>
//using namespace std;

class Animal
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string photo;
	static int nrOfMaxInstances;
	static int nrOfCurInstances;

public:
	Animal(const std::string& breed, const std::string& name, int age,const std::string& photo);
	//constructor with params for the domain class

	Animal();
	//default constructor

	~Animal();
	//default destructor

	static int getNumCI() { return nrOfCurInstances; }
	static int getNumMI() { return nrOfMaxInstances; }
	static void decC() { nrOfCurInstances--; }
	static void incC() { nrOfCurInstances++; }
	static void incM() { nrOfMaxInstances++; }
	//getters and incrementers for the static variables

	std::string getBreed() const;
	void setBreed(std::string breed);
	//geter and seter for the breed atribute

	std::string getName() const;
	void setName(std::string name);
	//geter and seter for the name atribute

	int getAge();
	void setAge(int age);
	//geter and seter for the age atribute

	std::string getPhoto();
	void setPhoto(std::string photo);
	//geter and seter for the photo link atribute
	std::string toStringSimple();
	std::string toString();
	//function returning a nice looking string of the object

	void openLink();
	//open a link using chrome browser

	friend std::istream& operator >> (std::istream& is, Animal& a);
	friend std::ostream& operator<<(std::ostream& os, Animal& a);

	void Animal::testDomain();
};


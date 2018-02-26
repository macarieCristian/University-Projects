#include"Domain.h"
#include<sstream>
#include<assert.h>
//#include <shellapi.h>
#include<iostream>
#include<Windows.h>
//#include<vector>
using namespace std;

int Animal::nrOfCurInstances = 0;
int Animal::nrOfMaxInstances = 0;

Animal::Animal(const string& breed, const string& name, int age,const string& photo)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photo = photo;
	this->nrOfCurInstances++;
	this->nrOfMaxInstances++;
}

Animal::Animal(): breed(""), name(""), age(0), photo("") 
{
	//this->nrOfCurInstances++;
	//this->nrOfMaxInstances++;
}

Animal::~Animal()
{
	//this->nrOfCurInstances--;
}

string Animal::getBreed() const
{
	return this->breed;
}

void Animal::setBreed(string breed)
{
	this->breed = breed;
}

string Animal::getName() const
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

std::string Animal::toStringSimple()
{
	string str = "";
	str = "Breed: " + this->breed + "    Name: " + this->name + "    Age: " + to_string(this->age) + "\n";
	return str;
}

string Animal::toString()
{
	string str = "";
	//string age = "";
	//stringstream ss;
	//ss << this->age;
	//ss >> age;
	string lik = this->photo.substr(0, 40);
	str = "Breed: " + this->breed + "    Name: " + this->name + "    Age: " + to_string(this->age) + "    Photo link: " + lik + " ...\n";
	return str;
}

void Animal::openLink()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
}

void Animal::testDomain()
{
	Animal a = Animal::Animal("Dog", "Rex", 10, "www.htp.com");
	Animal b;
	assert(a.getBreed() == "Dog");
	assert(a.getName() == "Rex");
	assert(a.getAge() == 10);
	assert(a.getPhoto() == "www.htp.com");
	a.setBreed("d");
	a.setName("Dada");
	a.setAge(11);
	a.setPhoto("sal");
	assert(a.getBreed() == "d");
	assert(a.getName() == "Dada");
	assert(a.getAge() == 11);
	assert(a.getPhoto() == "sal");
	string str = a.toString();
	assert(this->getNumCI() == 1);
	assert(this->getNumMI() == 1);
	this->decC();
	this->incC();
	this->incM();
	assert(this->getNumCI() == 1);
	assert(this->getNumMI() == 2);
}

std::istream & operator >> (std::istream & is, Animal & a)
{
	string line,str;
	getline(is, line);
	stringstream ss(line);
	vector<string> res;
	while (getline(ss, str, ','))
		res.push_back(str);
	if (res.size() != 4)
		return is;
	a.breed = res[0];
	a.name = res[1];
	a.age = stoi(res[2]);
	a.photo = res[3];

	return is;
}

std::ostream & operator<<(std::ostream & os, Animal & a)
{
	os << a.breed << "," << a.name << "," << to_string(a.age) << "," << a.photo << "\n";
	return os;
}

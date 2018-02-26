#pragma once
#include<string>
using namespace std;

class Animal
{
private:
	string breed;
	string name;
	int age;
	string photo;

public:
	Animal(string breed, string name, int age, string photo);//constructor
	Animal();

	string getBreed();
	void setBreed(string breed);

	string getName();
	void setName(string name);

	int getAge();
	void setAge(int age);

	string getPhoto();
	void setPhoto(string photo);

	string toString();
};

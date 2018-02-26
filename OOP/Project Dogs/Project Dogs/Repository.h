#pragma once
#include<vector>
#include"Domain.h"

class Repository
{
private:
	std::vector<Animal> elem;
	int currPos;
	std::string filename;
public:

	Repository();
	Repository(const std::string& filename1) : filename(filename1){}

	void addElement(const Animal& a);
	//ads an object of type Animal to the vector

	void delElement(int pos);
	//delete an object of type Animal from the vector

	void updateElement(const Animal& a, int pos);
	//updates an object of type Animal from the vector

	int getLen();
	//returns the length of the vector

	Animal Repository::getCurrAnimal();
	//returns a copy of the animal which is on the current position

	void Repository::next();
	//increment the current position and simulate a circular list

	void Repository::Olink();
	//open a link using a browser

	int Repository::getCurPos();
	//returns the current position

	std::vector<Animal> &getElem() { return elem; }
	//return a reference to the vector of animals

	Animal& getElement(int pos);
	//returns a reference to the animal on the position pos from the vector

	//void SortAss();
	void sortAlg();
	//sort the vector ascending by name

	void readFromCSVFile();
	void writeToCSVFile();
	

	void testRep();

};
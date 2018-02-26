#include"Repository.h"
#include<iostream>
#include<assert.h>
#include<algorithm>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include"RepoExceptions.h"

using namespace std;

Repository::Repository()
{
	this->currPos = 0;
}

int Repository::getCurPos()
{
	return this->currPos;
}

void Repository::addElement(const Animal& a)
{
	this->elem.push_back(a);
	this->writeToCSVFile();
}

void Repository::delElement(int pos)
{
	this->elem.erase(elem.begin() + pos);
	this->writeToCSVFile();
}

void Repository::updateElement(const Animal & a, int pos)
{
	this->elem[pos] = a;
	this->writeToCSVFile();
}

Animal& Repository::getElement(int pos)
{
	return this->elem[pos];
}

void Repository::sortAlg()
{
	sort(elem.begin(), elem.end(), [](Animal &a1, Animal &a2) {return a1.getName() < a2.getName(); });
}

void Repository::readFromCSVFile()
{
	ifstream file(this->filename);
	if (!file.is_open())
		throw RepoExceptions("The file could not be opened!");
	Animal a;
	while (file >> a)
		this->elem.push_back(a);
	file.close();
}

void Repository::writeToCSVFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw RepoExceptions("The file could not be opened!");
	for (Animal a : this->elem)
		file << a;

	file.close();
}

int Repository::getLen()
{
	return this->elem.size();
}

Animal Repository::getCurrAnimal()
{
	return elem[this->currPos];
}

void Repository::next()
{
	this->currPos++;
	if (this->currPos == this->elem.size())
	{
		this->currPos = 0;
	}
}

void Repository::Olink()
{
	Animal a = this->getCurrAnimal();
	a.openLink();
}

void Repository::testRep()
{
	Repository rep{};
	assert(rep.getCurPos() == 0);
	Animal a{ "rara","rex",1,"www" };
	rep.addElement(a);
	assert(rep.getLen() == 1);
	Animal b{ "ra","rex",1,"www" };
	rep.updateElement(b, 0);
	assert(rep.getElement(0).getBreed() == "ra");
	rep.delElement(0);
	assert(rep.getLen() == 0);
	rep.addElement(a);
	rep.addElement(b);
	vector<Animal> v = rep.getElem();
	assert(v.size() == 2);
	Animal c = rep.getElement(0);
	rep.Olink();
	rep.next();
	rep.next();
	rep.next();
	assert(rep.getCurPos() == 1);
	rep.sortAlg();
}

/*void main()
{
	Repository r{};
	r.testRep();
}*/
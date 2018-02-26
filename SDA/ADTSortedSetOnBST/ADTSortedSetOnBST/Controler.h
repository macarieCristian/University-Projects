#pragma once
#include"SortedSet.h"



class Controler
{
private:
	SortedSet repo;
	friend int condi(Element a, Element b);
public:
	Controler(SortedSet& ss) : repo{ss}{}
	~Controler(){}

	SortedSet getElements() { return repo; }
	void addLicencePlate(std::string district, std::string number, std::string combination);
	void removeLicencePlate(std::string district, std::string number, std::string combination);
	void writeToFileDistrict(std::string fileName, std::string district);
	SortedSet& searchFilter(std::string str);

};




#include "Controler.h"
#include<fstream>

using namespace std;


void Controler::addLicencePlate(std::string district, std::string number, std::string combination)
{
	if (district.size() != 2 && district.size() != 1)
		throw exception("\nThe district must have 1 or 2 uppercase letters!\n\tex:(B,AB,CJ,...\n");
	if (number.size() != 3 && number.size() != 2)
		throw exception("\nThe number must be in the interval [00..999]\n");
	try
	{
		int x = stoi(number);
		if(x<0 || x>999)
			throw exception("\nThe number must be in the interval [00..999]\n");
	}
	catch (...)
	{
		throw exception("\nThe number must be in the interval [00..999]\n");
	}
	if (combination.size() != 3)
		throw exception("\nThe combination must have 3 letters!\n");
	Element e{ district,number,combination };
	if (!repo.insert(e))
		throw exception("\nThe given licence plate already exists!\n");
}

void Controler::removeLicencePlate(std::string district, std::string number, std::string combination)
{
	Element e{ district,number,combination };
	if (!repo.erase(e))
		throw exception("\nThe given licence plate does not exist!\n");
}

void Controler::writeToFileDistrict(std::string fileName, std::string district)
{
	ofstream file;
	file.open(fileName);
	if (!file.is_open())
		throw exception("The file could not be opened!");

	string s = "";
	file << "\tThe licence plates for the district: " + district + "\n\n";
	int nr = 0;
	for (auto it = repo.begin(); it != repo.end(); it++)
	{
		if (it.getCurrent().district == district)
		{
			s += it.getCurrent().toStringN() + "           ";
			nr++;
		}
		if (nr % 4 == 0)
		{
			s += "\n";
		}
	}
	file << s + "\n";
	file << "\nThe number of plates from this district: " + to_string(nr);

	file.close();
}

SortedSet& Controler::searchFilter(std::string str)
{
	SortedSet ss{ &condi };
	for (auto it = repo.begin(); it != repo.end(); it++)
	{
		if (it.getCurrent().district.find(str) !=-1 || it.getCurrent().number.find(str) != -1 || it.getCurrent().leters.find(str) != -1)
		{
			ss.insert(it.getCurrent());
		}
	}
	return ss;
}

int condi(Element a, Element b)
{
	if (a.district < b.district)
		return 1;
	else if (a.district > b.district)
		return 2;
	else
		if (a.number < b.number)
			return 1;
		else if (a.number > b.number)
			return 2;
		else
			if (a.leters < b.leters)
				return 1;
			else if (a.leters > b.leters)
				return 2;
			else
				return 0;
}

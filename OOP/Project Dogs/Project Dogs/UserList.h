#pragma once
#include"Domain.h"
#include<vector>

class UserList
{
protected:
	std::vector<Animal> list;
public:
	UserList();
	virtual ~UserList(){}

	void add(const Animal& a);
	//add an animal to the adoption vector

	std::vector<Animal> &getUList() { return list; }
	//returns a reference to the adoption vector

	int isInside(const Animal& a);
	//search for the animal a in the adoption list
	//if the animal exists the position where it is found in the vector is returned
	//otherwise the output is -1

	int getSize() { return this->list.size(); }
	//returns the size of the vector
	
	Animal UserList::getElem(int pos);
	//returns a copy of the animal situated on the position pos

	

	void testUList();
};


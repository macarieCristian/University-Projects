#pragma once
#include"DynamicArray.h"

class Repository
{
public:
	DynamicArray elem;

public:
	void addElement(Animal a);
	//ads a new element
	void delElement(int pos);
	//delete a element
	int getLen();
	Animal getElement(int pos);
};
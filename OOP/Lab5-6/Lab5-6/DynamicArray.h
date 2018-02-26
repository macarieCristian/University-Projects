#pragma once
#include"Domain.h"

class DynamicArray
{
public:
	Animal *array;
	int size;
	int capacity;
public:
	DynamicArray(int capacity);
	//constructor for the dynamic array
	void DynamicArray::resize();
	//to allocate more memory when needed

	void add(Animal a);
	//adds an animal object to the dynamic array
	void del(int pos);
	//delete an animal from the array
	int getSize();
	//return the size of the array
};
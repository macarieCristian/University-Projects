#pragma once
#include"Domain.h"

class DynamicArray
{
private:
	Animal *array;
	int size;
	int capacity;
public:
	DynamicArray(int capacity=10);
	//constructor for the dynamic array

	DynamicArray(const DynamicArray& v);
	//copy constructor for the dynamic array
	~DynamicArray();
	//destructor for the dynamic array

	DynamicArray& operator=(const DynamicArray& v);

	void add(const Animal &a);
	//adds an animal object to the dynamic array
	void del(int pos);
	//delete an animal from the array
	void update(const Animal &a, int pos);
	int getSize();
	//return the size of the array
	int getCapacity();
	Animal* getAllElements() const;

private:
	void DynamicArray::resize();
	//to allocate more memory when needed
};
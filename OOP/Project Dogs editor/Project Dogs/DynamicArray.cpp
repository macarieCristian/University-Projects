#include"DynamicArray.h"
#include<assert.h>

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->array = new Animal[capacity];
}

DynamicArray::DynamicArray(const DynamicArray& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->array = new Animal[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->array[i] = v.array[i];
}

DynamicArray::~DynamicArray()
{
	delete[] this->array;
}

DynamicArray& DynamicArray::operator=(const DynamicArray& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;
	
	delete[] this->array;
	this->array = new Animal[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->array[i] = v.array[i];

		return *this;
}

void DynamicArray::resize()
{
	this->capacity *= 2;

	Animal* biggerArr;
	biggerArr = new Animal[this->capacity];
	for (int i = 0; i < this->size; i++)
		biggerArr[i] = this->array[i];
	delete [] this->array;
	this->array = biggerArr;
}

void DynamicArray::add(const Animal &a)
{
	if (this->size == this->capacity)
		this->resize();
	this->array[this->size++] = a;

}

void DynamicArray::del(int pos)
{
	for (int i = pos; i < this->size - 1; i++)
		this->array[i] = this->array[i + 1];
	this->size--;
}

void DynamicArray::update(const Animal & a, int pos)
{
	this->array[pos] = a;
}

int DynamicArray::getSize()
{
	return this->size;
}

int DynamicArray::getCapacity()
{
	return this->capacity;
}

Animal* DynamicArray::getAllElements() const
{
	return this->array;
}

void test()
{
	Animal a = Animal::Animal("Dog", "Rex", 10, "www.htp.com");
	Animal b = Animal::Animal("Dog1", "Reex", 101, "www.htp.com");
	DynamicArray arr = DynamicArray(1);
	assert(arr.getCapacity() == 1);
	arr.add(a);
	assert(arr.getSize() == 1);
	arr.add(b);
	assert(arr.getCapacity() == 2);
	arr.del(1);
	assert(arr.getSize() == 1);
}

/*
int main()
{
	test();
	system("pause");
	return 0;
}
*/
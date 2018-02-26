#include"DynamicArray.h"
#include<assert.h>

DynamicArray::DynamicArray(int capacity)
{
	this->capacity = capacity;
	this->size = 0;
	this->array = new Animal[capacity];
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

void DynamicArray::add(Animal a)
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

int DynamicArray::getSize()
{
	return this->size;
}

void test()
{
	Animal a = Animal::Animal("Dog", "Rex", 10, "www.htp.com");
	Animal b = Animal::Animal("Dog1", "Reex", 101, "www.htp.com");
	DynamicArray arr = DynamicArray(1);
	assert(arr.capacity == 1);
	arr.add(a);
	assert(arr.getSize() == 1);
	arr.add(b);
	assert(arr.capacity == 2);
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
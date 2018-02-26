#pragma once
#include"Domain.h"
#include<assert.h>

template <class T>
class DynamicArray
{
private:
	T *array;
	int size;
	int capacity;

public:
	DynamicArray(int capacity = 10);
	//constructor for the dynamic array

	DynamicArray(const DynamicArray& v);
	//copy constructor for the dynamic array
	~DynamicArray();
	//destructor for the dynamic array

	DynamicArray& operator=(const DynamicArray& v);

	void add(const T &a);
	//adds an animal object to the dynamic array
	void del(int pos);
	//delete an animal from the array
	void update(const T &a, int pos);
	int getSize();
	//return the size of the array
	int getCapacity();
	T* getAllElements() const;

private:
	void DynamicArray::resize();
	//to allocate more memory when needed

};


	template <class T>
	DynamicArray<T>::DynamicArray(int capacity = 10)
	{
		this->capacity = capacity;
		this->size = 0;
		this->array = new T[capacity];
	}

	template <class T>
	DynamicArray<T>::DynamicArray(const DynamicArray& v)
	{
		this->size = v.size;
		this->capacity = v.capacity;
		//delete[] this->array;
		this->array = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->array[i] = v.array[i];
	}

	template <class T>
	DynamicArray<T>::~DynamicArray()
	{
		delete[] this->array;
	}

	template <class T>
	DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& v)
	{
		if (this == &v)
			return *this;

		this->size = v.size;
		this->capacity = v.capacity;

		delete[] this->array;
		this->array = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			this->array[i] = v.array[i];

		return *this;
	}

	template <class T>
	void DynamicArray<T>::resize()
	{
		this->capacity *= 2;

		T* biggerArr;
		biggerArr = new T[this->capacity];
		for (int i = 0; i < this->size; i++)
			biggerArr[i] = this->array[i];
		delete[] this->array;
		this->array = biggerArr;
	}

	template <class T>
	void DynamicArray<T>::add(const T &a)
	{
		if (this->size == this->capacity)
			this->resize();
		this->array[this->size++] = a;
		//Animal::incC();
		//Animal::incM();

	}

	template <class T>
	void DynamicArray<T>::del(int pos)
	{
		for (int i = pos; i < this->size - 1; i++)
			this->array[i] = this->array[i + 1];
		this->size--;
		Animal::decC();
	}

	template <class T>
	void DynamicArray<T>::update(const T & a, int pos)
	{
		this->array[pos] = a;
	}

	template <class T>
	int DynamicArray<T>::getSize()
	{
		return this->size;
	}

	template <class T>
	int DynamicArray<T>::getCapacity()
	{
		return this->capacity;
	}

	template <class T>
	T* DynamicArray<T>::getAllElements() const
	{
		return this->array;
	}

	/*void test()
	{
		Animal a = Animal::Animal("Dog", "Rex", 10, "www.htp.com");
		Animal b = Animal::Animal("Dog1", "Reex", 101, "www.htp.com");
		DynamicArray<Animal> arr = DynamicArray(1);
		assert(arr.getCapacity() == 1);
		arr.add(a);
		assert(arr.getSize() == 1);
		arr.add(b);
		assert(arr.getCapacity() == 2);
		arr.del(1);
		assert(arr.getSize() == 1);
	}*/




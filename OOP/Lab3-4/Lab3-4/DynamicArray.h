#pragma once
#include"Domain.h"


typedef Medication *Object;

typedef struct
{
	Object *list;
	int length;
	int capacity;
}DynamicArray;

DynamicArray *createDynamicArray(int capacity);
//create a dynamicaly allocated array structure

void destroyDynamicArray(DynamicArray *arr);
//free the memory

void add(DynamicArray *arr, Object m);
// ads an object to the array

void delete(DynamicArray *arr, int poz);
//deletes an object from the array

int getLength(DynamicArray *arr);
//returns the length of the dynamic array

Object get(DynamicArray *arr, int poz);
//returns the element on a given position

void testDynamicArray();
//tests
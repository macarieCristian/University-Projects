#pragma once
#include "medication.h"

typedef medication*TElement;

typedef struct {
	TElement * elems;
	int length;
	int capacity;

}DynamicArray;
DynamicArray* createDynamicArray(int capacity);
void addDynamic(DynamicArray* arr, TElement*t);
void delete(DynamicArray* arr, int pos);
int getLength(DynamicArray* arr);
TElement get(DynamicArray* arr, int pos);
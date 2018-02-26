#include "dynamicArray.h"
#include <malloc.h>
DynamicArray * createDynamicArray(int capacity)
{
	DynamicArray * d = (DynamicArray*)malloc(sizeof(DynamicArray));
	if (d == NULL)
		return NULL;
	d->capacity = capacity;
	d->length = 0;
	d->elems = (TElement*)malloc(sizeof(TElement)*capacity);
	return d;
}

void destroyArray(DynamicArray* d)
{
	if (d == NULL)return;
	free(d->elems);
	d->elems = NULL;
	free(d);
	d = NULL;
}

void resize(DynamicArray* d)
{
	if (d == NULL)
		return;

	d->capacity *= 2;
	d->elems = (TElement*)realloc(d->elems, d->capacity * sizeof(TElement));
}
void addDynamic(DynamicArray* arr, TElement*t)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	// resize the array, if necessary
	if (arr->length == arr->capacity)
		resize(arr);
	arr->elems[arr->length] = t;
	arr->length = arr->length + 1;
}

void delete(DynamicArray* arr, int pos)
{
	if (arr == NULL)
		return;
	if (arr->elems == NULL)
		return;

	for (int i = pos; i < arr->length - 1; i++)
		arr->elems[i] = arr->elems[i + 1];

	arr->length--;
}

int getLength(DynamicArray* arr)
{
	if (arr == NULL)
		return -1;

	return arr->length;
}

TElement get(DynamicArray* arr, int pos)
{
	return arr->elems[pos];
}
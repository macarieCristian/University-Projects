#include"DynamicArray.h"
#include <stdlib.h>
#include <assert.h>

DynamicArray *createDynamicArray(int capacity)
{
	//for the entire structure space
	DynamicArray *arr = (DynamicArray*)malloc(sizeof(DynamicArray));
	arr->capacity = capacity;
	arr->length = 0;

	//malloc returns null value if there was not enough space
	if (arr == NULL)
		return NULL;

	//for the elems we allocate space
	arr->list = (Object*)malloc(capacity * sizeof(Object));

	//same principle as above
	if (arr->list == NULL)
		return NULL;

	//returns the dynamicaly allocated structure
	return arr;
}

void destroyDynamicArray(DynamicArray *arr)
{
	if (arr == NULL)
		return;

	//free the memory for the list
	free(arr->list);
	arr->list = NULL;

	//free the memory for the structure
	free(arr);
	arr = NULL;
}

void resizeDynamicArray(DynamicArray *arr)
{
	if (arr == NULL)
		return;

	arr->capacity *= 2;
	arr->list = (Object*)realloc(arr->list, arr->capacity * sizeof(Object));
}


void add(DynamicArray *arr, Object m)
{
	if (arr == NULL)
		return;
	if (arr->list == NULL)
		return;

	//find out if it is time to resize the dynamic list
	if (arr->length == arr->capacity)
		resizeDynamicArray(arr);

	arr->length += 1;
	arr->list[arr->length] = m;
}

void delete(DynamicArray *arr, int poz)
{
	if (arr == NULL)
		return;
	if (arr->list == NULL)
		return;

	for (int i = poz; i < arr->length - 1; i++)
		arr->list[i] = arr->list[i + 1];

	arr->length--;
}

int getLength(DynamicArray *arr)
{
	return arr->length;
}

Object get(DynamicArray *arr, int poz)
{
	return arr->list[poz];
}

void testDynamicArray()
{
	DynamicArray *arr = createDynamicArray(1);
	assert(arr != NULL);

	assert(arr->capacity == 1);
	assert(arr->length == 0);

	Medication *m1 = createMedication("PAPA", 2.0, 11, 20);
	add(arr, m1);
	assert(arr->length == 1);

	Medication *m2 = createMedication("DADA", 1.0, 10, 12);
	add(arr, m2);
	assert(arr->length == 2);
	assert(arr->capacity == 2);

	delete(arr, 0);
	assert(arr->length == 1);

	
	destroyMedication(m1);
	destroyMedication(m2);
	destroyDynamicArray(arr);
}

int main()
{
	testDynamicArray();
	return 0;
}
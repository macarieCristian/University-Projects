#pragma once
#include "medication.h"
#include "dynamicArray.h"
typedef struct
{
	medication* medication;
	char* operationType;
}Operation;

typedef struct
{
	DynamicArray* operations;
}OperationStack;
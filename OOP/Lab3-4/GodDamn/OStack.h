#pragma once
#include"Domain.h"
#include<string.h>

typedef struct
{
	Medication *medic;
		char *operationType;
}Operation;

Operation* createOperation(Medication *m, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Medication* getMedication(Operation* o);





typedef struct
{
	Operation *listOperation[100];
	int length;
	int currentPos;
}OperationsStack;

OperationsStack* createStack();
void destroyStack(OperationsStack* s);
void push(OperationsStack* s, Operation* o);
Operation *popUndo(OperationsStack *s);
void dec(OperationsStack *s);
Operation *popRedo(OperationsStack *s);
int isEmpty(OperationsStack* s);
int isFull(OperationsStack* s);



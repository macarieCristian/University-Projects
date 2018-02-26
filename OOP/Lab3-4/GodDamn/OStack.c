#include"OStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

Operation *createOperation(Medication *m, char *type)
{
	Operation *o = (Operation*)malloc(sizeof(Operation));
	o->medic = copyMedication(m);

	if (type != NULL)
	{
		o->operationType = (char*)malloc(sizeof(strlen(type) + 1));
		strcpy(o->operationType, type);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o)
{
	if (o == NULL)
		return;

	// first destroy the planet
	destroyMedication(o->medic);
	// then the operationType
	free(o->operationType);
	// then free the operation
	free(o);
}

Operation* copyOperation(Operation * o)
{
	if (o == NULL)
		return NULL;

	Operation* newOp = createOperation(o->medic, o->operationType);
	return newOp;
}

char* getOperationType(Operation* o)
{
	return o->operationType;
}

Medication* getMedication(Operation* o)
{
	return o->medic;
}




OperationsStack *createStack()
{
	OperationsStack *s = (OperationsStack*)malloc(sizeof(OperationsStack));
	s->length = 0;
	s->currentPos = -1;
	return s;
}

void destroyStack(OperationsStack *s)
{
	if (s == NULL)
		return;

	for (int i = 0; i < s->length; i++)
		destroyOperation(s->listOperation[i]);
	free(s);
}

void push(OperationsStack *s, Operation *o)
{
	s->listOperation[s->length++] = copyOperation(o);
	s->currentPos += 1;
}

void dec(OperationsStack *s)
{
	s->currentPos -= 1;
}

Operation *popUndo(OperationsStack *s)
{
	if (s->currentPos > -1)
	{
		return s->listOperation[s->currentPos];
	}
	else return NULL;
}

Operation *popRedo(OperationsStack *s)
{
	if (s->currentPos < s->length)
	{
		return s->listOperation[s->currentPos];
	}
}

int isEmpty(OperationsStack* s)
{
	return (s->length == 0);
}

int isFull(OperationsStack* s)
{
	return s->length == 100;
}



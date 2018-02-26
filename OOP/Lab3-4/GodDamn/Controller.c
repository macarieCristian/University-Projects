#include"Controller.h"
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

Controller *createController(MedicationRepo* r, OperationsStack *undoS)
{
	Controller *c = (Controller*)malloc(sizeof(Controller));
	c->control = r;
	c->undoStack = undoS;
	return c;
}

void destroyController(Controller *c)
{
	destroyRepo(c->control);
	destroyStack(c->undoStack);
	free(c);
}

int addMedicine(Controller *c, char *name, float con, int quantity, int price)
{
	Medication *m = createMedication(name, con, quantity, price);

	int result = addElement(c->control, m);
	if (result == 1)
	{
		Operation *o = createOperation(m, "add");
		push(c->undoStack, o);
		destroyOperation(o);
	}
	return result;
}

int addMedicineNo(Controller *c, char *name, float con, int quantity, int price)
{
	Medication *m = createMedication(name, con, quantity, price);

	int result = addElement(c->control, m);
	return result;
}

int deleteMedicine(Controller *c, char *name, float con)
{
	int result = deleteElement(c->control, name, con);
	if (result == 1)
	{
		Medication *m = createMedication(name, con, 1, 1);
		Operation *o = createOperation(m, "del");
		push(c->undoStack,o);
		destroyOperation(o);
	}
	return result;
}

int deleteMedicineNo(Controller *c, char *name, float con)
{
	int result = deleteElement(c->control, name, con);
	return result;
}

int updateMedicine(Controller *c, char *name, float con, int quantity, int price)
{
	Medication *m = createMedication(name, con, quantity, price);
	Medication *m2 = find(c->control, name, con);
	int result = updateElement(c->control, m);
	if (result == 1)
	{
		Operation *o = createOperation(m2, "upp");
		push(c->undoStack, o);
		destroyOperation(o);
	}
	return result;
}

int updateMedicineNo(Controller *c, char *name, float con, int quantity, int price)
{
	Medication *m = createMedication(name, con, quantity, price);
	int result = updateElement(c->control, m);
	return result;
}

MedicationRepo *getAll(Controller *c)
{
	return c->control;
}

MedicationRepo *filterBySubstring(Controller *c, char substring[])
{
	MedicationRepo *result = createRepo();
	for (int i = 0; i < getRepoLength(c->control); i++)
	{
		Medication *m = c->control->repo->elems[i];
		if (strstr(getName(m), substring) != NULL)
		{
			Medication *newMedication = createMedication(m->name, m->concentration, m->quantity, m->price);
			addElement(result, newMedication);
		}
	}
	return result;
}

MedicationRepo *filterByQuantity(Controller *c, int quan)
{
	MedicationRepo *result = createRepo();
	for (int i = 0; i < getRepoLength(c->control); i++)
	{
		Medication *m = getElement(c->control, i);
		if (m->quantity < quan)
		{
			Medication *newMedication = createMedication(m->name, m->concentration, m->quantity, m->price);
			addElement(result, newMedication);
		}
	}
	return result;
}

int undo(Controller *c)
{
	if (c->undoStack->currentPos == -1)
		return 0;
	else
	{
		Operation *o = popUndo(c->undoStack);
		c->undoStack->currentPos -= 1;
		if (strcmp(getOperationType(o), "add") == 0)
		{
			Medication *m = getMedication(o);
			deleteMedicineNo(c, m->name, m->concentration);
		}
		else if (strcmp(getOperationType(o), "del") == 0)
		{
			Medication *m = getMedication(o);
			addMedicineNo(c, m->name, m->concentration, m->quantity, m->price);
		}
		else if (strcmp(getOperationType(o), "upp") == 0)
		{
			Medication *m = getMedication(o);
			updateMedicineNo(c, m->name, m->concentration, m->quantity, m->price);
		}
		return 1;
	}
}

int redo(Controller *c)
{
	if (c->undoStack->currentPos == c->undoStack->length-1)
		return 0;
	else
	{
		c->undoStack->currentPos += 1;
		Operation *o = popUndo(c->undoStack);
		if (strcmp(getOperationType(o), "add") == 0)
		{
			Medication *m = getMedication(o);
			addMedicineNo(c, m->name, m->concentration, m->quantity, m->price);
		}
		else if (strcmp(getOperationType(o), "del") == 0)
		{
			Medication *m = getMedication(o);
			deleteMedicineNo(c, m->name, m->concentration);
		}
		else if (strcmp(getOperationType(o), "upp") == 0)
		{
			Medication *m = getMedication(o);
			updateMedicineNo(c, m->name, m->concentration, m->quantity, m->price);
		}
		return 1;

	}
}

void testController()
{
	MedicationRepo *r = createRepo();
	OperationsStack *s = createStack();
	Controller *c = createController(r,s);
	addMedicine(c, "Para", 2.0, 12, 11);
	assert(getRepoLength(c->control) == 1);
	assert(getRepoLength(filterBySubstring(c, "a")) == 1);
	assert(getRepoLength(filterBySubstring(c, "o")) == 0);
}

/*
void main()
{
	testController();
	system("Pause");
	return 0;
}
*/
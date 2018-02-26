#include"Controller.h"
#include<string.h>

Controller *createController(MedicationRepo* r)
{
	Controller *c = (Controller*)malloc(sizeof(Controller));
	c->control = r;

	return c;
}

void destroyController(Controller *c)
{
	destroyRepo(c->control);
	free(c);
}

int addMedicine(Controller *c, char *name, float con, int quantity, int price)
{
	Medication *m = createMedication(name, con, quantity, price);

	int result = addElement(c->control, m);
	return result;
}

int deleteMedicine(Controller *c, char *name, float con)
{
	int result = deleteElement(c->control, name, con);
	return result;
}

int updateMedicine(Controller *c, char *name, float con, int quantity, int price, char *searchName, float searchCon)
{
	Medication *m = createMedication(name, con, quantity, price);
	int result = updateElement(c->control, m, searchName, searchCon);
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
		Medication *m = getElement(c->control, i);
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
			Medication *newMedication = createMedication(m->name,m->concentration,m->quantity,m->price);
			addElement(result, newMedication);
		}
	}
	return result;
}

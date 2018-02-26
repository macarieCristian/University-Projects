#include"Repository.h"
#include <stddef.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
//#include<Windows.h>


MedicationRepo *createRepo()
{
	MedicationRepo *r = (MedicationRepo*)malloc(sizeof(MedicationRepo));
	r->repo = createDynamicArray(10);

	return r;
}

void destroyRepo(MedicationRepo *r)
{
	for (int i = 0; i < getLength(r->repo); i++)
	{
		Medication *m = get(r->repo, i);
		destroyMedication(m);
	}
	destroyDynamicArray(r->repo);
	free(r);
}

Medication* find(MedicationRepo *r, char *name, float con)
{
	for (int i = 0; i < getLength(r->repo); i++)
	{
		Medication *m = get(r->repo, i);
		if (strcmp(m->name, name) == 0 && m->concentration == con)
			return m;
	}
	return NULL;
}

int index(MedicationRepo *r, char *name, float con)
{
	for (int i = 0; i <getLength(r->repo); i++)
	{
		Medication *m = get(r->repo, i);
		if (strcmp(m->name, name) == 0 && m->concentration == con)
			return i;
	}
	return -1;
}

int getRepoLength(MedicationRepo *r)
{
	return getLength(r->repo);
}

Medication * getElement(MedicationRepo *r, int poz)
{
	if (poz<0 || poz>getLength(r->repo))
		return NULL;
	return get(r->repo,poz);
}

int addElement(MedicationRepo *r, Medication *m)
{
	Medication *x = find(r, m->name, m->concentration);
	if ( x != NULL)
	{
		x->quantity += m->quantity;
		return 0;
	}
	Medication *copy = createMedication(m->name, m->concentration, m->quantity, m->price);
	add(r->repo, copy);

	return 1;
}

int updateElement(MedicationRepo *r, Medication *m, char *name, float con)
{
	Medication *x = find(r, name, con);
	if (x == NULL)
		return 0;
	strcpy(x->name, m->name);
	x->concentration = m->concentration;
	x->quantity = m->quantity;
	x->price = m->price;
	return 1;
}

int deleteElement(MedicationRepo *r, char *name, float con)
{
	int poz = index(r, name, con);
	if (poz != -1)
	{
		Medication *m = getElement(r, poz);
		//deallocates the memory
		destroyMedication(m);
		//erase the pointer
		delete(r->repo, poz);

		return 1;
	}
	return 0;
}

void sortAss(MedicationRepo *r)
{
	int ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i <getLength(r->repo) - 1; i++)
		{
			Medication *m1 = get(r->repo, i);
			Medication *m2 = get(r->repo, i + 1);
			if (strcmp(m1->name, m2->name) > 0)
			{
				Medication *aux = m1;
				m1 = m2;
				m2 = aux;
				ok = 0;
			}
		}
	}
}

void sortDes(MedicationRepo *r)
{
	int ok = 0;
	while (ok == 0)
	{
		ok = 1;
		for (int i = 0; i <getLength(r->repo) - 1; i++)
		{
			Medication *m1 = get(r->repo, i);
			Medication *m2 = get(r->repo, i + 1);
			if (strcmp(m1->name, m2->name) < 0)
			{
				Medication *aux = m1;
				m1 = m2;
				m2 = aux;
				ok = 0;
			}
		}
	}
}

//Tests

void testRepo()
{
	Medication *x = createMedication("Paracetamol", 2.0, 10, 20);
	Medication *y = createMedication("Paracetamol", 2.0, 20, 20);
	Medication *z = createMedication("Paracetamol", 2.0, 10, 12);
	MedicationRepo *r = createRepo();
	assert(getRepoLength(r) == 0);
	addElement(r, x);
	assert(getRepoLength(r) == 1);
	assert(getElement(r, 0)->concentration == 2.0);
	assert(getElement(r, 0)->quantity == 10);
	addElement(r, y);
	
	assert(getRepoLength(r) == 1);
	assert(getElement(r, 0)->quantity == 30);
	updateElement(r, z,"Paracetamol",2.0);
	
	assert(getElement(r, 0)->quantity == 10);
	assert(getElement(r, 0)->price == 12);

	assert(index(r, x->name, x->concentration) == 0);
	deleteElement(r, x->name, x->concentration);
	assert(getRepoLength(r) == 0);

}

/*
int main()
{
	testRepo();
	system("pause");
	return 0;
}
*/



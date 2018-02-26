#include "repository.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <assert.h>
Repository* newRepository()
{
	Repository* r = (Repository*)malloc(sizeof(Repository));
	r->medList = createDynamicArray(10);
	return r;
}

int getRepoLength(Repository* r)
{
	return r->medList->length;
}
void freeRepository(Repository*r)
{
	for (int i = 0; i < r->medList->length;i++)
	{
		freeMedication(r->medList->elems[i]);
	}
	free(r);
}

medication* findMedication(Repository* r, char* name, int concentration)
{
	for (int i = 0; i < r->medList->length; i++)
	{
		if ((strcmp(get(r->medList, i)->name, name) == 0) && (get(r->medList, i)->concentration = concentration))
			return get(r->medList, i);
	}
	return NULL;
}
int findPosition(Repository* r, char* name, int concentration)
{
	for (int i = 0; i < r->medList->length; i++)
	{
		if ((strcmp(get(r->medList,i)->name, name) == 0) && (get(r->medList,i)->concentration == concentration))
			return i;
	}
	return -1;
}
medication*  findOnPos(Repository* r,int pos)
{
	if ((pos>=0)&&(pos<r->medList->length))
		return get(r->medList,pos);
	else 
		return NULL;
}

int addNewMedication(Repository* r,medication*m)
{
	int res=1;
	if (findPosition(r, m->name, m->concentration) != -1)
	{
		r->medList->elems[findPosition(r, m->name, m->concentration)]->quantity = r->medList->elems[findPosition(r, m->name, m->concentration)]->quantity + m->quantity;
		res=0;
	}
	else 
	{
		medication* copy = copyMedication(m);
		addDynamic(r->medList, copy);
	}
	return res;
}
/*
void swap(Repository* r, int pos)
{
	if (pos >= 0)
	{
		medication* m = (medication*)malloc(sizeof(medication));
		m = r->medList[pos];
		r->medList[pos] = r->medList[r->length - 1];
		r->medList[r->length - 1] = m;


	}
}*/
void deleteMedication(Repository* r, char* name,int concentration)
{
	int pos = findPosition(r, name,concentration);
	if (pos >= 0)
	{
		medication* m = get(r->medList, pos);
		freeMedication(m);
		delete(r->medList, pos);
	}
}
int updateMedication(Repository* r, medication* m)/*the first to fields of the*/
{
	int pos = findPosition(r, m->name, m->concentration);
	if (pos >= 0)
	{
		r->medList->elems[pos] = m;
		return 1;
	}
	return 0;
}

void sort(Repository* r,operation o)
{
	for (int i = 0; i < getRepoLength(r)-1; i++)
	{
		for (int j = i+1; j < getRepoLength(r); j++)
		{
			if (o(r->medList->elems[i], r->medList->elems[j]) > 0)//condition for ascending alphabetically order
			{
				medication *m = r->medList->elems[i];
				r->medList->elems[i] = r->medList->elems[j];
				r->medList->elems[j] = m;
			}
		}
	}
}

void fillRepoForTest(Repository*r)
{
	medication*m = newMedication("Arcoxia", 100, 15, 20.4);
	addNewMedication(r, m);
	medication*k = newMedication("Milgamma", 250, 60, 10.8);
	addNewMedication(r, k);

}
void testAddRepo()
{
	Repository* repo = newRepository();
	fillRepoForTest(repo);
	assert(getRepoLength(repo) == 2);
	medication*m = newMedication("Milgamma", 250, 60, 10.8);
	assert(getRepoLength(repo) == 2);
	addNewMedication(repo, m);
	assert(repo->medList->elems[1]->quantity == 120);

}
void testDelete()
{
	Repository* repo = newRepository();
	fillRepoForTest(repo);
	deleteMedication(repo, "Milgamma", 25);
	assert(getRepoLength(repo) == 2);
	deleteMedication(repo, "Milgamma", 250);
	assert(getRepoLength(repo) == 1);
}
void testFind()
{
	Repository* repo = newRepository();
	fillRepoForTest(repo);
	assert(findPosition(repo, "Milgamma", 250) >=1);
	assert(findPosition(repo, "Milgamma", 25) == -1);
	assert(findOnPos(repo, 0)->concentration == 100);

}
void testUpdate()
{
	Repository* repo = newRepository();
	fillRepoForTest(repo);
	medication*m = newMedication("Milgamma", 250, 0, 0);
	assert(updateMedication(repo, m) == 1);
	assert(repo->medList->elems[1]->price == 0);
	medication*k = newMedication("Milgamma", 100, 60, 10.8);
	assert(updateMedication(repo, k) == 0);
}
/*
void testSwap()
{
	Repository* repo = newRepository();
	fillRepoForTest(repo);
	swap(repo, 0);
	assert(repo->medList->elems[0]->concentration ==250 );
}
*/
void testRepo()
{
	//testSwap();
	testUpdate();
	testFind();
	testDelete();
	testAddRepo();
}



#include "controller.h"
#include "repository.h"
#include <malloc.h>
#include <assert.h>
Controller* newController(Repository* repo)
{
	Controller*control = (Controller*)malloc(sizeof(Controller));
	control->repo = repo;
	return control;
}
Repository* getRepo(Controller* control)
{
	return control->repo;
}

void destroyController(Controller* control)
{
	freeRepository(control->repo);
	free(control);
}

int addMedication(Controller* control, char* name, int concentration, int quantity, float price)
{
	medication* m = newMedication(name, concentration, quantity, price);
	int suc = addNewMedication(control->repo, m);
	return suc;
}

int deleteMed(Controller* control, char* name, int concentration)
{
	int pos = findPosition(control->repo, name, concentration);
	if (pos != -1) {
		deleteMedication(control->repo, name, concentration);
		return 1;
	}
	return 0;

}





int update(Controller* control, char* name, int concentration, int quantity, float price)
{
	medication* m = newMedication(name, concentration, quantity, price);
	int success = updateMedication(control->repo, m);
	return success;

}
Repository* filterByString(Controller* control, char* needle)
{
	Repository*filtered = newRepository();
	if (strcmp(needle, "null") == 0)
	{
		filtered = control->repo;
	}
	else
	{
		for (int i = 0; i < getRepoLength(control->repo); i++)
		{
			medication* m = copyMedication(findOnPos(control->repo, i));
			char form[50];
			toStringForFilter(m, form);
			if(strstr(form,needle)!=0)
			addNewMedication(filtered, m);
		}
	}
	sort(filtered,&byName);
	return filtered;
}
Repository * filterByPrice(Controller* control, int price)
{
	Repository* filtered = newRepository();
	for (int i = 0; i < getRepoLength(control->repo); i++)
	{
		medication *m = copyMedication(findOnPos(control->repo, i));
		if (m->price < price)
			addNewMedication(filtered, m);
	}
	sort(filtered, &byName);
	return filtered;
}

Repository* filterByName(Controller* control, char* name)
{
	Repository* filtered = newRepository();
	for (int i = 0; i < getRepoLength(control->repo); i++)
	{
		medication*m = copyMedication(findOnPos(control->repo, i));
		if (strcmp(m->name, name) == 0)
			addNewMedication(filtered, m);
	}
	sort(filtered, &byConcentration);
	return filtered;
}

Repository* filterBySupply(Controller* control, int x)
{
	Repository* filtered = newRepository();
	for (int i = 0; i < getRepoLength(control->repo); i++)
	{
		medication* m = copyMedication(findOnPos(control->repo, i));
		if (m->quantity < x)
		{
			addNewMedication(filtered, m);
		}
	}
	return filtered;
}

Controller* createControllerForTest()
{
	Repository* r = newRepository();
	Controller* control = newController(r);
	addMedication(control, "Arcoxia", 100, 15, 20.4);
	addMedication(control, "Lioresal", 500, 40, 40);
	addMedication(control, "Milgamma", 250, 60, 10.8);
	addMedication(control, "Paracetamol", 750, 5, 10);
	addMedication(control, "Multivitamin", 50, 80, 50.1);
	addMedication(control, "Digoxin", 150, 40, 150);
	addMedication(control, "Diclofenac", 200, 100, 40);
	addMedication(control, "Aspirin", 500, 80, 20);
	addMedication(control, "Exorcizamus", 450, 3, 100);

	return control;
}

void testControlAdd()
{
	Controller* control = createControllerForTest();
	assert(addMedication(control,"Digoxin", 150, 40, 150) == 0);
	assert(addMedication(control, "else", 150, 40, 150) == 1);
	assert(getRepoLength(control->repo) == 10);
	assert(addMedication(control, "Digoxin", 15, 40, 150) == 1);
	assert(getRepoLength(control->repo) == 11);
	destroyController(control);

}
void testControlDelete()
{
	Controller* control = createControllerForTest();
	assert(deleteMed(control, "noname", 1) == 0);
	assert(deleteMed(control, "Digoxin", 150) == 1);
	assert(getRepoLength(control->repo) == 8);
	destroyController(control);

}
void testControlUpdate()
{
	Controller* control = createControllerForTest();
	assert(update(control, "Digoxin", 150, 100, 0) == 1);
	assert(getRepoLength(control->repo)== getRepoLength(control->repo));
	assert(update(control, "Digoxin", 1, 100, 0) == 0);
	medication *m = findMedication(control->repo, "Digoxin", 150);
	assert(m->price == 0);
	destroyController(control);

}
void testFilter()
{
	Controller* control = createControllerForTest();
	Repository* r = filterByString(control, "nevergonnafindme");
	assert(getRepoLength(r) == 0);
	Repository* p = filterByString(control, "goxin");
	assert(getRepoLength(p) == getRepoLength(p));
	Repository*q = filterByString(control, "in");
	assert(getRepoLength(q)== getRepoLength(q));
	Repository* w = filterByString(control, "null");
	assert(w == control->repo);
	//freeRepository(r);
	//freeRepository(p);
	destroyController(control);

}
void testFilterSupply()
{
	Controller* control = createControllerForTest();
	Repository*r = filterBySupply(control,-1);
	assert(getRepoLength(r) == 0);
	Repository*p = filterBySupply(control, 100000);
	printf("%d\n", getLength(p->medList));
	assert(getRepoLength(p) == 9);
	Repository*q = filterBySupply(control, 5);
	assert(getRepoLength(q) == 1);
	medication*m = findMedication(q, "Exorcizamus", 450);
	assert(m != NULL);
	destroyController(control);


}

void testController()
	
{
	testControlAdd();
	testControlDelete();
	testControlUpdate();
	testFilter();
	testFilterSupply();
}

#pragma once
#include "accept.h"
#include "medication.h"
#include "dynamicArray.h"
typedef struct
{
	DynamicArray* medList;
}Repository;
/*create a repository instance, and return a pointer to it*/
Repository* newRepository();

/*free memory occuppied by repo*/
void freeRepository(Repository*r);

int getRepoLength(Repository* r);

/*update medication m of repo r
the first two fields of m are the ones that define which medication has to be updated
the other ones are the changeable ones, those will be updated*/
int updateMedication(Repository* r, medication* m);

/*delete medication from repo r defined by name and concentration
first we find this element, then swap it with the last one, and decrement the length of r*/
void deleteMedication(Repository* r, char* name, int concentartion);

/*swap the medication on pos with the last one
this method is used for deletion*/
void swap(Repository* r, int pos);

/*add medication m to repo r*/
int addNewMedication(Repository* r, medication*m);

/*find position of a medication in repo r, determined by its name and concentration*/
int findPosition(Repository* r, char* name, int concentration);

/*find a medication in repo and return  pointer to it if it is in teh repo*/
medication* findMedication(Repository* r, char* name, int concentration);

/*get a position and return  a pointer to the pos-th element of the repo r
first we also check if the position is valid or not, if it is not, return NULL*/
medication*  findOnPos(Repository* r, int pos);

/*sort alphabetically the medications of repo r by their name*/
void sort(Repository* r,operation o);

/*test*/
void fillRepoForTest(Repository*r);
void testRepo();
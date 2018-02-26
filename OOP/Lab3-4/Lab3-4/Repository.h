#pragma once
#include"DynamicArray.h"

typedef struct
{
	DynamicArray *repo;
}MedicationRepo;

MedicationRepo *createRepo();
//creates a dinamicaly allocated Medication repo struct

void destroyRepo(MedicationRepo *r);
//frees the memory allocated

Medication* find(MedicationRepo *r, char *name, float con);
/*finds out if the medication with the given name and concentration
is already in the repository
input the name and concentration of the searched medication
output the founded medication or null value
*/

int index(MedicationRepo *r, char *name, float con);
//returns the index of an element in the repo vector or -1

int getRepoLength(MedicationRepo *r);
//returns the lenght of the arr

Medication * getElement(MedicationRepo *r, int poz);
//returns the medication on the poz position

int addElement(MedicationRepo *r, Medication *m);
/*adds an new element or update it if it already exists*/

int updateElement(MedicationRepo *r, Medication *m, char *name, float con);
//updates the quantity and the price of the medication
//having the given name and concentration

void sortAss(MedicationRepo *r);
//sort asscending the repo

void sortDes(MedicationRepo *r);
//sort descending the repo

int deleteElement(MedicationRepo *r, char *name, float con);
//deletes the element with the given anme and concentration

void testRepo();



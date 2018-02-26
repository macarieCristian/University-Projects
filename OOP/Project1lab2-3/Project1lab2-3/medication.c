#include "medication.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
medication* newMedication(char* name, int concentartion, int quantity, float price)
{
	medication* m = (medication*)malloc(sizeof(medication));
	m->name = (char*)malloc(strlen(name) + 1);//sizeof +2 becaues of the 0 in the end
	strcpy(m->name, name);
	m->concentration = concentartion;
	m->quantity = quantity;
	m->price = price;
	return m;

}
medication* copyMedication(medication*m)
{
	if (m == 0)return NULL;
	medication* med = newMedication(getName(m), getConcentration(m), getQuantity(m), getPrice(m));
	return med;
}

void freeMedication(medication* m)
{
	free(m->name);//free the character array
	free(m);
}


char* getName(medication* m)
{
	return m->name;
}
int getConcentration(medication* m)
{
	return m->concentration;
}

int getQuantity(medication* m)
{
	return m->quantity;
}

float getPrice(medication* m)
{
	return m->price;
}

void medicationToString(medication* m, char res[])
{
	sprintf(res, "name: %s, concentartion %d mg, quantity %d boxes, price $ %.f",m->name,m->concentration,m->quantity,m->price);
}
void toStringForFilter(medication*m, char res[])
{
	sprintf(res, "%s %d %d %.f", m->name, m->concentration, m->quantity, m->price);
}

void testMedication()
{
	medication *m = newMedication("testMed", 1, 2, 3);
	assert(strcmp(getName(m),"testMed")==0);
	assert(getConcentration(m) == 1);
	assert(getQuantity(m) == 2);
	assert(getPrice(m) == 3);
	char test[50];
	toStringForFilter(m, test);
	assert(strcmp(test, "testMed 1 2 3") == 0);


}
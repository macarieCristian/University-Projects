#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"Domain.h"
//#include<Windows.h>


Medication *createMedication(char *name, float concentration, int quantity, int price)
{
	Medication *m = (Medication*)malloc(sizeof(Medication));
	m->name = (char*)malloc(strlen(name) + 1);
	strcpy(m->name, name);
	m->concentration = concentration;
	m->quantity = quantity;
	m->price = price;

	return m;
}

void destroyMedication(Medication *m)
{
	free(m->name);
	free(m);
}

Medication *copyMedication(Medication *m)
{
	Medication *newMedication = createMedication(m->name, m->concentration, m->quantity, m->price);
	return newMedication;
}

char* getName(Medication *m)
{
	return m->name;
}

float getConcentration(Medication *m)
{
	return m->concentration;
}

int getQuantity(Medication *m)
{
	return m->quantity;
}

int getPrice(Medication *m)
{
	return m->price;
}

void toString(Medication *m, char str[])
{
	sprintf(str, "\tMedication name: %s,  Concentration: %.2f,  Quantity: %d,  Price: %d;\n", m->name, m->concentration, m->quantity, m->price);
}

/*
int main()
{
Medication *m = createMedication("Paracetamol", 1.2, 11, 20);
char str[200];
toString(m, str);
printf("%s", str);
destroyMedication(m);
system("pause");
return 0;
}
*/
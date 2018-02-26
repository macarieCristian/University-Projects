#pragma once

typedef struct
{
	char *name;
	float concentration;
	int quantity;
	int price;
} Medication;

Medication *createMedication(char *name, float concentration, int quantity, int price);
/*creates a new object of type medication allocating the needed
space;
input the name string, the concentration float, the quantity int, the float price;
output the Medication object*/

void destroyMedication(Medication *m);
//free the previously allocated memory;

Medication *copyMedication(Medication *m);

char* getName(Medication *m);
float getConcentration(Medication *m);
int getQuantity(Medication *m);
int getPrice(Medication *m);

void toString(Medication *m, char str[]);
/*prepare the result in a nice looking string good for printing;*/
#pragma once
typedef struct
{
	char* name;
	int concentration;
	int quantity;
	float price;

}medication;

/*create a new medication
input-name, concentration, quantity,price-the fields of
the medication instance that is created
output-pointer to the medication instance made out of the fields*/
medication* newMedication(char* name, int concentration, int quantity,float price);

/*free memory ocuupied by a medication instance */
void freeMedication(medication* m);

/*return medication name*/
char* getName(medication* m);
/*returns medications concentration*/
int getConcentration(medication* m);
/*returns medications quantity*/
int getQuantity(medication* m);
/*retuns medicaions price*/
float getPrice(medication* m);
/*make a user-readable form out of a medication, and put it in a string*/
void medicationToString(medication* m, char res[]);
/*makes a string out of the fields of a medication, this time for being able to parse trough it
when filtering by a string.This way the other string components fom the function above does not confuse us*/
void toStringForFilter(medication*m, char res[]);
medication* copyMedication(medication*m);
void testMedication();
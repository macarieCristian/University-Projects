#pragma once
#include"Repository.h"

typedef struct
{
	MedicationRepo *control;
}Controller;

Controller *createController(MedicationRepo* r);
void destroyController(Controller *c);

int addMedicine(Controller *c, char *name, float con, int quantity, int price);
/*Adds a new medicine to the medicine repository
input:
c = pointer to the controller
name = name of the medicine
con = float concentration of the medicine
quantity = the number of available medicine
price = the price of the medicine
output:
1 = if the medicine was sucesfully added 
0 = if the medicine already existed and it was updated (only the quantity)*/

int deleteMedicine(Controller *c, char *name, float con);
/*deletes a medicine from the repository
input:
c = pointer to the controller
name = name of the medicine to be deleted
con = concentration of the medicine to be deleted
output:
1 = if the medicine was deleted
0 = if the medicine does not exists
*/

int updateMedicine(Controller *c, char *name, float con, int quantity, int price, char *searchName, float searchCon);
/*update the medicine with the given name and concentration
the searchName and searchCon refers to the searched medicine
output:
1 = if the medicine was updated
0 = if the medicine does not exists
*/

MedicationRepo *getAll(Controller *c);

MedicationRepo *filterBySubstring(Controller *c, char substring[]);
//returns a repo with all the medicine objects which contains the substring in their name

MedicationRepo *filterByQuantity(Controller *c, int quan);
//returns a repo with all the medicines which have a quantity less than quan

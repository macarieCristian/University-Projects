#pragma once
#include "repository.h"
#include <malloc.h>
#include "accept.h"
typedef struct
{
	Repository * repo;
}Controller;
/*create a controller by allocation memory for it and return a pointer to it*/
Controller* newController(Repository* repo);

/*destroy controller pointed at by *control*/
void destroyController(Controller* control);

/*add medication to repo of controller
name, conc...price are fields of medication that is created inside function
if the medication already exists and is inside the repo of control, we just add its quantity to the new one*/
int addMedication(Controller* control, char* name, int concentration, int quantity, float price);

/*delete medication from controllers repository*/
int deleteMed(Controller* control, char* name, int concentration);

/*update medication
name and concentration adefine which medication to be updated
the other fields will be cthe new ones
return 1 if succesfull, 0 otherwisw*/
int update(Controller* control, char* name, int concentration, int quantity, float price);

/*returns a repository containing
pointers to those medications that contain the string needle, sorted alphabetically*/
Repository* filterByString(Controller* control, char* needle);

/*returns a repo caontaining pointers to all medications  from the repo of controller that have a supply less then x*/
Repository* filterBySupply(Controller* control, int x);

/*returns a repo with pointers to all medications from repo of controller that have a specific name, sorted ascending by concentration*/
Repository* filterByName(Controller* control, char* name);

Repository * filterByPrice(Controller* control, int price);
/*test*/
void testController();
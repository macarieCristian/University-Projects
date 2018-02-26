#pragma once
#include "medication.h"
typedef int(*operation)(int, int);


/*accpetance functions for sorting, this returns true if m's name is before n's alphabetically, 0 otherwise*/
int byName(medication*m, medication*n);

int byNameDescending(medication*m, medication* n);
/*this accetance function returns 1 if m's concentration is greater than n's*/
int byConcentration(medication*m, medication*n);

int byConcentrationDescending(medication*m, medication*n);

int byQuantityDescending(medication*m, medication* n);

int byQuantity(medication*m, medication* n);

int byPriceDescending(medication*m, medication* n);
int byPrice(medication*m, medication* n);


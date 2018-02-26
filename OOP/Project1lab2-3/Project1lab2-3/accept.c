#include "accept.h"

int byName(medication*m, medication*n)
{
	if (strcmp(m->name, n->name) > 0)
		return 1;
	return 0;
}
int byConcentration(medication*m, medication*n)
{
	if (m->concentration>n->concentration)
		return 1;
	return 0;
}

int byNameDescending(medication*m, medication*n)
{
	if (strcmp(m->name, n->name) < 0)
		return 1;
	return 0;
}

int byConcentrationDescending(medication*m, medication* n)
{
	if (m->concentration<n->concentration)
		return 1;
	return 0;
}
int byQuantity(medication*m, medication* n)
{
	if (m->quantity>n->quantity)
		return 1;
	return 0;
}
int byQuantityDescending(medication*m, medication* n)
{
	if (m->quantity < n->quantity)
		return 1;
	return 0;
}

int byPrice(medication*m, medication* n)
{
	if (m->price>n->price)
		return 1;
	return 0;
}
int byPriceDescending(medication*m, medication* n)
{
	if (m->price < n->price)
		return 1;
	return 0;
}
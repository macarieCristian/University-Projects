#include"Repository.h"

void Repository::addElement(Animal a)
{
	this->elem.add(a);
}

void Repository::delElement(int pos)
{
	this->elem.del(pos);
}

Animal Repository::getElement(int pos)
{
	return this->elem.array[pos];
}

int Repository::getLen()
{
	return this->elem.getSize();
}

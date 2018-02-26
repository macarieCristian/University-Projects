#include "Repository.h"
#include<string>

using namespace std;

Repository::Repository()
{
	this->len = 0;
}

void Repository::add(Task t)
{
	this->list[this->len++] = t;
}

Task & Repository::getTask(int pos)
{
	return this->list[pos];
}

void Repository::sortDes()
{
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (int i = 0; i < this->len - 1; i++)
			if (this->list[i].getDuration() < this->list[i + 1].getDuration())
			{
				Task t = this->list[i];
				this->list[i] = this->list[i + 1];
				this->list[i + 1] = t;
				ok = true;
			}
	}
}

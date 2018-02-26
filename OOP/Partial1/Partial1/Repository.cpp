#include "Repository.h"
#include<assert.h>



Repository::Repository()
{
	len = 0;
}

void Repository::add(Song s)
{
	list[len++] = s;
}

Song & Repository::getSong(int pos)
{
	return list[pos];
}

void Repository::sortName()
{
	bool ok = true;
	while (ok)
	{
		ok = false;
		for (int i = 0; i < this->len - 1; i++)
			if (list[i].getName() > list[i + 1].getName())
			{
				Song aux = list[i];
				list[i] = list[i + 1];
				list[i + 1] = aux;
				ok = true;
			}
	}
}

void testadd()
{
	Repository r{};
	Song s1;
	Song s2;
	assert(r.getLen() == 0);
	r.add(s1);
	assert(r.getLen() == 1);
	r.add(s2);
	assert(r.getLen() == 2);

}




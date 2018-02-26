#include "UserList.h"
#include<algorithm>
#include<assert.h>

using namespace std;

UserList::UserList()
{
}

void UserList::add(const Animal & a)
{
	this->list.push_back(a);
}

int UserList::isInside( const Animal & a)
{
	auto it = find_if(list.begin(), list.end(), [&a](Animal &an) {return (an.getBreed() == a.getBreed()) && (an.getName() == a.getName()); });
	if (it == list.end())
		return -1;
	return distance(list.begin(), it);
}

Animal UserList::getElem(int pos)
{
	return this->list[pos];
}

void UserList::testUList()
{
	UserList ul{};
	Animal a{ "rara","rex",1,"www" };
	Animal b{ "ri","ra",1,"www" };
	assert(ul.getSize() == 0);
	ul.add(a);
	assert(ul.getSize() == 1);
	assert(ul.isInside(a) == 0);
	assert(ul.isInside(b) == -1);
	Animal x = ul.getElem(0);
	vector<Animal> v = ul.getUList();
	assert(v.size() == 1);
}

/*void main()
{
	UserList ul{};
	ul.testUList();
}*/






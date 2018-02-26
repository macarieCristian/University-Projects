#include "Controller.h"
#include<string>
#include<iostream>
#include<assert.h>

using namespace std;





int Controller::findSong(std::string name)
{
	for (int i = 0; i < repo.getLen(); i++)
		if (repo.getSong(i).getName() == name)
			return i;
	return -1;
}

int Controller::addSong(std::string name, std::string lista[50], int len)
{
	if (findSong(name) != -1)
		return 0;
	Song s{ name,lista,len };
	repo.add(s);
	return 1;
}

Song Controller::newSong(int p1, int p2)
{
	Song s1 = this->repo.getSong(p1);
	Song s2 = this->repo.getSong(p2);
	string list[50];
	int len = 0;
	//string name1 = s1.getName().substr(0, s1.getName().length() / 2);
	string n1 = s1.getName();
	string name1 = n1.substr(0, n1.length() / 2);
	//cout << name1 + "n1";
	//string name2 = s2.getName().substr(s2.getName().length()/2, s2.getName().length());
	string n2 = s2.getName();
	string name2 = n2.substr(n2.length() / 2, n2.length() - 1);
	//cout << name2 + "n2";
	string name = name1 +"/"+ name2;
	//cout << name;
	for (int i = 0; i < s1.getLenNotes() / 2; i++)
	{
		list[len] = s1.getNotes()[i];
		len++;
	}
	for (int i = s2.getLenNotes() / 2; i < s2.getLenNotes(); i++)
	{
		list[len] = s2.getNotes()[i];
		len++;
	}
	Song ss{ name,list,len };
	return ss;

}

/*std::string Controller::mostUsed()
{
	int l[10];
	for (int k = 0; k < 9; k++)
		l[k] = 0;
	for (int i = 0; i < repo.getLen(); i++)
	{
		Song s = repo.getSong(i);
		for (int j = 0; j < s.getLenNotes(); j++)
		{
		
		}
	}

}*/

void test()
{
	Repository r{};
	Controller c{ r };
	string list[10];
	list[0] = "do";
	list[2] = "re";
	int res = c.addSong("ceva", list, 2);
	assert(res == 1);
	int res1 = c.addSong("ceva", list, 2);
	assert(res == 0);


}

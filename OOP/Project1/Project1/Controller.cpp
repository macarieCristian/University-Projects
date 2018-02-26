#include "Controller.h"

using namespace std;

int Controller::findTask(string description)
{
	for (int i = 0; i < this->repo.getLen(); i++)
	{
		if (this->repo.getTask(i).getDescription() == description)
			return i;
	}
	return -1;
}

int Controller::addTask(std::string des, int duration, int priority)
{
	if (this->findTask(des) != -1)
		return 0;
	Task t{ des,duration,priority };
	this->repo.add(t);
	return 1;
}

int Controller::swap(std::string s1, std::string s2)
{
	int p1 = this->findTask(s1);
	int p2 = this->findTask(s2);
	if (p1 == -1 || p2 == -1)
		return 0;
	if (this->repo.getTask(p1).getPriority() == this->repo.getTask(p2).getPriority())
		return 0;
	int aux = this->repo.getTask(p1).getPriority();
	this->repo.getTask(p1).setPriority(this->repo.getTask(p2).getPriority());
	this->repo.getTask(p2).setPriority(aux);
	return 1;
}

Repository Controller::filter(int num)
{
	Repository r{};
	for(int i=0; i<this->repo.getLen();i++)
		if (this->repo.getTask(i).getPriority() < num)
		{
			Task t = this->repo.getTask(i);
			r.add(t);
		}
	return r;
}

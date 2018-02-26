#pragma once
#include"Repository.h"



class Controller
{
private:
	Repository repo;
public:
	Controller(Repository& repos) : repo(repos) {}

	int findTask(std::string description);

	int addTask(std::string des, int duration, int priority);

	int swap(std::string s1, std::string s2);

	Repository filter(int num);

	Repository& getRepo() { return this->repo; }
};


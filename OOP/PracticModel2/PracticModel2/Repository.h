#pragma once
#include<vector>
#include<algorithm>
#include"Task.h"
#include"Programer.h"
#include"Observer.h"
#include<exception>


class Repository : public Observable
{
private:
	std::vector<Programer> Pvec;
	std::vector<Task> Tvec;
public:
	Repository()
	{
		readProgramatorsFromFile();
		readTasksFromFile();
	}
	~Repository()
	{
		writeTasksToFile();
	}

	void addTask(std::string description);
	void removeTask(std::string description);
	void startTask(Programer p, std::string description);
	void closeTask(Programer p, Task t);

	void readProgramatorsFromFile();
	void readTasksFromFile();
	void writeTasksToFile();

	void sortTaskByStatus();


	std::vector<Programer>& getPvec() { return Pvec; }
	std::vector<Task>& getTvec() { return Tvec; }
};


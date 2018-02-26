#include "Repository.h"
#include<fstream>
#include<sstream>

using namespace std;

void Repository::addTask(std::string description)
{
	Task t{0, description, "open" };
	Tvec.push_back(t);
	notify();
}

void Repository::removeTask(std::string description)
{
	auto it = find_if(Tvec.begin(), Tvec.end(), [description](Task t) {return t.getDescription() == description; });
	if (it != Tvec.end())
	{
		Tvec.erase(it);
		notify();
	}
	
}

void Repository::startTask(Programer p, std::string description)
{
	for (Task& t : Tvec)
	{
		if (t.getDescription() == description)
		{
			if (t.getStatus() != "open")
				throw exception("Can't start this task!");
			t.setId(p.getId());
			t.setStatus("in progress");
			t.setProgName(p.getName());
			notify();
			break;
		}
	}
}

void Repository::closeTask(Programer p, Task t)
{
	if (p.getId() != t.getId() || t.getStatus()!="in progress")
		throw exception("You can't close this task!");
	for(Task& ta: Tvec)
		if (ta.getDescription() == t.getDescription())
		{
			ta.setStatus("closed");
			notify();
		}
}


void Repository::readProgramatorsFromFile()
{
	ifstream file;
	file.open("Programers.txt");

	string line, aux;
	while (getline(file, line))
	{
		vector<string> v;
		stringstream ss(line);
		while (getline(ss, aux, ','))
		{
			v.push_back(aux);
		}
		Programer p{ stoi(v[0]),v[1] };
		Pvec.push_back(p);
	}
	file.close();
}

void Repository::readTasksFromFile()
{
	ifstream file;
	file.open("Tasks.txt");

	string line, aux;
	while (getline(file, line))
	{
		vector<string> v;
		stringstream ss(line);
		while (getline(ss, aux, ','))
		{
			v.push_back(aux);
		}
		Task t{ stoi(v[0]),v[1],v[2] };
		Tvec.push_back(t);
	}
	file.close();
}

void Repository::writeTasksToFile()
{
	ofstream file;
	file.open("Tasks.txt");

	for (Task t : Tvec)
	{
		file << to_string(t.getId()) + "," + t.getDescription() + "," + t.getStatus() + "\n";
	}
	
	file.close();
}

void Repository::sortTaskByStatus()
{
	sort(Tvec.begin(), Tvec.end(), [](Task t1, Task t2) {return t1.getStatus() < t2.getStatus(); });
}

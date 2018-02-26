#include "Task.h"
#include<Windows.h>

using namespace std;


/*Task::Task(const string& description, int duration, int priority)
{
	this->description = description;
	this->duration = duration;
	this->priority = priority;
}*/

std::string Task::toString()
{
	string str = "Description: " + description + "     Duration: " + to_string(duration) + "    Priority: " + to_string(priority) + "\n";
	return str;
}

/*void main()
{
	Task a{ "Sarmale", 160, 1 };
	cout << a.toString();
	cout << a.getDescription();
	a.setDescription("Vava");
	cout << a.toString();
	system("pause");
}*/
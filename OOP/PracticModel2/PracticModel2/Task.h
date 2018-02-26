#pragma once
#include<string>


class Task
{
private:
	int id = 0;
	std::string description;
	std::string status = "open";
	std::string progName = "";
public:
	Task(){}
	Task(int d, std::string descr, std::string stat) : id{ d },description { descr }, status{ stat } {}
	~Task(){}

	int getId() { return id; }
	std::string getDescription() { return description; }
	std::string getStatus() { return status; }

	void setId(int value) { id = value; }
	void setStatus(std::string stat) { status = stat; }
	void setProgName(std::string name) { progName = name; }

	std::string toString() { return status + "  -  " + description + "   " + progName +"\n"; }

};


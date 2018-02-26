#pragma once
#include<string>



class Idea
{
private:
	std::string description;
	std::string status;
	std::string creator;
	std::string act;
public:
	Idea(){}
	Idea(std::string descr, std::string stat, std::string creat, std::string ac) : description{descr},status{stat},creator{creat},act{ac}{}
	~Idea(){}


	std::string getDescription() { return description; }
	std::string getStatus() { return status; }
	std::string getCreator() { return creator; }
	std::string getAct() { return act; }

	void setStatus(std::string stat) { status = stat; }

	std::string toStringPopulate() { return description + "   " + status + "   " + creator + "   " + act + "\n"; }

};


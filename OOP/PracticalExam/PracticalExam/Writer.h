#pragma once
#include<string>


class Writer
{
private:
	std::string name;
	std::string expertise;
public:
	Writer(){}
	Writer(std::string nam, std::string expert) : name{nam},expertise{expert}{}
	~Writer(){}

	std::string getName() { return name; }
	std::string getExpertise() { return expertise; }
};


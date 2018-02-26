#pragma once
#include<string>

class Programer
{
private:
	int id;
	std::string name;
public:
	Programer(){}
	Programer(int d,std::string nam) : id{d},name{nam}{}
	~Programer(){}

	int getId() { return id; }
	std::string getName() { return name; }
};


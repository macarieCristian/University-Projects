#pragma once
#include<string>


class Gene
{
private:
	std::string organism;
	std::string name;
	std::string seq;

public:
	Gene(std::string org,std::string nam,std::string seq1) : organism{org},name{nam},seq{seq1}{}
	Gene();
	~Gene();

	std::string getOrganism() { return organism; }
	std::string getName() { return name; }
	std::string getSeq() { return seq; }

	std::string toString() { return organism + " " + name + "\n"; }
};


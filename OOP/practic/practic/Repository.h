#pragma once
#include<vector>
#include<algorithm>
#include"Gene.h"


class Repository
{
private:
	std::vector<Gene> vec;

public:
	Repository();
	~Repository();

	std::vector<Gene>& getRepo() { return vec; }
	void deleteGene(Gene g);
	int nrGenes(std::string organism);
	/*
	The function nrGenes return the number of genes which have the given organism;
	input: a string, the organism;
	output: an integer, the number of genes for the given organism
	*/

	void readFromFile(std::string fileName);

	void sorted();
	/*
	The function sorted , sort the current repository by organism in an alfabetical order using an STL algorithm;
	input: -
	output: the repo is modifyed so that is sorted;
	*/

	void test();

};


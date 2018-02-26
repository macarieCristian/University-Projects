#include "Repository.h"
#include<fstream>
#include<sstream>
#include<assert.h>

using namespace std;

Repository::Repository()
{
}


Repository::~Repository()
{
}



void Repository::deleteGene(Gene ge)
{
	int poz = 0;
	for (Gene g : vec)
	{
		if (ge.getName() == g.getName())
			break;
		poz += 1;
	}

	if (poz >= vec.size())
		return;
	vec.erase(vec.begin() + poz);


}

int Repository::nrGenes(std::string organism)
{
	int nr = 0;
	nr = count_if(vec.begin(), vec.end(), [organism](Gene g) {return g.getOrganism() == organism; });
	return nr;
}

void Repository::readFromFile(std::string fileName)
{

	ifstream file;
	file.open(fileName);
	string line;
	while (getline(file, line))
	{
		string dada;
		stringstream ss(line);
		vector<string> res;
		while (getline(ss, dada, ','))
		{
			res.push_back(dada);
		}

		Gene g{ res[0],res[1],res[2] };
		vec.push_back(g);

	}




}

void Repository::sorted()
{
	sort(vec.begin(), vec.end(), [](Gene g1, Gene g2) {return g1.getOrganism() < g2.getOrganism(); });
}

void Repository::test()
{
	Repository r{};
	r.readFromFile("Genes.txt");
	assert(r.nrGenes("human") == 2);
	assert(r.nrGenes("ecoli") == 1);
	assert(r.nrGenes("blabla") == 0);


}

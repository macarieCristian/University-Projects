#include "Controller.h"
#include<fstream>
#include<sstream>
#include<assert.h>


using namespace std;


void Controller::readWriters()
{
	ifstream file;
	file.open("Writers.txt");

	string line, aux;
	while (getline(file, line))
	{
		stringstream ss{ line };
		vector<string> v;
		while (getline(ss, aux, ','))
		{
			v.push_back(aux);
		}
		Writer w{ v[0],v[1] };
		Wvec.push_back(w);
	}
	file.close();
}

void Controller::readIdeas()
{
	ifstream file;
	file.open("Ideas.txt");

	string line, aux;
	while (getline(file, line))
	{
		stringstream ss{ line };
		vector<string> v;
		while (getline(ss, aux, ','))
		{
			v.push_back(aux);
		}
		Idea i{ v[0],v[1],v[2],v[3] };
		Ivec.push_back(i);
	}
	file.close();
}

void Controller::sortByActAndCreator()
{
	sort(Ivec.begin(), Ivec.end(), [](Idea a, Idea b) {if (a.getAct() == b.getAct())return a.getCreator() < b.getCreator(); else return a.getAct() < b.getAct(); });
}

void Controller::addIdea(Writer w, std::string description, std::string act)
{
	if (description.size() == 0)
		throw exception("Empty description!");
	if (act != "1" && act != "2" && act != "3")
		throw exception("The act is wrong!");
	auto it = find_if(Ivec.begin(), Ivec.end(), [description, act](Idea i) {return description == i.getDescription() && act == i.getAct(); });
	if (it != Ivec.end())
		throw exception("Same description in tha same act!");
	Idea id{ description,"proposed",w.getName(),act };
	Ivec.push_back(id);
	notify();
}

bool Controller::acceptIdea(Writer w, Idea i)
{
	if (w.getExpertise() != "Senior")
		return false;
	
	for (Idea& i1 : Ivec)
	{
		if (i1.getDescription() == i.getDescription())
		{
			i1.setStatus("accepted");
			break;
		}
	}
	notify();
	return true;
}

void Controller::writePlot()
{
	ofstream file;
	file.open("Plot.txt");
	string act1, act2, act3;
	act1 = "Act1 - ";
	act2 = "Act2 - ";
	act3 = "Act3 - ";
	for (Idea i : Ivec)
	{
		if (i.getAct() == "1" && i.getStatus()=="accepted")
		{
			act1 += i.getDescription() + "  (" + i.getCreator() + ")  ";
		}
	}
	act1 += "\n\n";
	file << act1;

	for (Idea i : Ivec)
	{
		if (i.getAct() == "2" && i.getStatus() == "accepted")
		{
			act2 += i.getDescription() + "  (" + i.getCreator() + ")  ";
		}
	}
	act2 += "\n\n";
	file << act2;

	for (Idea i : Ivec)
	{
		if (i.getAct() == "3" && i.getStatus() == "accepted")
		{
			act3 += i.getDescription() + "  (" + i.getCreator() + ")  ";
		}
	}
	act3 += "\n\n";
	file << act3;

	file.close();
}

void Controller::testTwoFunctions()
{
	Controller cont{};
	int x = cont.getIvec().size();
	Writer w{ "Cristi","Senior" };
	cont.addIdea(w, "ceva", "1");
	assert(cont.getIvec().size() == x + 1);
	try
	{
		cont.addIdea(w, "Ideea1", "1");
	}
	catch (exception& e)
	{
		assert(e.what() == "Same description in tha same act!");
	}

	try
	{
		cont.addIdea(w, "", "1");
	}
	catch (exception& e)
	{
		assert(e.what() != "");
	}

	try
	{
		cont.addIdea(w, "dasd", "7");
	}
	catch (exception& e)
	{
		assert(e.what() != "The act is wrong!");
	}

	bool ok = cont.acceptIdea(w, cont.getIvec()[0]);
	assert(ok == true);
}


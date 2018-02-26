#pragma once
#include"Idea.h"
#include"Writer.h"
#include<vector>
#include<algorithm>
#include<exception>
#include"Observer.h"



class Controller : public Observable
{
private:
	std::vector<Writer> Wvec;
	std::vector<Idea> Ivec;
public:
	Controller()
	{
		readWriters();
		readIdeas();
	}
	~Controller(){}

	std::vector<Writer>& getWvec() { return Wvec; }
	std::vector<Idea>& getIvec() { return Ivec; }

	void readWriters();
	void readIdeas();

	void sortByActAndCreator();

	void addIdea(Writer w, std::string description, std::string act);
	/*
		descr: adds an idea to the list of ideas
		input: w the writer, description of idea, act the act of the idea
		throw exception if:
			-description is empty
			-if act!= 1,2,3
			-if there is another ideea with the same act
	*/
	bool acceptIdea(Writer w, Idea i);
	/*
		descr: accept an ideea meaning that its status is changed to accepted
		input: w the writer which accepts the ideea , and i the ideea
		return true if successful
	*/

	void writePlot();

	void testTwoFunctions();

};


#pragma once
#include<string>

class Participant
{
private:
	std::string name;
	int score = 0;
public:
	Participant(){}
	Participant(std::string nam): name{nam}{}
	~Participant(){}

	std::string getName() { return name; }
	int getScore() { return score; }
	void setScore(int value) { score = value; }
};


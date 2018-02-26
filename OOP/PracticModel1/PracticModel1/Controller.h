#pragma once
#include"Question.h"
#include"Participant.h"
#include<vector>
#include<algorithm>
#include"Observer.h"

class Controller : public Observable
{
private:
	std::vector<Question> Qvec;
	std::vector<Participant> Pvec;
public:
	Controller()
	{
		this->readQuestionsFromFile();
		this->readParticipantsFromFile();
	}
	~Controller()
	{
		writeQuestionsToFile();
	}

	int getParticipantsNum() { return Pvec.size(); }
	std::vector<Participant>& getPvec() { return Pvec; }
	std::vector<Question>& getQvec() { return Qvec; }

	void readQuestionsFromFile();
	void readParticipantsFromFile();
	void writeQuestionsToFile();

	void addQuestion(int id, std::string text, std::string answer, int score);

	void QuestionsSortedById();

	void QuestionsSortedDescendingByScore();

};


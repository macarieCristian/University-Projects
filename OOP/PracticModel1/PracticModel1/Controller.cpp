#include "Controller.h"
#include<fstream>
#include<sstream>

using namespace std;




void Controller::readQuestionsFromFile()
{
	ifstream file;
	file.open("Questions.txt");

	string line, aux;
	while (getline(file, line))
	{
		vector<string> v;
		stringstream ss(line);
		while (getline(ss, aux, ','))
		{
			v.push_back(aux);
		}
		Question q{ stoi(v[0]),v[1],v[2],stoi(v[3]) };
		Qvec.push_back(q);
	}

	file.close();
}

void Controller::readParticipantsFromFile()
{
	ifstream file;
	file.open("Participants.txt");

	string line;
	while (getline(file, line))
	{
		Participant p{ line };
		Pvec.push_back(p);
	}

	file.close();
}

void Controller::writeQuestionsToFile()
{
	ofstream file;
	file.open("Questions.txt");
	for (Question q : Qvec)
	{
		file << to_string(q.getId()) + "," + q.getText() + "," + q.getRightAnswer() + "," + to_string(q.getScore()) + "\n";
	}
	file.close();
}

void Controller::addQuestion(int id, std::string text, std::string answer, int score)
{
	auto it = find_if(Qvec.begin(), Qvec.end(), [id](Question q) {return q.getId() == id; });
	if (it != Qvec.end())
		throw exception("There is already a question with this id.");
	Question q{ id,text,answer,score };
	Qvec.push_back(q);
	notify();
}

void Controller::QuestionsSortedById()
{
	sort(Qvec.begin(), Qvec.end(), [](Question q1, Question q2) {return q1.getId() < q2.getId(); });
}

void Controller::QuestionsSortedDescendingByScore()
{
	sort(Qvec.begin(), Qvec.end(), [](Question q1, Question q2) {return q1.getScore() > q2.getScore(); });
}

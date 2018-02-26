#pragma once
#include<string>
class Question
{
private:
	int id;
	std::string text;
	std::string rightAnsw;
	int score;
public:
	Question(){}
	Question(int Id, std::string txt, std::string rightAsw,int core): id{Id},text{txt},rightAnsw{rightAsw},score{core}{}
	~Question(){}

	int getId() { return id; }
	std::string getText() { return text; }
	std::string getRightAnswer() { return rightAnsw; }
	int getScore() { return score;}

	std::string toStringPresenter()
	{
		return std::to_string(id) + ". " + text + "  " + rightAnsw + "  " + std::to_string(score) + "\n";
	}

	std::string toStringUser()
	{
		return std::to_string(id) + ". " + text + "    Score: " + std::to_string(score) + "\n";
	}
};


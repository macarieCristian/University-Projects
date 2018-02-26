#ifndef PRACTICMODEL1_H
#define PRACTICMODEL1_H

#include <QtWidgets/QMainWindow>
#include "ui_practicmodel1.h"
#include"Controller.h"
#include"Observer.h"


class PracticModel1 : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	PracticModel1(Participant p, Controller& c, QWidget *parent = 0);
	~PracticModel1();

private:
	Controller &ctrl;
	Ui::PracticModel1Class ui;
	std::vector<Question> answered;
	Participant pp;

	int getCurrentIndex();

	void answerQuestion();
	void populate();
	void update();

	void currentIndexChangedHandler();

	void connect();
};

#endif // PRACTICMODEL1_H

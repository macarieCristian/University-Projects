#ifndef PRACTICALEXAM_H
#define PRACTICALEXAM_H

#include <QtWidgets/QMainWindow>
#include "ui_practicalexam.h"
#include"Controller.h"
#include"Observer.h"

class PracticalExam : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	PracticalExam(Writer w, Controller& c, QWidget *parent = 0);
	~PracticalExam();

private:
	Ui::PracticalExamClass ui;
	Controller& ctrl;
	Writer ww;
	bool hasAcceptedIdea = false;

	void populate();
	void update() override;

	int getCurrentIndex();

	void addButton();
	void acceptHandler();
	void indexChangedHandler();
	void connect();

	void savePlotHandler();

	void developHandler();

};

#endif // PRACTICALEXAM_H

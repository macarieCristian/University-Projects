#ifndef PRESENTERWINDOW_H
#define PRESENTERWINDOW_H

#include <QtWidgets/QMainWindow>
#include "ui_presenterwindow.h"
#include"Controller.h"

class PresenterWindow : public QWidget, public Observer
{
	Q_OBJECT

public:
	PresenterWindow(Controller& c,QWidget *parent = 0);
	~PresenterWindow();

private:
	Controller &ctrl;
	Ui::PresenterWindow ui;

	void addQuestion();
	void populate();
	void update();
	void connect();
};

#endif // PRESENTERWINDOW_H

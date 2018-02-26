#ifndef GUI2_H
#define GUI2_H

#include <QtWidgets/QMainWindow>
#include "ui_gui2.h"
#include"Repository.h"

class gui2 : public QMainWindow, public Observer
{
	Q_OBJECT

public:
	gui2(Programer p, Repository& r, QWidget *parent = 0);
	~gui2();

private:
	Ui::gui2 ui;
	Repository& repo;
	Programer pp;

	int getSelectedIndex();

	void update();
	void populate();

	void addButtonHandler();
	void deleteButonHandler();
	void startButtonHandler();
	void doneButtonHandler();

	void connect();
};

#endif // GUI2_H

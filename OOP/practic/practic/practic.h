#ifndef PRACTIC_H
#define PRACTIC_H

#include <QtWidgets/QMainWindow>
#include "ui_practic.h"
#include"Repository.h"

class practic : public QMainWindow
{
	Q_OBJECT

public:
	practic(Repository& rep, QWidget *parent = 0);
	~practic();

private:
	Ui::practicClass ui;
	std::vector<Gene> repo;
	Repository rr;

	void populate();

	int getSelectedIndex();
	void deleteHandler();

	void sortHandler();

	void numberOfGenesHandler();

	void selectionChangedHandler();


	void conect();

};

#endif // PRACTIC_H

#ifndef PROJECTDOGS_H
#define PROJECTDOGS_H

#include <QtWidgets/QMainWindow>
#include "ui_projectdogs.h"

class ProjectDogs : public QMainWindow
{
	Q_OBJECT

public:
	ProjectDogs(QWidget *parent = 0);
	~ProjectDogs();

private:
	Ui::ProjectDogsClass ui;
};

#endif // PROJECTDOGS_H

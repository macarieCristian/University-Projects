#ifndef PRACTICMODEL2_H
#define PRACTICMODEL2_H

#include <QtWidgets/QMainWindow>
#include "ui_practicmodel2.h"

class PracticModel2 : public QMainWindow
{
	Q_OBJECT

public:
	PracticModel2(QWidget *parent = 0);
	~PracticModel2();

private:
	Ui::PracticModel2Class ui;
};

#endif // PRACTICMODEL2_H

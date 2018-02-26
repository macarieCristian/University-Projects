#ifndef SECOUNDWINDOW_H
#define SECOUNDWINDOW_H

#include <QMainWindow>
#include "ui_secoundwindow.h"

class SecoundWindow : public QMainWindow
{
	Q_OBJECT

public:
	SecoundWindow(QWidget *parent = 0);
	~SecoundWindow();

private:
	Ui::SecoundWindow ui;
};

#endif // SECOUNDWINDOW_H

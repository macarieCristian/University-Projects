#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qwidget.h>
#include <qcombobox.h>
#include "ControllerAdmin.h"
#include<qmessagebox.h>
#include"gui.h"
#include"CSVUserList.h"
#include"HTMLUserList.h"
#include"guieditor.h"
#include"firstwindow.h"

#include <QObject>


class FirstWindow : public QWidget
{
	Q_OBJECT

public:
	FirstWindow(GUI* csv, GUI* html, QWidget *parent = 0);
	~FirstWindow();

	int getRes() { return res; }
private:
	GUI* CSV;
	GUI* HTML;


	QPushButton* CSVButton;
	QPushButton* HTMLButton;
	int res;

	


	void windowShow();
	void connectButtons();
private slots:
	void setResponseCSV();
	void setResponseHTML();


};

#endif // FIRSTWINDOW_H

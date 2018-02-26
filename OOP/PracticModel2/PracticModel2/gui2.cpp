#include "gui2.h"
#include<qmessagebox.h>

gui2::gui2(Programer p, Repository& r, QWidget *parent)
	: QMainWindow(parent),repo{r},pp{p}
{
	ui.setupUi(this);
	repo.addObserver(this);
	connect();
	populate();

}

gui2::~gui2()
{

}

int gui2::getSelectedIndex()
{
	if (ui.listWidget->count() == 0)
		return -1;
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		return -1;
	}
	int idx = index.at(0).row();
	return idx;
}

void gui2::update()
{
	populate();
}

void gui2::populate()
{
	if (repo.getTvec().size() == 0)
		return;
	
	ui.listWidget->clear();
	repo.sortTaskByStatus();

	for (Task t : repo.getTvec())
	{
		QString str = QString::fromStdString(t.toString());

		ui.listWidget->addItem(str);
	}
}

void gui2::addButtonHandler()
{
	QString desc = ui.lineEdit->text();
	if (desc.size() == 0)
		return;

	repo.addTask(desc.toStdString());

}

void gui2::deleteButonHandler()
{
	int x = getSelectedIndex();
	if (x == -1)
		return;
	Task t = repo.getTvec()[x];
	repo.removeTask(t.getDescription());
}

void gui2::startButtonHandler()
{
	try
	{
		int x = getSelectedIndex();
		if (x == -1)
			return;
		Task t = repo.getTvec()[x];
		repo.startTask(pp, t.getDescription());
	}
	catch (std::exception& e)
	{
		QMessageBox mb;
		mb.critical(0, "Error", e.what());
	}

}

void gui2::doneButtonHandler()
{
	try
	{
		int x = getSelectedIndex();
		if (x == -1)
			return;
		Task t = repo.getTvec()[x];
		repo.closeTask(pp, t);
	}
	catch (std::exception& e)
	{
		QMessageBox mb;
		mb.critical(0, "Error", e.what());
	}
}

void gui2::connect()
{
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &gui2::addButtonHandler);
	QObject::connect(ui.pushButtonRemove, &QPushButton::clicked, this, &gui2::deleteButonHandler);
	QObject::connect(ui.pushButtonStart, &QPushButton::clicked, this, &gui2::startButtonHandler);
	QObject::connect(ui.pushButtonDone, &QPushButton::clicked, this, &gui2::doneButtonHandler);
}

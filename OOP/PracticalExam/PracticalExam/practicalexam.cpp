#include "practicalexam.h"
#include<qmessagebox.h>
#include<fstream>

PracticalExam::PracticalExam(Writer w, Controller& c, QWidget *parent)
	: QMainWindow(parent),ctrl{c},ww{w}
{
	ui.setupUi(this);
	ctrl.addObserver(this);
	populate();
	ui.pushButtonDevelop->setDisabled(true);
	connect();
	ui.lineEdit1->hide();
	ui.lineEdit2->hide();
	//ui.pushButtonSave->hide();
}

PracticalExam::~PracticalExam()
{

}

void PracticalExam::populate()
{
	if (ctrl.getIvec().size() == 0)
		return;
	ui.listWidget->clear();

	ctrl.sortByActAndCreator();


	for (Idea i : ctrl.getIvec())
	{
		QString dd{ QString::fromStdString(i.toStringPopulate()) };
		QListWidgetItem *it = new QListWidgetItem{dd};
		this->setWindowTitle(QString::fromStdString(ww.getName()));
		QString nam = this->windowTitle();
		//ui.lineEditAct->setText(nam);
		if (i.getCreator() == nam.toStdString() && i.getStatus() == "accepted")
		{
			it->setBackgroundColor(Qt::green);
		}

		ui.listWidget->addItem(it);
	}
}

void PracticalExam::update()
{
	populate();
	for(Idea i: ctrl.getIvec())
		if(i.getCreator()==ww.getName() && i.getStatus() == "accepted")
			ui.pushButtonDevelop->setDisabled(false);


	QString nam = this->windowTitle();
	ui.lineEditAct->setText(nam);
	int nr = 0;
	for (Idea i : ctrl.getIvec())
		if (i.getCreator() == nam.toStdString() && i.getStatus() == "accepted")
			nr += 1;
	if (nr == 1)
	{
		ui.lineEdit1->show();
	}
	if (nr == 2)
	{
		ui.lineEdit1->show();
		ui.lineEdit2->show();
	}
	ui.pushButtonDevelop->show();
}

int PracticalExam::getCurrentIndex()
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

void PracticalExam::addButton()
{
	try
	{
		QString desc = ui.lineEditDesc->text();
		QString act = ui.lineEditAct->text();
		ctrl.addIdea(ww, desc.toStdString(), act.toStdString());
	}
	catch(std::exception& e)
	{
		QMessageBox mb;
		mb.critical(0, "Error", e.what());
	}
}

void PracticalExam::acceptHandler()
{
	int idx = getCurrentIndex();
	if (idx == -1)
		return;

	ctrl.acceptIdea(ww, ctrl.getIvec()[idx]);
	

}

void PracticalExam::indexChangedHandler()
{
	int idx = getCurrentIndex();
	if (idx == -1)
		return;

	Idea i = ctrl.getIvec()[idx];
	if (i.getStatus() == "proposed" && ww.getExpertise()=="Senior")
	{
		ui.pushButtonAccept->setDisabled(false);
	}
	else
	{
		ui.pushButtonAccept->setDisabled(true);
	}

}

void PracticalExam::connect()
{
	QObject::connect(ui.pushButtonAdd, &QPushButton::clicked, this, &PracticalExam::addButton);
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, &PracticalExam::indexChangedHandler);
	QObject::connect(ui.pushButtonAccept, &QPushButton::clicked, this, &PracticalExam::acceptHandler);
	QObject::connect(ui.pushButtonSavePlot, &QPushButton::clicked, this, &PracticalExam::savePlotHandler);
	QObject::connect(ui.pushButtonSave, &QPushButton::clicked, this, &PracticalExam::savePlotHandler);
	QObject::connect(ui.pushButtonDevelop, &QPushButton::clicked, this, &PracticalExam::developHandler);
}

void PracticalExam::savePlotHandler()
{
	ctrl.writePlot();
}

void PracticalExam::developHandler()
{
	int idx = getCurrentIndex();
	if (idx == -1)
		return;

	QString qq = ui.lineEdit1->text();
	QString qq2 = ui.lineEdit2->text();

	std::ofstream f;
	f.open("da.txt");

	std::string str;

	str = "";
	str += ctrl.getIvec()[idx].getCreator() + "   " + ctrl.getIvec()[idx].getAct() + "   " + qq.toStdString();
	f << str;
	f.close();

}

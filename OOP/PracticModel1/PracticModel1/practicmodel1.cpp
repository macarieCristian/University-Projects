#include "practicmodel1.h"
#include<iostream>

PracticModel1::PracticModel1(Participant p, Controller& c, QWidget *parent)
	: QMainWindow(parent), ctrl{c}, pp{p}
{
	ui.setupUi(this);
	ctrl.addObserver(this);
	connect();
	populate();
}

PracticModel1::~PracticModel1()
{

}

int PracticModel1::getCurrentIndex()
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

void PracticModel1::answerQuestion()
{
	int idx = getCurrentIndex();
	if (idx == -1)
		return;
	Question q = ctrl.getQvec()[idx];
	QString as = ui.lineEdit->text();
	if (q.getRightAnswer() == as.toStdString())
	{
		pp.setScore(pp.getScore() + q.getScore());
	}
	answered.push_back(q);
	populate();
	currentIndexChangedHandler();
}


void PracticModel1::populate()
{
	ui.labelScore->setText(QString::number(pp.getScore()));

	if (ctrl.getQvec().size() == 0)
		return;
	ctrl.QuestionsSortedDescendingByScore();

	ui.listWidget->clear();

	for (Question q : ctrl.getQvec())
	{
		QString dd = QString::fromStdString(q.toStringUser());
		QListWidgetItem* it = new QListWidgetItem{ dd };
		int id = q.getId();
		auto ite = find_if(answered.begin(), answered.end(), [id](Question qq) {return id == qq.getId(); });
		if (ite != answered.end())
		{
			it->setBackgroundColor(Qt::green);
		}
		ui.listWidget->addItem(it);
	}
}

void PracticModel1::update()
{
	populate();
}

void PracticModel1::currentIndexChangedHandler()
{
	int idx = getCurrentIndex();
	if (idx == -1)
		return;
	Question q = ctrl.getQvec()[idx];
	int id = q.getId();
	auto ite = find_if(answered.begin(), answered.end(), [id](Question qq) {return id == qq.getId(); });
	if (ite != answered.end())
	{
		ui.pushButton->setDisabled(true);
	}
	else
	{
		ui.pushButton->setDisabled(false);
	}
}

void PracticModel1::connect()
{
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &PracticModel1::answerQuestion);
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, &PracticModel1::currentIndexChangedHandler);
}

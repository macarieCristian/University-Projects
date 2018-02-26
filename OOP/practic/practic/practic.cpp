#include "practic.h"

practic::practic(Repository& rep, QWidget *parent)
	: QMainWindow(parent),rr{rep}
{
	ui.setupUi(this);
	populate();
	conect();
	

}

practic::~practic()
{

}

void practic::populate()
{
	ui.listWidget->clear();
	std::vector<Gene> repo = rr.getRepo();
	for (Gene g : repo)
	{
		QString it = QString::fromStdString(g.toString());
		ui.listWidget->addItem(it);
	}



}

int practic::getSelectedIndex()
{
	QModelIndexList index = ui.listWidget->selectionModel()->selectedIndexes();
	
		if (index.size() == 0)
		{
			return -1;
		}

		int idx = index.at(0).row();
		return idx;
}

void practic::deleteHandler()
{
	int index = getSelectedIndex();
		if (index == -1)
			return;
	
		if (index >= rr.getRepo().size())
			return;

		Gene g = rr.getRepo()[index];
		rr.deleteGene(g);
		populate();


}

void practic::sortHandler()
{
	rr.sorted();
	populate();


}

void practic::numberOfGenesHandler()
{
	QString org = ui.lineEdit->text();
	if (org.size() == 0)
	{
		ui.lineEdit_2->clear();
		return;
	}

	int res = rr.nrGenes(org.toStdString());
	QString nr = QString::number(res);
	ui.lineEdit_2->setText(nr);
	ui.lineEdit->clear();


}

void practic::selectionChangedHandler()
{
	int inx = getSelectedIndex();

	if (inx >= rr.getRepo().size())
		return;

	QString org = QString::fromStdString(rr.getRepo()[inx].getOrganism());
	ui.lineEdit->setText(org);


}

void practic::conect()
{
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, &practic::selectionChangedHandler);
	QObject::connect(ui.pushButtonShow, &QPushButton::clicked, this, &practic::numberOfGenesHandler);
	QObject::connect(ui.pushButtonRemove, &QPushButton::clicked, this, &practic::deleteHandler);
	QObject::connect(ui.pushButtonSort, &QPushButton::clicked, this, &practic::sortHandler);
}



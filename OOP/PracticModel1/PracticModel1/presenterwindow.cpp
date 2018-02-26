#include "presenterwindow.h"
#include<qmessagebox.h>

PresenterWindow::PresenterWindow(Controller& c, QWidget *parent)
	: QWidget(parent),ctrl{c}
{
	ui.setupUi(this);
	ctrl.addObserver(this);
	populate();
	connect();
}

PresenterWindow::~PresenterWindow()
{

}

void PresenterWindow::addQuestion()
{
	QString id = ui.lineEditId->text();
	QString text = ui.lineEditText->text();
	QString answ = ui.lineEditAsw->text();
	QString score = ui.lineEditScore->text();
	if (id.size() == 0 || text.size() == 0 || answ.size() == 0 || score.size() == 0)
	{
		QMessageBox mb;
		mb.critical(0, "Error", "There are empty fields!");
		return;
	}
	try
	{
		ctrl.addQuestion(id.toInt(), text.toStdString(), answ.toStdString(), score.toInt());
	}
	catch (std::exception& e)
	{
		QMessageBox mb1;
		mb1.critical(0, "Error", e.what());
	}
}

void PresenterWindow::populate()
{
	if (ctrl.getQvec().size() == 0)
		return;
	ui.listWidget->clear();
	ctrl.QuestionsSortedById();

	for (Question q : ctrl.getQvec())
	{
		QString dd = QString::fromStdString(q.toStringPresenter());
		ui.listWidget->addItem(dd);
	}
}

void PresenterWindow::update()
{
	populate();
}

void PresenterWindow::connect()
{
	QObject::connect(ui.pushButton, &QPushButton::clicked, this, &PresenterWindow::addQuestion);
}

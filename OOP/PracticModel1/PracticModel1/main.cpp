#include "practicmodel1.h"
#include"presenterwindow.h"
#include <QtWidgets/QApplication>
#include"Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);


	Controller c{};
	PresenterWindow w{ c };
	w.setWindowTitle(" Presenter ");
	w.show();
	

	for (int i = 0; i < c.getParticipantsNum(); i++)
	{
		Participant p{ c.getPvec()[i].getName() };
		PracticModel1* x = new PracticModel1{p,c};
		x->setWindowTitle(QString::fromStdString(c.getPvec()[i].getName()));
		x->show();
	}

	return a.exec();
}

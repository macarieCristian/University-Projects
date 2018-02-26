#include "practicalexam.h"
#include "secoundwindow.h"
#include <QtWidgets/QApplication>
#include"Controller.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Controller c{};

	for (Writer w : c.getWvec())
	{
		PracticalExam *x = new PracticalExam{ w,c };
		x->setWindowTitle(QString::fromStdString(w.getName()));
		x->show();
	}

	c.testTwoFunctions();

	


	return a.exec();
}

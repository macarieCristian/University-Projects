#include "practicmodel2.h"
#include"gui2.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository r{};

	for (Programer p : r.getPvec())
	{

		gui2* x = new gui2{ p,r };
		x->setWindowTitle(QString::fromStdString(p.getName()));
		x->show();
	}


	return a.exec();
}

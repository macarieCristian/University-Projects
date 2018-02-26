#include "practic.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r{};
	r.readFromFile("Genes.txt");
	r.test();
	practic w{ r };
	w.show();
	return a.exec();
}

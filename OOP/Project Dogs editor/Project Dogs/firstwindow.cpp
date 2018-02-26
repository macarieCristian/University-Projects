#include "firstwindow.h"

FirstWindow::FirstWindow(GUI* csv, GUI* html, QWidget *parent) : QWidget(parent)
{
	res = 0;
	windowShow();
	connectButtons();
	CSV = csv;
	HTML = html;
}

FirstWindow::~FirstWindow()
{

}

void FirstWindow::setResponseCSV()
{
	
	this->close();
	CSV->show();
	
}

void FirstWindow::setResponseHTML()
{
	
	this->close();
	HTML->show();
}

void FirstWindow::windowShow()
{
	QHBoxLayout* layout = new QHBoxLayout{this};

	QWidget *menu = new QWidget{};
	QVBoxLayout *lay = new QVBoxLayout{ menu };
	QLabel* label = new QLabel{};
	QFont f("Arial", 15);
	label->setText("In which type of file do you want your adoption list to be saved in?");
	label->setFont(f);
	lay->addWidget(label);

	CSVButton = new QPushButton{ "Save in CSV format." };
	CSVButton->setFont(f);

	HTMLButton = new QPushButton{ "Save in HTML format." };
	HTMLButton->setFont(f);

	lay->addWidget(CSVButton);
	lay->addWidget(HTMLButton);



	layout->addWidget(menu);

}

void FirstWindow::connectButtons()
{
	QObject::connect(this->CSVButton, &QPushButton::clicked, this, &FirstWindow::setResponseCSV);
	QObject::connect(this->HTMLButton, &QPushButton::clicked, this, &FirstWindow::setResponseHTML);



}







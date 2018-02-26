#include "gui.h"
#include"RepoExceptions.h"

GUI::GUI(ControllerAdmin& c, QWidget *parent) : QWidget{parent}, control{c}
{
	this->initGUI();
	this->conectComponents();
	this->comboBoxHandler();
}

GUI::~GUI()
{

}

void GUI::initGUI()
{
	QHBoxLayout* layout = new QHBoxLayout{ this };
	
	this->dogList = new QListWidget{};
	//this->addDogButton = new QPushButton{"Press"};
	this->dogList->setSelectionMode(QAbstractItemView::SingleSelection);
	//layout->addWidget(this->dogList);
	
	QWidget* leftSide = new QWidget{};
	QVBoxLayout* layoutLeft = new QVBoxLayout{ leftSide };
	QWidget* rightSide = new QWidget{};
	QVBoxLayout* layoutRight = new QVBoxLayout{ rightSide };

	QFont f{ "Verdana",15 };
	QFont f1{ "Verdana",10 };

	this->comboBox = new QComboBox{};
	comboBox->setFont(f1);
	comboBox->addItem(" Detailed ");
	comboBox->addItem(" Simple ");
	layoutLeft->addWidget(comboBox);

	QLabel* l5 = new QLabel{ "List of dogs:" };
	l5->setFont(f);
	layoutLeft->addWidget(l5);

	layoutLeft->addWidget(dogList);


	//dog info
	QWidget* dogData = new QWidget{};
	QFormLayout* formLayout = new QFormLayout{ dogData };
	QLabel* l1 = new QLabel{ "Breed:" };
	QLabel* l2 = new QLabel{ "Name:" };
	QLabel* l3 = new QLabel{ "Age:" };
	QLabel* l4 = new QLabel{ "Link:" };
	this->breedEdit = new QLineEdit{};
	this->nameEdit = new QLineEdit{};
	this->ageEdit = new QLineEdit{};
	this->photoLinkEdit = new QLineEdit{};
	
	breedEdit->setFont(f);
	nameEdit->setFont(f);
	ageEdit->setFont(f);
	photoLinkEdit->setFont(f);
	l1->setFont(f);
	l2->setFont(f);
	l3->setFont(f);
	l4->setFont(f);
	formLayout->addRow(l1, breedEdit);
	formLayout->addRow(l2,nameEdit);
	formLayout->addRow(l3,ageEdit);
	formLayout->addRow(l4,photoLinkEdit);

	layoutLeft->addWidget(dogData);

	QWidget* buttonsAdmin = new QWidget{};
	QHBoxLayout* buttonsAdminLayout = new QHBoxLayout{ buttonsAdmin };

	addDogButton = new QPushButton{ " Add " };
	removeDogButton = new QPushButton{ " Remove " };
	updateDogButton = new QPushButton{ " Update " };
	addDogButton->setFont(f);
	removeDogButton->setFont(f);
	updateDogButton->setFont(f);
	buttonsAdminLayout->addWidget(addDogButton);
	buttonsAdminLayout->addWidget(removeDogButton);
	buttonsAdminLayout->addWidget(updateDogButton);
	layoutLeft->addWidget(buttonsAdmin);

	/*QWidget* filterButtonw = new QWidget{};
	QVBoxLayout* FBLW = new QVBoxLayout{ filterButtonw };
	QPushButton* filterButton = new QPushButton{ " Filter " };
	filterButton->setFont(f);
	FBLW->addWidget(filterButton);
	layoutLeft->addWidget(filterButtonw);*/

	QWidget* filter = new QWidget{};
	QLabel* l0 = new QLabel{ "Filter by:" };
	l0->setFont(f);
	QFormLayout* fl = new QFormLayout{ filter };
	this->filterEdit = new QLineEdit{};
	filterEdit->setFont(f);
	fl->addRow(l0, filterEdit);
	layoutLeft->addWidget(filter);



	QLabel* l6 = new QLabel{ "List of adoptions:" };
	l6->setFont(f);
	layoutRight->addWidget(l6);

	this->adoptionList = new QListWidget{};
	layoutRight->addWidget(adoptionList);

	QWidget* startStop = new QWidget{};
	QHBoxLayout* startStopL = new QHBoxLayout{ startStop };

	

	QLabel* l02 = new QLabel{ "Filter by:" };
	l02->setFont(f);
	layoutRight->addWidget(l02);

	QLabel* n1 = new QLabel{ "Breed:" };
	n1->setFont(f);
	QLabel* n2 = new QLabel{ "Age less than:" };
	n2->setFont(f);

	QWidget* filter2 = new QWidget{};
	QFormLayout* fl2 = new QFormLayout{ filter2 };
	this->filterEditAdoptionName = new QLineEdit{};
	filterEditAdoptionName->setFont(f);
	fl2->addRow(n1, filterEditAdoptionName);

	this->filterEditAdoptionAge = new QLineEdit{};
	filterEditAdoptionAge->setFont(f);
	fl2->addRow(n2, filterEditAdoptionAge);

	startStopL->addWidget(filter2);
	layoutRight->addWidget(startStop);


	QWidget* adopt = new QWidget{};
	QHBoxLayout* adoptL = new QHBoxLayout{ adopt };

	adoptDogButton = new QPushButton{ " Adopt " };
	nextDogButton = new QPushButton{ " Next " };
	photoDogButton = new QPushButton{ " Photo " };
	adoptDogButton->setFont(f);
	nextDogButton->setFont(f);
	photoDogButton->setFont(f);
	adoptL->addWidget(adoptDogButton);
	adoptL->addWidget(nextDogButton);
	adoptL->addWidget(photoDogButton);
	layoutRight->addWidget(adopt);

	openButton = new QPushButton{ " Save and open file. " };
	openButton->setFont(f);
	layoutRight->addWidget(openButton);

	layout->addWidget(leftSide);
	layout->addWidget(rightSide);
	
}

void GUI::populateDogListDetalied()
{
	if (this->dogList->count() > 0)
		this->dogList->clear();

	for (Animal a : control.getRepo().getElem())
	{
		QString itemAnimal = QString::fromStdString(a.toString());
		QFont f("Verdana", 10);
		QListWidgetItem* item = new QListWidgetItem{ itemAnimal };
		item->setFont(f);
		this->dogList->addItem(item);
	}

	if (control.getRepo().getElem().size() > 0)
		this->dogList->setCurrentRow(0);


}

void GUI::populateDogListSimple()
{
	if (this->dogList->count() > 0)
		this->dogList->clear();

	for (Animal a : control.getRepo().getElem())
	{
		QString itemAnimal = QString::fromStdString(a.toStringSimple());
		QFont f("Verdana", 10);
		QListWidgetItem* item = new QListWidgetItem{ itemAnimal };
		item->setFont(f);
		this->dogList->addItem(item);
	}

	if (control.getRepo().getElem().size() > 0)
		this->dogList->setCurrentRow(0);

}

void GUI::populateDetalied(std::vector<Animal> vec)
{
	if (this->dogList->count() > 0)
		this->dogList->clear();

	for (Animal a : vec)
	{
		QString itemAnimal = QString::fromStdString(a.toString());
		QFont f("Verdana", 10);
		QListWidgetItem* item = new QListWidgetItem{ itemAnimal };
		item->setFont(f);
		this->dogList->addItem(item);
	}

	if (vec.size() > 0)
		this->dogList->setCurrentRow(0);

}

void GUI::populateSimple(std::vector<Animal> vec)
{
	if (this->dogList->count() > 0)
		this->dogList->clear();

	for (Animal a : vec)
	{
		QString itemAnimal = QString::fromStdString(a.toStringSimple());
		QFont f("Verdana", 10);
		QListWidgetItem* item = new QListWidgetItem{ itemAnimal };
		item->setFont(f);
		this->dogList->addItem(item);
	}

	if (vec.size() > 0)
		this->dogList->setCurrentRow(0);
}

void GUI::populate()
{
	if (this->comboBox->currentText() == " Simple ")
		this->populateDogListSimple();
	else if (this->comboBox->currentText() == " Detailed ")
		this->populateDogListDetalied();
}

void GUI::populateUList()
{
	if (this->adoptionList->count() > 0)
		this->adoptionList->clear();

	for (Animal a : control.getUList()->getUList())
	{
		QString itemAnimal = QString::fromStdString(a.toStringSimple());
		QFont f("Verdana", 10);
		QListWidgetItem* item = new QListWidgetItem{ itemAnimal };
		item->setFont(f);
		this->adoptionList->addItem(item);
	}

	if (control.getUList()->getUList().size() > 0)
		this->adoptionList->setCurrentRow(0);
}

void GUI::populateUListSimple(std::vector<Animal> vec)
{
	if (this->adoptionList->count() > 0)
		this->adoptionList->clear();

	for (Animal a : vec)
	{
		QString itemAnimal = QString::fromStdString(a.toStringSimple());
		QFont f("Verdana", 10);
		QListWidgetItem* item = new QListWidgetItem{ itemAnimal };
		item->setFont(f);
		this->adoptionList->addItem(item);
	}

	if (vec.size() > 0)
		this->adoptionList->setCurrentRow(0);

}

int GUI::getSelectedIndex()
{
	if (dogList->count() == 0)
		return -1;

	QModelIndexList index = dogList->selectionModel()->selectedIndexes();
	if (index.size() == 0)
	{
		breedEdit->clear();
		nameEdit->clear();
		ageEdit->clear();
		photoLinkEdit->clear();
		return -1;
	}

	int idx = index.at(0).row();
	return idx;
}

void GUI::listItemChangedHandler()
{
	int index = this->getSelectedIndex();
	if (index == -1)
		return;

	std::vector<Animal> vec = control.getRepo().getElem();

	if (index >= vec.size())
		return;

	Animal a = vec[index];

	breedEdit->setText(QString::fromStdString(a.getBreed()));
	nameEdit->setText(QString::fromStdString(a.getName()));
	ageEdit->setText(QString::number(a.getAge()));
	photoLinkEdit->setText(QString::fromStdString(a.getPhoto()));



}

void GUI::removeDogButtonHandler()
{
	try
	{
		QString breed = breedEdit->text();
		QString name = nameEdit->text();
		int age = ageEdit->text().toInt();
		QString link = photoLinkEdit->text();

		control.delAnimal(breed.toStdString(), name.toStdString());
		this->populate();
	}
	catch (RepoExceptions& e)
	{

		QMessageBox message;
		message.critical(0, "Error", e.what());

	}
}

void GUI::updateDogButtonHandler()
{
	try
	{
		int idx = this->getSelectedIndex();
		Animal to_up = control.getRepo().getElem()[idx];

		QString breed = breedEdit->text();
		QString name = nameEdit->text();
		int age = ageEdit->text().toInt();
		QString link = photoLinkEdit->text();

		control.updateAnimal(to_up.getBreed(), to_up.getName(), breed.toStdString(), name.toStdString(), age, link.toStdString());
		this->populate();
	}
	catch (RepoExceptions& e)
	{

		QMessageBox message;
		message.critical(0, "Error", e.what());

	}



}

void GUI::adoptDogButtonHandler()
{
	try
	{
		QString breed = breedEdit->text();
		QString name = nameEdit->text();
		int age = ageEdit->text().toInt();
		QString link = photoLinkEdit->text();
		Animal a{ breed.toStdString(), name.toStdString(), age, link.toStdString() };
		control.addUList(a);
		populateUList();
	}
	catch (RepoExceptions& e)
	{

		QMessageBox message;
		message.critical(0, "Error", e.what());

	}
}

void GUI::nextDogButtonHandler()
{

	int x = dogList->currentRow();
	x += 1;
	if (x == control.getRepo().getElem().size())
		x = 0;
	dogList->setCurrentRow(x);

}

void GUI::photoDogButtonHandler()
{
	int x = dogList->currentRow();
	Animal a = control.getRepo().getElem()[x];
	a.openLink();
}

void GUI::openFileButtonHandler()
{
	try
	{
		control.saveUserList(";)");
		control.openUserFile();
	}
	catch (RepoExceptions& e)
	{

		QMessageBox message;
		message.critical(0, "Error", e.what());

	}




}

void GUI::addDogButtonHandler()
{
	
		
		try
		{
			QString breed = breedEdit->text();
			QString name = nameEdit->text();
			int age = ageEdit->text().toInt();
			QString link = photoLinkEdit->text();

			control.addAnimal(breed.toStdString(), name.toStdString(), age, link.toStdString());
			this->populate();
		}
		catch (RepoExceptions& e)
		{

			QMessageBox message;
			message.critical(0, "Error", e.what());

		}


}

//void GUI::addDog(std::string breed, std::string name, int age, std::string link)
//{
//	
//	try
//	{
//		control.addAnimal(breed, name, age, link);
//
//		emit repoUpdatedSignal();
//	}
//	catch (RepoExceptions& e)
//	{
//
//		QMessageBox::information(this, tr("Error"), tr(e.what()));
//
//	}
//	
//}

void GUI::conectComponents()
{
	QObject::connect(this->filterEdit, &QLineEdit::textChanged, this, &GUI::filterHandler);
	QObject::connect(this->filterEditAdoptionName, &QLineEdit::textChanged, this, &GUI::filterHandler2);
	QObject::connect(this->filterEditAdoptionAge, &QLineEdit::textChanged, this, &GUI::filterHandler2);

	QObject::connect(this->comboBox, &QComboBox::currentTextChanged, this, &GUI::comboBoxHandler);

	QObject::connect(this->dogList, &QListWidget::itemSelectionChanged, this, &GUI::listItemChangedHandler);
	
	QObject::connect(this->addDogButton, SIGNAL(clicked()), this, SLOT(addDogButtonHandler()));
	QObject::connect(this->removeDogButton, &QPushButton::clicked, this, &GUI::removeDogButtonHandler);
	QObject::connect(this->updateDogButton, &QPushButton::clicked, this, &GUI::updateDogButtonHandler);

	QObject::connect(this->adoptDogButton, &QPushButton::clicked, this, &GUI::adoptDogButtonHandler);
	QObject::connect(this->nextDogButton, &QPushButton::clicked, this, &GUI::nextDogButtonHandler);
	QObject::connect(this->photoDogButton, &QPushButton::clicked, this, &GUI::photoDogButtonHandler);
	QObject::connect(this->openButton, &QPushButton::clicked, this, &GUI::openFileButtonHandler);


	//QObject::connect(this, SIGNAL(addDogSignal(std::string, std::string, int, std::string)), this, SLOT(addDog(std::string, std::string, int, std::string)));
	//QObject::connect(this, &GUI::addDogSignal, this, &GUI::addDog);
	//QObject::connect(this, &GUI::repoUpdatedSignal, this, &GUI::populate);
}

void GUI::comboBoxHandler()
{
	if (this->comboBox->currentText() == " Simple ")
		this->populateDogListSimple();
	else if (this->comboBox->currentText() == " Detailed ")
		this->populateDogListDetalied();
	this->filterEdit->clear();
}

void GUI::filterHandler()
{
	QString filterData = this->filterEdit->text();
	if (filterData.size() == 0)
	{
		if (this->comboBox->currentText() == " Simple ")
			this->populateDogListSimple();
		else if (this->comboBox->currentText() == " Detailed ")
			this->populateDogListDetalied();
	}
	else
	{
		std::vector<Animal> vec = control.filterByBreedNameAge(filterData.toStdString()).getElem();
		if (this->comboBox->currentText() == " Simple ")
			this->populateSimple(vec);
		else if (this->comboBox->currentText() == " Detailed ")
			this->populateDetalied(vec);
	}

	

}

void GUI::filterHandler2()
{
	QString filterBreed = this->filterEditAdoptionName->text();
	QString filterAge = this->filterEditAdoptionAge->text();
	if (filterAge.size() == 0 && filterBreed.size() == 0)
	{
		populateUList();
	}
	else if(filterAge.size() != 0 && filterBreed.size() != 0)
	{
		std::vector<Animal> vec = control.filterAlgBreedAndAge(filterBreed.toStdString(),filterAge.toInt()).getElem();
		populateUListSimple(vec);
	}
	else
	{
		populateUList();
	}



}

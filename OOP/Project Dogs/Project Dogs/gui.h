#ifndef GUI_H
#define GUI_H
#include <QListWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <qwidget.h>
#include <qcombobox.h>
#include "ControllerAdmin.h"
#include<qmessagebox.h>

#include <QObject>

class GUI : public QWidget
{
	Q_OBJECT

public:
	GUI(ControllerAdmin& c, QWidget *parent = 0);
	~GUI();

private:
	ControllerAdmin control;

	QListWidget* dogList;
	QListWidget* adoptionList;
	QLineEdit* breedEdit;
	QLineEdit* nameEdit;
	QLineEdit* ageEdit;
	QLineEdit* photoLinkEdit;
	QLineEdit* filterEdit;
	QPushButton* addDogButton;
	QPushButton* removeDogButton;
	QComboBox* comboBox;


	void initGUI();

	void populateDogListDetalied();
	void populateDogListSimple();

	void conectComponents();

	void comboBoxHandler();
	void filterHandler();

	void populateDetalied(std::vector<Animal> vec);
	void populateSimple(std::vector<Animal> vec);
	void populate();

	int getSelectedIndex();
	void listItemChangedHandler();

signals:
	void repoUpdatedSignal();
	void addDogSignal(std::string breed, std::string name, int age, std::string link);

public slots:
	void addDogButtonHandler();
	void addDog(std::string breed, std::string name, int age, std::string link);
	
};

#endif // GUI_H

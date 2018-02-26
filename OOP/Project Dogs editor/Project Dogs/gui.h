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
	QLineEdit* filterEditAdoptionName;
	QLineEdit* filterEditAdoptionAge;

	QPushButton* addDogButton;
	QPushButton* removeDogButton;
	QPushButton* updateDogButton;

	QPushButton* adoptDogButton;
	QPushButton* nextDogButton;
	QPushButton* photoDogButton;
	QPushButton* openButton;

	QComboBox* comboBox;


	void initGUI();

	void populateDogListDetalied();
	void populateDogListSimple();

	void conectComponents();

	void comboBoxHandler();
	void filterHandler();
	void filterHandler2();

	void populateDetalied(std::vector<Animal> vec);
	void populateSimple(std::vector<Animal> vec);
	void populate();

	void populateUList();
	void populateUListSimple(std::vector<Animal>vec);

	int getSelectedIndex();
	void listItemChangedHandler();

//signals:
	//void repoUpdatedSignal();
	//void addDogSignal(std::string breed, std::string name, int age, std::string link);

private slots:
	void addDogButtonHandler();
	void removeDogButtonHandler();
	void updateDogButtonHandler();
	void adoptDogButtonHandler();
	void nextDogButtonHandler();
	void photoDogButtonHandler();
	void openFileButtonHandler();
	//void addDog(std::string breed, std::string name, int age, std::string link);
	
};

#endif // GUI_H

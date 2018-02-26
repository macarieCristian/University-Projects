#include"Ui.h"
#include<iostream>
#include<Windows.h>

void UI::printRepo()
{
	cout << "\n\t\tThe list: \n";
	Repository rep = this->controllerA.getRepo();
	for (int i = 0; i < rep.getLen(); i++)
		cout << rep.getElement(i).toString();
	cout << "\n";
}

void printMenu()
{
	cout << "\t\tThe menu: \n";
	cout << "\t1 - Add a new dog;\n";
	cout << "\t2 - Delete a dog;\n";
	cout << "\t3 - Update a dog;\n";
	cout << "\t4 - List all dogs;\n";
	cout << "\t0 - Exit.\n\n";
}

void printModeMenu()
{
	cout << "\t\tThe menu: \n";
	cout << "\t1 - Administrator mode;\n";
	cout << "\t2 - User mode;\n";
	cout << "\t0 - Exit.\n";
}

void UI::mainMenu()
{
	bool stop1 = true;
	while (stop1)
	{
		system("cls");
		printModeMenu();
		int z = -1;
		cout << "Enter your command: ";
		cin >> z;
		cout << "\n";
		if (z == 1)
		{
			system("cls");
			printMenu();
			bool stop = true;
			int x = -1;
			while (stop)
			{
				cout << "Enter your command: ";
				cin >> x;
				cout << "\n";
				if (x == 0)
				{
					cout << "\n\tThanks for using the app!\n\n";
					stop = false;
				}
				else if (x == 1)
				{
					system("cls");
					printMenu();
					cout << "Enter the breed: ";
					string breed;
					cin >> breed;
					cout << "Enter the name: ";
					string name;
					cin >> name;
					cout << "Enter the age: ";
					int age;
					cin >> age;
					cout << "Enter the link: ";
					string link;
					cin >> link;
					cout << "\n";
					int res = this->controllerA.addAnimal(breed, name, age, link);
					if (res == 0)
					{
						cout << "\nThis dog already exists!\n\n";
					}
					else
						this->printRepo();
				}
				else if (x == 2)
				{
					system("cls");
					printMenu();
					cout << "\nFor the dog you want to delete: \n";
					cout << "Enter the breed: ";
					string breed;
					cin >> breed;
					cout << "Enter the name: ";
					string name;
					cin >> name;
					int res = this->controllerA.delAnimal(breed, name);
					if (res == 0)
					{
						cout << "\nThis dog does not exist!\n\n";
					}
					else
					{
						this->printRepo();
					}
				}
				else if (x == 3)
				{
					system("cls");
					printMenu();
					cout << "\nFor the dog you want to update: \n";
					cout << "Enter the breed: ";
					string breedS;
					cin >> breedS;
					cout << "Enter the name: ";
					string nameS;
					cin >> nameS;
					cout << "\nThe new atributes: \n";
					cout << "Enter the breed: ";
					string breed;
					cin >> breed;
					cout << "Enter the name: ";
					string name;
					cin >> name;
					cout << "Enter the age: ";
					int age;
					cin >> age;
					cout << "Enter the link: ";
					string link;
					cin >> link;
					cout << "\n";
					int res = this->controllerA.updateAnimal(breedS, nameS, breed, name, age, link);
					if (res == 0)
					{
						cout << "\nThis dog does not exist!\n\n";
					}
					else
					{
						this->printRepo();
					}
				}
				else if (x == 4)
				{
					system("cls");
					printMenu();
					this->printRepo();
				}
				else
				{
					cout << "\tInvalid command!\n\n";
					system("pause");
				}
			}
		}
		else if (z == 2)
		{

		}
		else if (z == 0)
		{
			cout << "\n\tThanks for using the app;\n";
			stop1 = false;
		}
		else
		{
			cout << "\tInvalid command!\n\n";
			system("pause");
		}
	}
}
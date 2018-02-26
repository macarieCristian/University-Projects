#include"Ui.h"
#include<iostream>
#include<string>
#include<Windows.h>
#include<algorithm>
#include<fstream>
#include<sstream>
#include"RepoExceptions.h"

using namespace std;

int readInteger(string msg)
{
	bool ok = true;
	while (ok)
	{
		try
		{
			string x;
			cout << msg;
			cin >> x;
			int a = stoi(x);
			ok = false;
			return a;
		}
		catch (...)
		{
			cout << "\nPlease enter a integer value.\n";
		}
	}
	
}

void UI::printRepo()
{
	cout << "\n\t\tThe list: \n";
	Repository rep = this->controllerA.getRepo();
	for_each(rep.getElem().begin(), rep.getElem().end(), [](Animal &a) {cout << a.toString(); });
	cout << "\n";
}

void printARepo(Repository rep)
{
	if (rep.getLen() == 0)
		cout << "There are no items matching this filter;\n";
	else
	{
		cout << "\n\t\tThe list: \n";
		for_each(rep.getElem().begin(), rep.getElem().end(), [](Animal &a) {cout << "Breed: " + a.getBreed() + "   Name: " + a.getName() + "   Age: " + to_string(a.getAge()) + "\n"; });
		cout << "\n";
	}
}

void UI::printUList()
{
	if (this->controllerA.getUList()->getSize() == 0)
		cout << "\n\nThe adoption list is empty.\n\n";
	else
	{
		cout << "\n\t\tThe adoption list: \n";
		UserList *ul = this->controllerA.getUList();
		for_each(ul->getUList().begin(), ul->getUList().end(), [](Animal &a) {cout << "Breed: " + a.getBreed() + "   Name: " + a.getName() + "   Age: " + to_string(a.getAge()) + "\n"; });
		cout << "\n";
	}
}

void UI::printCAnimal()
{
	Animal a = this->controllerA.getRepo().getCurrAnimal();
	cout << "\n\t\t";
	string string1 = "Breed: " + a.getBreed() + "   Name: " + a.getName() + "   Age: " + to_string(a.getAge()) + "\n";
	cout << string1;
}

void printUserMenu()
{
	cout << "\t\tThe menu: \n";
	cout << "\t1 - Start show app;\n";
	cout << "\t2 - Show adoption list;\n";
	cout << "\t3 - See all the dogs of a given breed, having an age less than a given number;\n";
	cout << "\t4 - Save to CSV file or HTML format;\n";
	cout << "\t5 - Display using notepad or chrome;\n";
	cout << "\t0 - Exit to mode menu.\n\n";
}

void printUserMenuApp()
{
	cout << "\t\tThe app menu: \n";
	cout << "\t1 - Addopt this dog;\n";
	cout << "\t2 - Next dog;\n";
	cout << "\t3 - Show image of this dog;\n";
	cout << "\t0 - Exit app.\n\n";
}

void printMenu()
{
	cout << "\t\tThe menu: \n";
	cout << "\t1 - Add a new dog;\n";
	cout << "\t2 - Delete a dog;\n";
	cout << "\t3 - Update a dog;\n";
	cout << "\t4 - List all dogs;\n";
	cout << "\t5 - List all dogs sorted ascending by name;\n";
	cout << "\t6 - Get the number of instances;\n";
	cout << "\t0 - Exit to mode menu.\n\n";
}

void printModeMenu()
{
	cout << "\t\tThe menu: \n";
	cout << "\t1 - Administrator mode;\n";
	cout << "\t2 - User mode;\n";
	cout << "\t0 - Exit windows.\n";
}

void UI::mainMenu()
{
	bool stop1 = true;
	while (stop1)
	{
			system("cls");
			printModeMenu();
			int z = readInteger("Enter your command: ");
			cout << "\n";
			if (z == 1)
			{
				system("cls");
				printMenu();
				bool stop = true;
				int x = -1;
				while (stop)
				{
					x = readInteger("Enter your command: ");
					cout << "\n";
					if (x == 0)
					{
						cout << "\n\tThanks for using the app!\n\n";
						stop = false;
					}
					else if (x == 1)
					{
						try
						{
							system("cls");
							printMenu();
							cout << "Enter the breed: ";
							string breed;
							cin >> breed;
							cout << "Enter the name: ";
							string name;
							cin >> name;
							int age;
							age = readInteger("Enter the age: ");
							cout << "Enter the link: ";
							string link;
							cin >> link;
							cout << "\n";
							this->controllerA.addAnimal(breed, name, age, link);
							this->printRepo();
						}
						catch (RepoExceptions &e)
						{
							cout << e.what() << endl;
						}
							
					}
					else if (x == 2)
					{
						try
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
							this->controllerA.delAnimal(breed, name);
							this->printRepo();
						}
						catch (RepoExceptions &e)
						{
							cout << e.what() << endl;
						}
					}
					else if (x == 3)
					{
						try
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
							int age;
							age = readInteger("Enter the age: ");
							cout << "Enter the link: ";
							string link;
							cin >> link;
							cout << "\n";
							this->controllerA.updateAnimal(breedS, nameS, breed, name, age, link);
							this->printRepo();
						}
						catch (RepoExceptions &e)
						{
							cout << e.what() << endl;
						}
					}
					else if (x == 4)
					{
						system("cls");
						printMenu();
						this->printRepo();
					}
					else if (x == 5)
					{

						system("cls");
						printMenu();
						Repository rep = this->controllerA.getRepo();
						rep.sortAlg();
						printARepo(rep);
					}
					else if (x == 6)
					{
						cout << "\n\n\tThe number of max instances: " << Animal::getNumMI() << "\n";
						cout << "\tThe number of curent instances: " << Animal::getNumCI() << "\n";
					}
					else
					{
						cout << "\tInvalid command!\n\n";
						system("pause");
					}
				}
			}

			//User interface
			else if (z == 2)
			{
				system("cls");
				printUserMenu();
				bool stop = true;
				int x = -1;
				while (stop)
				{
					x = readInteger("Enter your command: ");
					cout << "\n";
					if (x == 0)
					{
						cout << "\n\tThanks for using the app!\n\n";
						stop = false;
					}
					else if (x == 1)
					{
						int y = -1;
						bool stop1 = true;
						while (stop1)
						{
							system("cls");
							printCAnimal();
							cout << "\n";
							printUserMenuApp();
							y = readInteger("Enter your command: ");
							cout << "\n";
							if (y == 0)
							{
								cout << "\n\tThanks for using the app!\n\n";
								stop1 = false;
								system("cls");
								printUserMenu();
							}
							else if (y == 1)
							{
								try
								{
									Animal a = this->controllerA.getRepo().getCurrAnimal();
									this->controllerA.addUList(a);
									system("cls");
								}
								catch (RepoExceptions &e)
								{
									cout << e.what() << endl;
									system("pause");
								}
							}
							else if (y == 2)
							{
								this->controllerA.nextA();
								system("cls");
								printCAnimal();
								cout << "\n";
								printUserMenuApp();
							}
							else if (y == 3)
							{
								this->controllerA.play();
							}
						}
					}
					else if (x == 2)
					{
						system("cls");
						printUserMenu();
						printUList();
					}
					else if (x == 3)
					{
						system("cls");
						printUserMenu();
						string breed;
						int age;
						cout << "\nEnter the breed: ";
						cin >> breed;
						age = readInteger("\nEnter the age: ");
						cout << "\n";
						system("cls");
						printUserMenu();
						Repository r = this->controllerA.filterAlgBreedAndAge(breed, age);
						printARepo(r);
					}
					else if (x == 4)
					{
						try
						{
							controllerA.saveUserList("");
							cout << "The content was saved successfuly!\n";
						}
						catch (RepoExceptions &e)
						{
							cout << e.what();
						}
					}
					else if (x == 5)
					{
						controllerA.openUserFile();
					}
				}
			}
			else if (z == 0)
			{
				cout << "\n\tThanks for using my app!\n\n";
				system("pause");
				stop1 = false;
			}
			else
			{
				cout << "\tInvalid command!\n\n";
				system("pause");
			}
		
	}
	
}
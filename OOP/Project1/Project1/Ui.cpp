#include "Ui.h"
#include<string>
#include<iostream>

using namespace std;

void printList(Repository repo)
{
	cout << "\n\tThe list is:\n";
	for (int i = 0; i < repo.getLen(); i++)
		cout << repo.getTask(i).toString();
}

void printMenu()
{
	cout << "\n\tThe menu:\n";
	cout << "1 - Add a task;\n";
	cout << "2 - List all;\n";
	cout << "3 - Given two task, swap priorites;\n";
	cout << "4 - Show all task with priority less than a given value sorted descending by duration;\n";
	cout << "0 - Exit.\n";

}

void Ui::mainMenu()
{
	std::string a{ "Sarmale" };
	cout << "result= " << a.find("e") << " Len= " << a.length();
	bool ok = true;
	int c = -1;
	while (ok)
	{
		printMenu();
		cout << "\nEnter a command:";
		cin >> c;
		if (c == 0)
			ok = false;
		else if (c == 1)
		{
			string des;
			int d, p;
			cout << "Enter description: ";
			cin >> des;
			cout << "Enter duration: ";
			cin >> d;
			cout << "Enter priority: ";
			cin >> p;
			int res = controller.addTask(des, d, p);
			if (res == 0)
				cout << "\n This task already exists!";
		}
		else if (c == 2)
			printList(controller.getRepo());
		else if (c == 3)
		{
			string d1, d2;
			cout << "Enter the firs description: ";
			cin >> d1;
			cout << "Enter the secound description: ";
			cin >> d2;
			int res = controller.swap(d1, d2);
			if (res == 0)
				cout << "\n Error!";
		}
		else if (c == 4)
		{
			int n;
			cout << "Enter a number: ";
			cin >> n;
			Repository r = controller.filter(n);
			r.sortDes();
			printList(r);
		}
	}
}

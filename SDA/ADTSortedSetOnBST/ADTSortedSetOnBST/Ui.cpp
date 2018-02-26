#include "Ui.h"
#include<iostream>
using namespace std;

void printMenu()
{
	string str = "\n\tThe menu:\n";
	str += "1 - Add a licence plate.\n";
	str += "2 - Remove a licence plate.\n";
	str += "3 - List all the licence plates.\n";
	str += "4 - Write to a file all licence plates from a district.\n";
	str += "5 - Search a licence plate.\n";
	str += "0 - Exit.\n";
	cout << str;
}

void printASortedSet(SortedSet s)
{
	cout << endl;
	if (s.size() == 0)
		cout << "There are no elements!\n";
	else
	{
		for (IteratorSS it = s.begin(); it != s.end(); it++)
		{
			cout << it.getCurrent().toString();
		}
	}
}

void Ui::startApp()
{
	int x;
	while (1)
	{
		try
		{
			printMenu();
			cout << "\nEnter your command: ";
			cin >> x;
			if (x == 0)
				break;
			else if (x == 1)
			{
				string d, n, c;
				cout << "\nEnter the district: ";
				cin >> d;
				cout << "\nEnter the number: ";
				cin >> n;
				cout << "\nEnter the combination: ";
				cin >> c;
				ctrl.addLicencePlate(d, n, c);
				printASortedSet(ctrl.getElements());
			}
			else if (x == 2)
			{
				string d, n, c;
				cout << "\nEnter the district: ";
				cin >> d;
				cout << "\nEnter the number: ";
				cin >> n;
				cout << "\nEnter the combination: ";
				cin >> c;
				ctrl.removeLicencePlate(d, n, c);
				printASortedSet(ctrl.getElements());
			}
			else if (x == 3)
			{
				printASortedSet(ctrl.getElements());
			}
			else if (x == 4)
			{
				string d, fn;
				cout << "\nEnter the district: ";
				cin >> d;
				cout << "\nEnter the file name: ";
				cin >> fn;
				ctrl.writeToFileDistrict(fn, d);
				cout << "\nThe operation was successfuly!\n";
			}
			else if (x == 5)
			{
				string asw;
				cout << "\nSearch: ";
				cin >> asw;
				SortedSet ss = ctrl.searchFilter(asw);
				printASortedSet(ss);
				ss.destroy();
			}
		}
		catch (exception& e)
		{
				cout << e.what();
		}
	}
}

#include "Ui.h"
#include<string>
#include<iostream>

using namespace std;



void printMenu()
{
	string str;
	cout << "1 - Add a new song;\n";
	cout << "2 - Show all songs;\n";
	cout << "3 - New song;\n";
	cout << "0 - Exit;\n";
}

void printRepo(Repository rep)
{
	for (int i = 0;i < rep.getLen(); i++)
	{
		cout << rep.getSong(i).toString();
	}
}

void Ui::mainMenu()
{
	bool ok = true;
	int c = -1;
	while (ok)
	{
		printMenu();
		cout << "\nEnter a command: ";
		cin >> c;
		if (c == 0)
		{
			ok = false;
		}
		else if (c == 1)
		{
			string name, list[50];
			int len;
			cout << "Enter tha name: ";
			cin >> name;
			cout << "Enter the number of notes: ";
			cin >> len;
			for (int i = 0; i < len; i++)
			{
				cout << "Enter a note: ";
				cin >> list[i];
			}
			int res = controller.addSong(name, list, len);
			if (res == 1)
			{
				cout << "\nThe song was added\n";
			}
			if (res == 0)
			{
				cout << "\nThere already exist a song with this name!\n";
			}
		}
		else if (c == 2)
		{
			Repository r = controller.getRepo();
			r.sortName();
			printRepo(r);
		}
		else if (c == 3)
		{
			int p1, p2;
			cout << "\nEnter th position of the first song: ";
			cin >> p1;
			cout << "Enter the pos of the secound song: ";
			cin >> p2;
			Song s = controller.newSong(p1, p2);
			cout << "\n" + s.toString()+ "\n";
		}

	}
}

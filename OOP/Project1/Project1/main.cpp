#include"Ui.h"
#include<locale>
#include<iostream>
#include<algorithm>

using namespace std;

string to_lower(string str)
{
	string copy = str;
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

void main()
{
	/*Repository repo{};
	Controller c{ repo };
	c.addTask("Sarmale", 200, 1);
	c.addTask("Zama", 60, 2);
	c.addTask("Cartofi", 120, 1);
	c.addTask("Varza", 30, 3);
	c.addTask("dana", 40, 5);

	Ui ui{ c };

	ui.mainMenu();*/

	string a = "SaRmA GG";
	cout << to_lower(a) << endl;
	cout << a << endl;
	system("pause");
}




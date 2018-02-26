#include "opa.h"
#include<algorithm>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;






std::vector<int>& opa::operator/(int x)
{
	elem.push_back(x);
	return elem;
}


/*void main()
{
	opa list;
	list.elem.push_back(1);
	list.elem.push_back(2);
	list.elem.push_back(3);
	list.elem.push_back(4);
	list / 6;
	list / 7;
	list / 10;
	for_each(list.elem.begin(), list.elem.end(), [](int &x) {cout << x << " "; });
	cout << endl;
	cout << "\n\n\n";

	string a{ "Ana are mere multe!" };
	string str = "";
	string sp = " ";
	string lista[4];
	int k = 0;
	for (int i = 0; i < a.length(); i++)
	{
		
		if (a[i] == sp[0])
		{
			lista[k++] = str;
			str = "";
		}
		else
			str += a[i];
	}
	lista[k++] = str;
	for (int i = 0; i < k; i++)
		cout << lista[i] + "\n";
	cout << "\n\n";

	for (int i : list.elem)
		cout << i;

	system("pause");
}*/

/*void main()
{
	try
	{
		int x;
		cout << "Enter int:";
		cin >> x;
		cout << x;
	}
	catch (...)
	{
		cout << "Enter a int please.";
	}
	system("pause");
}*/
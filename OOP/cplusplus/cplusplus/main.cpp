#include"Pisica.h"

using namespace std;

void filter(Pisica lista[10], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
		sum += lista[i].getNrMPui();
	for (int i = 0; i < len; i++)
		if (lista[i].getNrMPui() < (sum / len))
			lista[i].print();

}

int main()
{
	Pisica a{ "pasd",1,5 };
	Pisica b{ "fsad",2,3 };
	Pisica c{ "rsar",1,4 };
	a.print();
	b.print();
	c.print();
	cout << "\n\n";

	Pisica lista[10];
	lista[0] = a;
	lista[1] = b;
	lista[2] = c;
	int len = 3;

	for (int i = 0; i < len; i++)
		lista[i].print();

	if (a > b)
		cout << "ceva";
	else
		cout << "altceva";
	cout << "\n\n";

	filter(lista, len);

	cout << "\n\n";

	a.print();
	a -= 2;
	a.print();
	cout << "\n\n";
	rasaDiff(a, lista, len);


	cout << endl;
	system("pause");
	return 0;
}
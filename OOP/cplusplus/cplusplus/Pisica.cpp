#include "Pisica.h"

using namespace std;

Pisica::Pisica()
{
	rasa = "";
	varsta = 0;
	nrMediuPui = 0;
}

Pisica::Pisica(std::string ras, int var, int nrmp)
{
	rasa = ras;
	varsta = var;
	nrMediuPui = nrmp;
}

void Pisica::print()
{
	cout << "Rasa:" << rasa << "   Varsta: " << varsta << "   Nr mediu pui: " << nrMediuPui << "\n";
}

bool Pisica::operator>(Pisica & a)
{
	if (varsta == a.getVarsta())
		return (nrMediuPui > a.getNrMPui());
	return(varsta > a.getVarsta());
}

void Pisica::operator-=(int x)
{
	nrMediuPui -= x;
}

void rasaDiff(Pisica & a, Pisica lista[], int len)
{
	for (int i = 0; i < len; i++)
		if (lista[i].getRasa() != a.getRasa())
			lista[i].print();

}

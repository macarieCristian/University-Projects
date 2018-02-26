#include "CSVUserList.h"
#include<fstream>
#include"RepoExceptions.h"
#include <Windows.h>

using namespace std;

void CSVUserList::writeToFile()
{
	ofstream file("fila.txt");

	if (!file.is_open())
		throw RepoExceptions("The file could not be opened!");

	for (Animal a : this->list)
		file << a;

	file.close();

}

void CSVUserList::displayAdoptionList()
{
	string aux = "fila.txt";
	ShellExecuteA(NULL, NULL, "c:\\Windows\\system32\\notepad.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}

#include "HTMLUserList.h"
#include<fstream>
#include"RepoExceptions.h"
#include <Windows.h>

using namespace std;

void HTMLUserList::writeToFile()
{
	ofstream file("fila.html");

	if (!file.is_open())
		throw RepoExceptions("The file could not be opened!");

	file << "<!DOCTYPE html>\n"
		<< "<html>\n"
		<< "<head>\n"
		<< "<title>AdoptionList</title>\n"
		<< "</head>\n"
		<< "<body>\n"
		<< "<table border=""1"">\n"
		<< "<tr>\n"
		<< "<td>Breed</td>\n"
		<< "<td>Name</td>\n"
		<< "<td>Age</td>\n"
		<< "<td>Photo link</td>\n"
		<< "</tr>\n";
	for (Animal a : this->list)
	{
		file << "<tr>\n"
			<< "<td>" + a.getBreed() + "</td>\n"
			<< "<td>" + a.getName() + "</td>\n"
			<< "<td>" + to_string(a.getAge()) + "</td>\n"
			<< "<td><a href =" + a.getPhoto() + ">Link</a></td>\n"
			<< "</tr>\n";
	}
	file << "</table>\n"
		<< "</body>\n"
		<< "</html>";

	file.close();
}

void HTMLUserList::displayAdoptionList()
{

	string aux = "fila.html";
	ShellExecuteA(NULL, NULL, "chrome.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);

}

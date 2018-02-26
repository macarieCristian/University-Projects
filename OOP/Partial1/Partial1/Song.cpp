#include "Song.h"
#include<string>

using namespace std;



Song::Song(std::string name1, std::string list[50], int len)
{
	name = name1;
	lenNotes = len;
	for (int i = 0; i < len; i++)
	{
		this->listNotes[i] = list[i];
	}

}

std::string Song::toString()
{
	string str = "Name: " + name + "   List: ";
	for (int i = 0; i < lenNotes; i++)
		str += listNotes[i] + ", ";
	str += "\n";
	return str;



}

#pragma once
#include<string>



class Song
{
private:
	std::string name;
	std::string listNotes[50];
	int lenNotes;

public:
	Song() : name("") , lenNotes(0) {}
	Song(std::string name1,std::string list[50], int len);

	std::string getName() { return this->name; }
	std::string* getNotes() { return this->listNotes; }
	int getLenNotes() { return this->lenNotes; }

	void setName(std::string value) { this->name = value; }
	void setLenNotes(int value) { this->lenNotes = value; }

	std::string toString();

};


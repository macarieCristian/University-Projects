#pragma once
#include "UserList.h"

class FileUserList : public UserList
{
protected:
	std::string filenameCSV;
public:

	FileUserList(): UserList{},filenameCSV{""}{}
	virtual ~FileUserList(){}

	void setCSVFile(const std::string& fname) { filenameCSV = fname; }

	virtual void writeToFile() = 0;
	virtual void displayAdoptionList() = 0;

};


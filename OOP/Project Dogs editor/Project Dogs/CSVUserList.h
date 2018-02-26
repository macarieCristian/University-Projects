#pragma once
#include "FileUserList.h"
#include <string>

class CSVUserList : public FileUserList
{
public:

	void writeToFile() override;

	void displayAdoptionList() override;
};


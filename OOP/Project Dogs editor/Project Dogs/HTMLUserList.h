#pragma once
#include "FileUserList.h"


class HTMLUserList : public FileUserList
{
public:
	void writeToFile() override;

	void displayAdoptionList() override;
};


#pragma once
#include"ControllerAdmin.h"

class UI
{
private:
	ControllerAdmin controllerA;

public:
	UI(const ControllerAdmin& c) : controllerA(c) {}
	void printRepo();
	void mainMenu();
	void UI::printUList();
	void UI::printCAnimal();

	void readFromCSVFile(std::string fileName);
	void writeToCSVFile(std::string fileName);
};
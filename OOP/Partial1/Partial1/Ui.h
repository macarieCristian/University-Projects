#pragma once
#include"Controller.h"


class Ui
{
private:
	Controller controller;
public:
	Ui(Controller& control) : controller(control) {}

	void mainMenu();

};


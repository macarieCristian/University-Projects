#pragma once
#include"Controller.h"


class Ui
{
private:
	Controller controller;
public:
	Ui(Controller& con) : controller(con) {}

	void mainMenu();

};


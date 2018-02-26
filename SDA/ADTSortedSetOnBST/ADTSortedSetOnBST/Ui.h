#pragma once
#include"Controler.h"


class Ui
{
private:
	Controler ctrl;
public:
	Ui(Controler& c) : ctrl{c}{}
	~Ui(){}

	void startApp();
};


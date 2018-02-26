#pragma once
#include"Task.h"


class Repository
{
private:
	Task list[100];
	int len;

public:
	Repository();

	int getLen() { return len; }

	void add(Task t);
	Task& getTask(int pos);

	void sortDes();
};


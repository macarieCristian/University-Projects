#pragma once
#include"Song.h"


class Repository
{
private:
	Song list[100];
	int len;
public:
	Repository();

	void add(Song s);
	//ads a new song object to the list of songs
	//input a song object
	Song& getSong(int pos);

	int getLen() { return len;}

	void sortName();




};


#pragma once
#include"Repository.h"

class Controller
{
private:
	Repository repo;
public:
	Controller(Repository& repo1) : repo(repo1) {}

	int findSong(std::string name);

	int addSong(std::string name, std::string lista[50], int len);
	//adds a new song to the repository list
	//name is a string
	//lista is a list of notes
	// len is the length of the list
	//returns 1 if successfuly added
	//returns 0 if if the song already exists

	Repository getRepo() { return repo; }

	Song newSong(int p1, int p2);

	std::string mostUsed();
	//returns the most used note in all songs from the repo
	//output a string value representing the most used note in all of the songs

};


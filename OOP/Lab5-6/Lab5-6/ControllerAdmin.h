#pragma once
#include<string>
#include"Repository.h"
using namespace std;

class ControllerAdmin
{
public:
	Repository repo;
public:
	int addAnimal(string breed, string name, int age, string photo);
	// adds a new animal object to the repo
	//with the specified atributes
	//returns 1 if successfuly added
	//returns 0 if the animal already exists

	int findElementOnPos(string breed, string name);
	//return the index of the searched animal
	//return -1 if not found

	int delAnimal(string breed, string name);
	//deletes a animal
	//returns 1 if successfuly deleted
	//returns 0 if the animal does not exists

	int updateAnimal(string breedSearch, string nameSearch, string breed, string name, int age, string photo);
	//updates the animal with the breedsearch and namesearch atributes
	//returns 1 if successfuly updated
	//returns 0 if the animal does not exists

	int ControllerAdmin::getLength();
	Repository ControllerAdmin::getRepo();
};
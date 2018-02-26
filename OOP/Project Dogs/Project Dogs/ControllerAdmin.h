#pragma once
#include<string>
#include"Repository.h"
#include"FileUserList.h"
//using namespace std;

class ControllerAdmin
{
private:
	Repository repo;
	FileUserList *uList;
public:
	ControllerAdmin(const Repository& r, FileUserList *ul) : repo{ r }, uList{ ul } {}
	
	int addAnimal(const std::string& breed, const std::string& name, int age, const std::string& photo);
	// adds a new animal object to the repo
	//with the specified atributes
	//returns 1 if successfuly added
	//returns 0 if the animal already exists

	int addUList(const Animal& a);
	//1 if succesfuly added
	//0 if the animal also exists
	
	UserList* getUList() { return this->uList; }
	//returns the UserList object
	
	void nextA();
	void play();
	//from the lower levels

	int findElementOnPosAlg(const std::string& breed, const std::string& name);
	//int findElementOnPos(const std::string& breed, const std::string& name);
	//return the index of the searched animal
	//return -1 if not found

	int delAnimal(const std::string& breed, const std::string& name);
	//deletes a animal
	//returns 1 if successfuly deleted
	//returns 0 if the animal does not exists

	int updateAnimal(const std::string& breedSearch,const std::string& nameSearch, const std::string& breed, const std::string& name, int age, const std::string& photo);
	//updates the animal with the breedsearch and namesearch atributes
	//returns 1 if successfuly updated
	//returns 0 if the animal does not exists

	//Repository filterByBreedAndAge(const std::string& breed, int age);

	Repository filterAlgBreedAndAge(const std::string& breed, int age);
	//returns a repository object with those animals which have the given breed ant the age less than the given age

	Repository filterByBreedNameAge(std::string& string);

	int ControllerAdmin::getLength();
	//returns the length of the repository object
	
	Repository &ControllerAdmin::getRepo();

	void ControllerAdmin::testController();

	void saveUserList(const std::string& filename);
	void openUserFile() const;
};
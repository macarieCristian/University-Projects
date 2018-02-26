#include"ControllerAdmin.h"
#include<assert.h>
#include<algorithm>
#include"RepoExceptions.h"
#include"CSVUserList.h"
using namespace std;


int ControllerAdmin::addAnimal(const string& breed, const string& name, int age, const string& photo)
{
	if (this->findElementOnPosAlg(breed, name) != -1)
	{
		throw RepoExceptions("This dog already exists!");
		return 0;
	}
	Animal a = Animal(breed, name, age, photo);
	this->repo.addElement(a);
	Animal::incC();
	Animal::incM();
	return 1;
}

int ControllerAdmin::addUList(const Animal & a)
{
	if (this->uList->isInside(a) == -1)
	{
		this->uList->add(a);
		return 1;
	}
	throw RepoExceptions("This dog is already in your adoption list!");
	return 0;
}

void ControllerAdmin::nextA()
{
	this->repo.next();
}

void ControllerAdmin::play()
{
	this->repo.Olink();
}

int ControllerAdmin::findElementOnPosAlg(const std::string & breed, const std::string & name)
{
	auto it = find_if(this->repo.getElem().begin(), this->repo.getElem().end(), [&breed, &name](Animal &a) {return (a.getBreed() == breed) && (a.getName() == name); });
	if (it == this->repo.getElem().end())
		return -1;
	return distance(this->repo.getElem().begin(), it);
}

int ControllerAdmin::delAnimal(const string& breed, const string& name)
{
	int x = this->findElementOnPosAlg(breed, name);
	if (x == -1)
		throw RepoExceptions("The dog you're trying to delete doesn't exist!");
	this->repo.delElement(x);
	return 1;
}

int ControllerAdmin::updateAnimal(const string& breedSearch, const string& nameSearch, const string& breed, const string& name, int age, const string& photo)
{
	int x = this->findElementOnPosAlg(breedSearch, nameSearch);
	if (x == -1)
		throw RepoExceptions("The dog you're trying to update doesn't exist!");
	const Animal a{ breed,name,age,photo };
	this->repo.updateElement(a,x);
	return 1;
}

Repository ControllerAdmin::filterAlgBreedAndAge(const std::string & breed, int age)
{
	vector<Animal> repo1 = this->getRepo().getElem();
	vector<Animal> repo2(this->getLength());
	auto it = copy_if(repo1.begin(), repo1.end(), repo2.begin(), [breed, age](Animal a) {return (a.getBreed() == breed) && (a.getAge() < age); });
	Repository r{};
	repo2.resize(distance(repo2.begin(), it));
	r.getElem() = repo2;
	return r;


}

string to_lower(string str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
	return str;
}

Repository ControllerAdmin::filterByBreedNameAge(std::string & string)
{
	string = to_lower(string);
	vector<Animal> repo1 = this->getRepo().getElem();
	vector<Animal> repo2(this->getLength());
	auto it = copy_if(repo1.begin(), repo1.end(), repo2.begin(), [string](Animal a) {return !((to_lower(a.getBreed()).find(string)) && (to_lower(a.getName()).find(string)) && (to_lower(to_string(a.getAge())).find(string))); });
	Repository r{};
	repo2.resize(distance(repo2.begin(), it));
	r.getElem() = repo2;
	return r;



	
}

int ControllerAdmin::getLength()
{
	return this->repo.getLen();
}

Repository &ControllerAdmin::getRepo()
{
	return this->repo;
}

void ControllerAdmin::testController()
{
	Animal a("Dog", "Rex", 10, "www.htp.com");
	Animal b{ "ra","r",1,"ww" };
	Repository rep{};
	FileUserList *ul1 = new CSVUserList{};
	ControllerAdmin controller{rep, ul1};
	assert(controller.getLength() == 0);
	controller.addAnimal("Dog", "Rex", 10, "ww.ww.ww");
	assert(controller.addAnimal("Dog", "Rex", 10, "ww.ww.ww") == 0);
	controller.play();
	assert(controller.getLength() == 1);
	assert(controller.findElementOnPosAlg("Dog", "Rex") == 0);
	assert(controller.findElementOnPosAlg("Dog", "Rex1") == -1);
	controller.updateAnimal("Dog", "Rex", "dada", "d", 11, "ww");
	assert(controller.updateAnimal("Dog", "Rex", "dada", "d", 11, "ww") == 0);
	assert(controller.getRepo().getElement(0).getAge() == 11);
	controller.delAnimal("dada", "d");
	assert(controller.delAnimal("dada", "d") == 0);
	assert(controller.getLength() == 0);
	controller.addUList(a);
	assert(controller.addUList(a) == 0);
	Repository r = controller.filterAlgBreedAndAge("Dog", 0);
	Repository r1 = controller.getRepo();
	UserList *ul = controller.getUList();
	controller.nextA();
}

void ControllerAdmin::saveUserList(const std::string & filename)
{
	if (this->uList == nullptr)
		return;
	this->uList->setCSVFile(filename);
	this->uList->writeToFile();
}

void ControllerAdmin::openUserFile() const
{
	if (this->uList == nullptr)
		return;
	this->uList->displayAdoptionList();
}


/*int main()
{
	Repository r{};
	ControllerAdmin c{r};
	c.testController();
	system("pause");
	return 0;
}*/

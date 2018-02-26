#include"ControllerAdmin.h"
#include<assert.h>


int ControllerAdmin::addAnimal(string breed, string name, int age, string photo)
{
	if (this->findElementOnPos(breed, name) != -1)
		return 0;
	Animal a = Animal(breed, name, age, photo);
	this->repo.addElement(a);
	return 1;
}

int ControllerAdmin::findElementOnPos(string breed, string name)
{
	for (int i = 0; i < this->repo.getLen(); i++)
		if ((this->repo.getElement(i).getBreed() == breed) && (this->repo.getElement(i).getName() == name))
			return i;
	return -1;
}

int ControllerAdmin::delAnimal(string breed, string name)
{
	int x = this->findElementOnPos(breed, name);
	if (x == -1)
		return 0;
	else
	{
		this->repo.delElement(x);
		return 1;
	}
}

int ControllerAdmin::updateAnimal(string breedSearch, string nameSearch, string breed, string name, int age, string photo)
{
	int x = this->findElementOnPos(breedSearch, nameSearch);
	if (x == -1)
		return 0;
	this->repo.elem.array[x].setBreed(breed);
	this->repo.elem.array[x].setName(name);
	this->repo.elem.array[x].setAge(age);
	this->repo.elem.array[x].setPhoto(photo);
	return 1;
}

int ControllerAdmin::getLength()
{
	return this->repo.getLen();
}

Repository ControllerAdmin::getRepo()
{
	return this->repo;
}

void testController()
{
	Animal a = Animal::Animal("Dog", "Rex", 10, "www.htp.com");
	DynamicArray arr = DynamicArray(10);
	Repository rep = Repository{ arr };
	ControllerAdmin controller = ControllerAdmin{rep};
	assert(controller.getLength() == 0);
	controller.addAnimal("Dog", "Rex", 10, "ww.ww.ww");
	assert(controller.getLength() == 1);
	assert(controller.findElementOnPos("Dog", "Rex") == 0);
	assert(controller.findElementOnPos("Dog", "Rex1") == -1);
	controller.updateAnimal("Dog", "Rex", "dada", "d", 11, "ww");
	assert(controller.getRepo().getElement(0).getAge() == 11);
	controller.delAnimal("dada", "d");
	assert(controller.getLength() == 0);
}

/*
int main()
{
	testController();
	system("pause");
	return 0;
}
*/
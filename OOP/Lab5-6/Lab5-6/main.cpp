#include"Ui.h"
#include<Windows.h>

int main()
{
	DynamicArray dyArr = DynamicArray(10);
	Repository repo = Repository{ dyArr };
	ControllerAdmin controlA = ControllerAdmin{ repo };

	controlA.addAnimal("Pitbul", "Rex", 3, "www.photo1.com");
	controlA.addAnimal("Pitbul", "Rexy", 4, "www.photo2.com");
	controlA.addAnimal("Labrador", "Lexy", 2, "www.photo3.com");
	controlA.addAnimal("Rottweiler", "Baxter", 6, "www.photo4.com");
	controlA.addAnimal("Pug", "Ozzie", 1, "www.photo5.com");

	UI ui = UI{ controlA };
	ui.mainMenu();

	//system("pause");
	return 0;
}
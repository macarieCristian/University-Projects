#include "Interface.h"
#include <crtdbg.h>
int main()
{
	testRepo();
	testController();
	Repository* repo = newRepository();
	Controller* control = newController(repo);
	addMedication(control, "Arcoxia", 100, 15, 20.4);
	addMedication(control, "Lioresal", 500, 40, 40);
	addMedication(control, "Milgamma", 250, 60, 10.8);
	addMedication(control, "Paracetamol",750,5,23);
	addMedication(control, "Multivitamin", 50, 80, 50.1);
	addMedication(control, "Digoxin", 150, 40, 150);
	addMedication(control, "Diclofenac", 200, 100, 34);
	addMedication(control, "Aspirin", 500, 80, 20);
	addMedication(control, "Cyanide", 450, 3, 100);
	addMedication(control, "Milgamma", 100, 1, 103);
	addMedication(control, "Milgamma", 50, 15, 62);
	addMedication(control, "Milgamma", 150, 100, 35);

	Interface* ui = createInterface(control);
	mainMenu(ui);
	destroyInterface(ui);
	_CrtDumpMemoryLeaks();

}
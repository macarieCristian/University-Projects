#include "Interface.h"
#include <stdio.h>
Interface* createInterface(Controller* control)
{
	Interface* ui = (Interface*)malloc(sizeof(Interface));
	ui->control = control;
	return ui;
}
void destroyInterface(Interface* ui)
{
	destroyController(ui->control);
	free(ui);

}

void printMenu()
{
	printf("\n");
	printf("1-add new medication\n");
	printf("2-delete medication\n");
	printf("3-update medication\n");
	printf("4-list all medications\n");
	printf("5-filter by a string\n");
	printf("6-filter affordable medications\n");
	printf("7-display medications with supply less then x\n");
	printf("8-display by name\n");
	printf("0-exit\n");
}
int readNumber(const char* msg)
{
	int res, ok = 0,err=0;
	char s[15];
	while (ok == 0)
	{
		printf("%s", msg);
		scanf("%s", s);
		err = sscanf(s, "%d", &res);
		ok = (err == 1);
		if (!ok)printf("pls input a valid number\n");
	}

	return res;
}

int validCommand(int command)
{
	if (command < 0 || command>8)
		return 0;
	return 1;
}
int add(Interface* ui)
{
	char name[20];
	printf("enter medication name: ");
	scanf("%s", name);
	int concentration=readNumber("enter concentration"), quantity=readNumber("enterQuantity");
	float price;
	/*printf("enter concentration: ");
	scanf("%d", &concentration);
	printf("enter quantity: ");
	scanf("%d", &quantity);*/
	printf("enter price: ");
	scanf("%f", &price);
	int success = addMedication(ui->control, name, concentration, quantity, price);
	return success;
}

int updateIt(Interface* ui)
{
	char name[20];
	int concentration,quantity;
	float price;
	printf("enter name of medication: ");
	scanf("%s,%d", name);
	concentration = readNumber("enter concentration\n");
	printf("enter new quantity\n");
	scanf("%d", &quantity);
	printf("enter new price\n");
	scanf("%f", &price);
	int res = update(ui->control,name, concentration, quantity, price);
	return res;

}
int removeMed(Interface* ui)
{
	char name[20];
	printf("enter name of medication\n");
	scanf("%s", name);
	int concentration=readNumber("enter concentration\n");

	int success = deleteMed(ui->control,name, concentration);
	return success;
}
void listAll(Interface* ui)
{
	Repository* repository = getRepo(ui->control);
	if (getLength(repository) == 0)
		printf("no medications\n");
	
	printRepoContent(ui->control->repo);
}
void printFiltered(Interface* ui)
{
	char needle[50];
	printf("enter string you want to filter by");
	scanf("%s", needle);
	Repository* filtered = filterByString(ui->control, needle);
	if (getRepoLength(filtered) == 0)
		printf("no match");
	else
		printRepoContent(filtered);
	freeRepository(filtered);
}

void printRepoContent(Repository* filtered)
{
	//printf("results:\n");
	for (int i = 0; i < getRepoLength(filtered); i++)
	{
		char* s2 = (char*)malloc(80 * sizeof(char));
		medicationToString(findOnPos(filtered, i), s2);
		printf("%s\n", s2);
		free(s2);

	}
}

void printByPrice(Interface* ui)
{
	int p = readNumber("enter price ");
	int v = readNumber("enter '1' for ascending, '2' for descending sort\n");
	void* o;
	if (v == 1)o = &byPrice;
	if (v == 2)o = &byPriceDescending;
	Repository* filtered = filterByPrice(ui->control, p);
	sort(filtered, o);
	if (getRepoLength(filtered) == 0)printf("no medications with price lower than %d", p);
	printRepoContent(filtered);
	freeRepository(filtered);
}


void printBySupply(Interface* ui)
{
	int x = readNumber("enter maximum supply value\n");
	int v=readNumber("enter '1' for ascending, '2' for descending sort\n");
	void* o;
	if (v == 1)o = &byQuantity;
	if (v == 2)o = &byQuantityDescending;

	Repository* filtered = filterBySupply(ui->control, x);
	sort(filtered, o);
	if (!getRepoLength(filtered))
		printf("no medications with supply less then %d", x);
	else {
		printf("medications with supply less then %d:\n", x);
		printRepoContent(filtered);
		freeRepository(filtered);
	}
}
void printByName(Interface* ui)
{
	char* name[20];
	printf("enter name\n");
	scanf("%s", name);
	Repository* filtered = filterByName(ui->control, name);
	if (getRepoLength(filtered) == 0)printf("no medications with this name\n");
	else
		printRepoContent(filtered);
	freeRepository(filtered);
}


void mainMenu(Interface* ui)
{
	while (10)
	{
		printMenu();
		int command = readNumber("enter command\n");
		while (validCommand(command) == 0)
		{
			printf("invalid command\n");
			command = readNumber("enter command\n");
		}
		if (command == 1)
		{
			int res = add(ui);
			if (res)
				printf("new medication succesfully added\n");
			else
				printf("warning!already existing medication added, quantity updated, price was not changed\n");
		}
		else if (command == 2)
		{
			int res = removeMed(ui);
			if (res)
				printf("succesfully deleted\n");
			else
				printf("medication does not exist, nothing was deleted\n");
		}
		else if (command == 3)
		{
			int res = updateIt(ui);
			if (res)
				printf("succesfully updated\n");
			else
				printf("medication name/concentration invalid, nothing was updated\n");
		}
		else if (command == 4)
		{
			printf("available medications:\n");
			listAll(ui);
		}
		else if (command == 5)
		{
			printFiltered(ui);
		}
		else if (command == 7)
		{
			printBySupply(ui);
		}
		else if (command == 8)
		{
			printByName(ui);
		}
		else if (command == 6)
			printByPrice(ui);

		else if (command == 0)
			break;

	}

}

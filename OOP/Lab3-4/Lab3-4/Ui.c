#include "UI.h"
#include <stdio.h>
#include <string.h>

UI *createUI(Controller *c)
{
	UI *ui = (UI*)malloc(sizeof(UI));
	ui->controller = c;

	return ui;
}

void destroyUI(UI *ui)
{
	destroyController(ui->controller);
	free(ui);
}


void printMenu()
{
	printf("\n\t\tThe menu:  \n");
	printf("\t1 - Add a medication;\n");
	printf("\t2 - Delete a medication;\n");
	printf("\t3 - Update a medication;\n");
	printf("\t4 - List all stock;\n");
	printf("\t5 - List all medication containing a given string;\n");
	printf("\t6 - List all medication with quantity less than a given value;\n");
	printf("\t0 - Exit.\n\n");
}

char *readName()
{
	char name[50];
	printf("Enter the medication name: ");
	scanf("%s", name);
	return name;
}

float readConcentration()
{
	float con;
	printf("Enter the concentration: ");
	scanf("%f", &con);
	return con;
}

int readQuantity()
{
	int q;
	printf("Enter the quantity: ");
	scanf("%d", &q);
	return q;
}

int readPrice()
{
	int p;
	printf("Enter the price: ");
	scanf("%d", &p);
	return p;
}

void printRepo(UI *ui)
{
	MedicationRepo *repo = getAll(ui->controller);
	int len = getRepoLength(repo);
	
	if (len == 0)
		printf("\nThe list is empty!\n");
	else
	{
		for (int i = 0; i < getRepoLength(repo); i++)
		{
			char string[200];
			toString(getElement(repo, i), string);
			printf("%s", string);
		}
	}
}

void startUI(UI *ui)
{
	int stop = 0;
	int command = -1;
	while (stop == 0)
	{
		printMenu();
		printf("\nEnter the command: ");
		scanf("%d", &command);
		if (command == 0)
		{
			stop = 1;
		}
		else if (command == 1)
		{
			char name[50];
			float con;
			int quantity, price;
			strcpy(name, readName());
			con = readConcentration();
			quantity = readQuantity();
			price = readPrice();
			addMedicine(ui->controller, name, con, quantity, price);
			printRepo(ui);
		}
		else if (command == 2)
		{
			char name[50];
			float con;
			strcpy(name, readName());
			con = readConcentration();
			deleteMedicine(ui->controller, name, con);
			printRepo(ui);
		}
		else if (command == 3)
		{
			printf("\nEnter the update informations:  \n");
			char name[50], searchName[50];
			float con, searchCon;
			int quantity, price;
			strcpy(name, readName());
			con = readConcentration();
			quantity = readQuantity();
			price = readPrice();
			printf("\nEnter the name and concentration of the medicine you want to update:  \n");
			strcpy(searchName, readName());
			searchCon = readConcentration();
			updateMedicine(ui->controller, name, con, quantity, price, searchName, searchCon);
			printRepo(ui);
		}
		else if (command == 4)
		{
			printRepo(ui);
		}
		else if (command == 5)
		{
			char subStr[30];
			printf("Search:  ");
			scanf("%s", subStr);
			if (strcmp(subStr, "*") == 0)
			{
				printRepo(ui);
			}
			else
			{
				MedicationRepo *rep = filterBySubstring(ui->controller, subStr);
				int len = getLength(rep);
				if (len == 0)
				{
					printf("There are no medicines containing the searched leters.\n");
				}
				else
				{
					printf("1 - Ascending\n");
					printf("2 - Descending\n");
					int cc;
					printf("\nEnter the command: ");
					scanf("%d", &cc);
					if (cc == 1)
					{
						sortAss(rep);
						for (int i = 0; i < len; i++)
						{
							char str[200];
							toString(getElement(rep, i), str);
							printf("%s", str);
						}
					}
					else if (cc == 2)
					{
						sortDes(rep);
						for (int i = 0; i < len; i++)
						{
							char str[200];
							toString(getElement(rep, i), str);
							printf("%s", str);
						}
					}
					else
						printf("\nInvalid command!\n");
				}
			}
		}
		else if (command == 6)
		{
			int quan;
			printf("Enter the quantity: ");
			scanf("%d", &quan);
			MedicationRepo *rep = filterByQuantity(ui->controller, quan);
			int len = getLength(rep);
			for (int i = 0; i < len; i++)
			{
				char str[200];
				toString(getElement(rep, i), str);
				printf("%s", str);
			}
		}
		else
			printf("\nInvalid command!\n");
	}
}

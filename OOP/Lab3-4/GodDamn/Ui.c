#include "UI.h"
#include <stdio.h>
#include <string.h>
#include<Windows.h>

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
	printf("\n\t\t\t\t\t\t\t\t\t\t\t\t\t\tThe menu:  \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t1 - Add a medication;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t2 - Delete a medication;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t3 - Update a medication;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t4 - List all stock;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t5 - List all medication containing a given string;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t6 - List all medication with quantity less than a given value;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t7 - Undo;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t8 - Redo;\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t0 - Exit.\n\n");
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
	printMenu();
	while (stop == 0)
	{
		printf("\nEnter the command: ");
		scanf("%d", &command);
		printf("\n");
		if (command == 0)
		{
			stop = 1;
		}
		else if (command == 1)
		{
			system("cls");
			printMenu();
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
			system("cls");
			printMenu();
			char name[50];
			float con;
			strcpy(name, readName());
			con = readConcentration();
			deleteMedicine(ui->controller, name, con);
			printRepo(ui);
		}
		else if (command == 3)
		{
			system("cls");
			printMenu();
			printf("\nEnter the name and the concentration of the medication to be updated:  \n");
			char name[50];
			float con;
			int quantity, price;
			strcpy(name, readName());
			con = readConcentration();
			printf("\nEnter the quantity and the price of the medicine you want to update:  \n");
			quantity = readQuantity();
			price = readPrice();
			updateMedicine(ui->controller, name, con, quantity, price);
			printRepo(ui);
		}
		else if (command == 4)
		{
			system("cls");
			printMenu();
			printRepo(ui);
		}
		else if (command == 5)
		{
			system("cls");
			printMenu();
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
				int len = getRepoLength(rep);

				if (len == 0)
				{
					printf("There are no medicines containing the searched leters.\n");
				}
				else
				{
					printf("\n1 - Ascending by name;\n");
					printf("2 - Descending by name;\n");
					printf("3 - Ascending by concentration;\n");
					printf("4 - Descending by concentration;\n");
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
					else if (cc == 3)
					{
						sortAssCon(rep);
						for (int i = 0; i < len; i++)
						{
							char str[200];
							toString(getElement(rep, i), str);
							printf("%s", str);
						}
					}
					else if (cc == 4)
					{
						sortDesCon(rep);
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
			system("cls");
			printMenu();
			int quan;
			printf("Enter the quantity: ");
			scanf("%d", &quan);
			MedicationRepo *rep = filterByQuantity(ui->controller, quan);
			int len = getRepoLength(rep);
			for (int i = 0; i < len; i++)
			{
				char str[200];
				toString(getElement(rep, i), str);
				printf("%s", str);
			}
		}
		else if (command == 7)
		{
			system("cls");
			printMenu();
			int res = undo(ui->controller);
			if (res == 1)
				printRepo(ui);
			else
			{
				printf("No more undo-s to make.\n");
			}
		}
		else if (command == 8)
		{
			system("cls");
			printMenu();
			int res = redo(ui->controller);
			if (res == 1)
				printRepo(ui);
			else
			{
				printf("No more redo-s to make.\n");
			}
		}
		else
		{
			system("cls");
			printMenu();
			printf("\nInvalid command!\n");
		}
	}
}

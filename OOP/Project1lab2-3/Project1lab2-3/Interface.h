#pragma once
#include "controller.h"

typedef struct
{
	Controller* control;
}Interface;
/*free memory occupied by interface*/
void destroyInterface(Interface* ui);

/*allocate memory to interface and return a pointer to it*/
Interface* createInterface(Controller* control);

/*what?*/
Repository* getRepo(Controller* control);

/*print menu of the application*/
void printMenu();

/*reads an integer number and return it, but first display a message msg
so that we know every time what are we reading exactly*/
int readNumber(const char* msg);

/*checks if a command is valid or not, and returns 0 if not, 1 if so*/
int validCommand(int command);

/*add a new medication
we invoke here the add function of controller after reading all the required fields*/
int add(Interface* ui);

/*read data, then update*/
int updateIt(Interface* ui);

/*read data, the remove*/
int removeMed(Interface* ui);
/*launch the event loop of application*/
void mainMenu(Interface* ui);
/*print out the content of a repository filtered by name */
void printFiltered(Interface* ui);
/*print out concent of repo filtered by name*/
void printByName(Interface* ui);
void printRepoContent(Repository* filtered);
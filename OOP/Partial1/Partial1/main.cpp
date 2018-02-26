#include"Ui.h"


void main()
{
	std::string list[50];
	int len;
	list[0] = "do";
	list[1] = "re";
	list[2] = "mi";
	len = 3;

	Repository r{};
	Controller c{ r };
	c.addSong("Song1", list, 3);
	list[3] = "fa";
	c.addSong("Song2", list, 4);
	list[4] = "sol";
	c.addSong("Song3", list, 5);

	Ui ui{ c };
	ui.mainMenu();
}
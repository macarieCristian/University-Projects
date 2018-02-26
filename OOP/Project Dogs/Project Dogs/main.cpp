#include "projectdogs.h"
#include <QtWidgets/QApplication>
#include <QSpinBox>
#include <QSlider>
#include <QHBoxLayout>
#include "gui.h"
#include"CSVUserList.h"
#include"HTMLUserList.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository r{ "Repo.txt" };
	r.readFromCSVFile();
	FileUserList* ful = new CSVUserList{};
	ControllerAdmin c{ r,ful };

	/*c.addAnimal("Pitbul", "Rex", 3, "https://www.google.ro/imgres?imgurl=https%3A%2F%2Fs-media-cache-ak0.pinimg.com%2F564x%2Ff2%2Fa0%2F5e%2Ff2a05edf372fc425ab3685a6e5cb0158.jpg&imgrefurl=https%3A%2F%2Fwww.pinterest.com%2Fpin%2F566609196849608983%2F&docid=QyCewTnVpWRAUM&tbnid=nZzvhRDUeMIbDM%3A&vet=1&w=500&h=711&bih=950&biw=1920&ved=0ahUKEwjW4_mukPvSAhXBuRQKHaorCIIQMwg7KAwwDA&iact=c&ictx=1");
	c.addAnimal("Pitbul", "Rexy", 4, "https://www.google.ro/imgres?imgurl=http%3A%2F%2Fcdn3-www.dogtime.com%2Fassets%2Fuploads%2Fgallery%2Fpit-bull-dog-breed-pictures%2Fpit-bull-dog-breed-picture-1.jpg&imgrefurl=http%3A%2F%2Fdogtime.com%2Fdog-breeds%2Famerican-pit-bull-terrier&docid=-N_94u2Hcu6bVM&tbnid=KL3MzSZckttR9M%3A&vet=1&w=680&h=510&bih=950&biw=1920&ved=0ahUKEwjW4_mukPvSAhXBuRQKHaorCIIQMwhVKBwwHA&iact=c&ictx=1");
	c.addAnimal("Labrador", "Lexy", 2, "https://www.google.ro/imgres?imgurl=http%3A%2F%2Fwww.thelabradorsite.com%2Fwp-content%2Fuploads%2F2011%2F12%2Fbreed-standard.jpg&imgrefurl=http%3A%2F%2Fwww.thelabradorsite.com%2Flabrador-breed-standard%2F&docid=8R0vCNpOzPfJrM&tbnid=pohq-IDa8vu_UM%3A&vet=1&w=1220&h=701&bih=950&biw=1920&ved=0ahUKEwj6s4zykPvSAhVQnRQKHYuHAd8QMwg3KAgwCA&iact=c&ictx=1");
	c.addAnimal("Rottweiler", "Baxter", 6, "https://www.google.ro/imgres?imgurl=http%3A%2F%2Fwww.elityavru.com%2Firk%2Fresim%2Frottweiler-elityavru.jpg&imgrefurl=http%3A%2F%2Fwww.elityavru.com%2Fkopek-irklari%2Frottweiler%2F58&docid=mmpX95uyRJwTsM&tbnid=kbm-Bx6zV2lnZM%3A&vet=1&w=404&h=303&bih=950&biw=1920&ved=0ahUKEwjS6v2JkfvSAhVHlxQKHcYZCyEQxiAIGSgF&iact=c&ictx=1");
	c.addAnimal("Pug", "Ozzie", 1, "https://www.google.ro/imgres?imgurl=https%3A%2F%2Fupload.wikimedia.org%2Fwikipedia%2Fcommons%2Fd%2Fd7%2FSad-pug.jpg&imgrefurl=https%3A%2F%2Fen.wikipedia.org%2Fwiki%2FPug&docid=7Wf5ySVfU5NjYM&tbnid=VMRw1Fuue8MFfM%3A&vet=1&w=2400&h=1600&bih=950&biw=1920&ved=0ahUKEwik4K2ZkfvSAhVHQBQKHXLuDygQMwgvKAAwAA&iact=c&ictx=1");
	*/





	GUI gui{c};
	gui.show();
	return a.exec();
}
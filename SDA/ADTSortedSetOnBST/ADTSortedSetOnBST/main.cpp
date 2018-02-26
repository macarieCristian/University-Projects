#include"Ui.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int cond(Element a, Element b)
{
	if (a.district < b.district)
		return 1;
	else if (a.district > b.district)
		return 2;
	else
		if (a.number < b.number)
			return 1;
		else if (a.number > b.number)
			return 2;
		else
			if (a.leters < b.leters)
				return 1;
			else if (a.leters > b.leters)
				return 2;
			else
				return 0;
}

int condNumber(Element a, Element b)
{
	if (a.number < b.number)
		return 1;
	else if (a.number > b.number)
		return 2;
	else return 0;
}

void preMain()
{
	SortedSet s{ &condNumber };
	Element e1{ "AB","10","KBV" };
	Element e2{ "CJ","19","GHY" };
	Element e3{ "CT","05","UGI" };
	Element e4{ "AB","97","AAA" };
	Element e5{ "B","12","SSL" };
	Element e6{ "B","82","CJA" };
	Element e7{ "TM","19","SPP" };
	Element e8{ "GJ","88","PRT" };
	Element e9{ "AB","82","CJA" };
	Element e10{ "AB","19","SPP" };
	Element e11{ "AB","88","PRT" };
	s.insert(e1);
	s.insert(e2);
	s.insert(e3);
	s.insert(e4);
	s.insert(e5);
	s.insert(e6);
	s.insert(e7);
	s.insert(e8);
	s.insert(e9);
	s.insert(e10);
	s.insert(e11);
	Controler c{ s };
	Ui ui{ c };
//####################################
	/*BSTNode b;
	IteratorSS it;

	e1.testElement();
	b.testElement();
	it.testIterator();
	s.testSortedSet();*/

//####################################
	ui.startApp();
	s.destroy();
}

void main()
{
	preMain();


	//system("pause");
	_CrtDumpMemoryLeaks();
}
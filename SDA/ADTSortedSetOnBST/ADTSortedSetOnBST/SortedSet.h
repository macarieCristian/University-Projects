#pragma once
#include"IteratorSS.h"


using namespace std;

class SortedSet
{
private:
	friend int condii(Element a, Element b);
	BSTNode* root;
	int len;
	//IteratorSS* it;

	int(*Relation)(Element a, Element b);

	BSTNode* getNode(Element e);
	BSTNode* leftMost(BSTNode* node);
	
public:
	SortedSet(int(*rel)(Element a1,Element a2)) : root{ NULL }, len{ 0 }/*, it{ new IteratorSS{} }*/, Relation{ rel } {}
	SortedSet(){}
	~SortedSet(){}

	IteratorSS begin();
	IteratorSS end();

	int size() { return len; }
	
	bool find(Element e);
	bool insert(Element e);
	bool erase(Element e);
	
	void destroy();

	//bool find1(Element e);

	void testSortedSet()
	{
		SortedSet s{ &condii };
		Element e1{ "1","1","1" };
		BSTNode* b1 = s.getNode(e1);
		assert(b1 == NULL);
		assert(s.find(e1) == false);
		Element e2{ "2","2","2" };
		Element e3{ "3","3","3" };
		Element e4{ "4","4","4" };
		Element e5{ "5","5","5" };
		Element e6{ "6","6","6" };
		Element e7{ "7","7","7" };
		Element e8{ "8","8","8" };
		Element e9{ "9","9","9" };
		Element e10{ "10","10","10" };
		Element e11{ "11","11","11" };
		s.insert(e4);
		BSTNode* b2 = s.getNode(e2);
		assert(b2 == NULL);
		assert(s.find(e2) == false);
		assert(s.erase(e2) == false);
		s.insert(e1);
		BSTNode* b4 = s.getNode(e5);
		assert(b4 == NULL);
		assert(s.find(e5) == false);
		s.insert(e3);
		assert(s.insert(e3) == false);
		s.insert(e2);
		s.insert(e6);
		s.insert(e5);
		s.insert(e7);
		BSTNode* b3 = s.getNode(e1);
		assert(b3->district == "1");
		assert(s.find(e1) == true);
		BSTNode* b5 = s.getNode(e6);
		assert(b5->district == "6");
		assert(s.find(e6) == true);
		s.insert(e8);
		s.insert(e9);
		s.insert(e10);
		s.insert(e11);
		BSTNode* b = s.getNode(e4);
		assert(b->district == "4");
		assert(s.find(e4) == true);
		BSTNode* a1 = s.leftMost(b);
		assert(a1->district == "1");
		int z = 0;
		for (auto it = s.begin(); it != s.end(); it++)
		{
			z++;
		}
		assert(z == 11);
		s.erase(e2);
		s.erase(e1);
		s.erase(e6);
		s.erase(e5);
		s.erase(e8);
		assert(s.size() == 6);
		s.destroy();
	}
};



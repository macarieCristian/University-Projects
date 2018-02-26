#pragma once
#include"BSTNode.h"
#include<queue>
#include<exception>

class IteratorSS
{
	IteratorSS begin(BSTNode* r);
	void inOrederQueue(BSTNode* node);
	std::queue<BSTNode*> q;
public:
	BSTNode* current;
	IteratorSS() : current{0}{}
	IteratorSS(BSTNode* root);
	~IteratorSS() {}

	
	//IteratorSS end(BSTNode* r);

	
	void next();

	Element getCurrent();

	IteratorSS& operator=(IteratorSS& it);
	bool operator!=(const IteratorSS& it);
	bool operator==(const IteratorSS& it);
	IteratorSS operator++(int);

	void testIterator()
	{
		BSTNode root{ "a","b","c",NULL,NULL,NULL };
		BSTNode b2{ "x","b","c",&root,NULL,NULL };
		BSTNode b3{ "b","b","c",&root,NULL,NULL };
		BSTNode b4{ "c","b","c",&b2,NULL,NULL };
		root.left = &b2;
		root.right = &b3;

		IteratorSS it1{ &root };
		IteratorSS it2{ &root };
		assert(it1 == it2);
		it2.next();
		assert(it1 != it2);
		std::string c = it2.getCurrent().district;
		assert(c == "a");
		int x = 0;
		for (auto itz = this->begin(&root); itz != NULL; itz++)
		{
			x++;
		}
		assert(x == 3);
		it1 = it2;
		assert(it1 == it2);
		try
		{
			IteratorSS itf = this->begin(&root);
			itf.next();
			itf.next();
			itf.next();
			itf.next();
			itf.next();
			itf.getCurrent();
			assert(false);
		}
		catch(std::exception)
		{
			assert(true);
		}
	}
};

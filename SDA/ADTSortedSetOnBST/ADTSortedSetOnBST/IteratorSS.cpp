#include "IteratorSS.h"

using namespace std;

IteratorSS::IteratorSS(BSTNode * root)
{
	inOrederQueue(root);
	q.push(NULL);
	current = q.front();
	q.pop();
}

IteratorSS IteratorSS::begin(BSTNode* r)
{
	IteratorSS it{ r };
	return it;
}

//IteratorSS IteratorSS::end(BSTNode * r)
//{
//	IteratorSS it{ r };
//	while (it.q.size() != 0)
//		it.next();
//	return it;
//}

void IteratorSS::inOrederQueue(BSTNode * node)
{
	if (node == NULL)
		return;
	inOrederQueue(node->left);
	this->q.push(node);
	inOrederQueue(node->right);
}

void IteratorSS::next()
{
	current = q.front();
	if (current == NULL)
		return;
	q.pop();

}

Element IteratorSS::getCurrent()
{
	if (current == NULL)
		throw exception("\nOut of range!\n");
	Element e{ current->district,current->number,current->leters };
	return e;
	
}

IteratorSS & IteratorSS::operator=(IteratorSS & it)
{
	current = it.current;
	q = it.q;
	return *this;
}

bool IteratorSS::operator!=(const IteratorSS & it)
{
	return current != it.current;
}

bool IteratorSS::operator==(const IteratorSS & it)
{
	return current == it.current;
}

IteratorSS IteratorSS::operator++(int)
{
	this->next();
	return *this;
}

#include "SortedSet.h"

BSTNode * SortedSet::getNode(Element e)
{
	if (len == 0)
		return NULL;
	if (Relation(*root, e) == 0)
		return root;
	BSTNode* aux = root;
	while (aux != NULL)
	{
		if (Relation(e, *aux)==1)// e1<e2
		{
			aux = aux->left;
			if (aux == NULL)
				return NULL;
		}
		else if (Relation(e, *aux)==2)
		{
			aux = aux->right;
			if (aux == NULL)
				return NULL;
		}
		if (Relation(*aux, e) == 0)
		{
			return aux;
		}
	}
	return NULL;
}

BSTNode * SortedSet::leftMost(BSTNode * node)
{
	while (node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

IteratorSS SortedSet::begin()
{
	IteratorSS it{ root };
	return it;
}

IteratorSS SortedSet::end()
{
	IteratorSS it{ root };
	while (it != NULL)
		it++;
	return it;
}

//bool SortedSet::find1(Element e)
//{
//	IteratorSS* it = new IteratorSS{};
//	for (*it = this->begin(); *it != this->end(); it->next())
//	{
//		if (it->getCurrent() == e)
//			return true;
//	}
//	return false;
//}

bool SortedSet::find(Element e)
{
	if (len == 0)
		return false;
	if (Relation(*root,e)==0)
		return true;
	BSTNode* aux = root;
	while (aux != NULL)
	{
		if (Relation(e, *aux) == 1)// e1<e2
		{
			aux = aux->left;
			if (aux == NULL)
				return false;
		}
		else if (Relation(e, *aux) == 2)
		{
			aux = aux->right;
			if (aux == NULL)
				return false;
		}
		if (Relation(*aux, e) == 0)
		{
			return true;
		}
	}
	return false;
	
}

bool SortedSet::insert(Element e)
{
	if (find(e))
		return false;

	BSTNode* node = root;
	if (node == NULL)
	{
		root = new BSTNode{ e.district,e.number,e.leters,NULL,NULL,NULL };
		len++;
		return true;
	}
	else
	{
		while (node != NULL)
		{
			if (Relation(e, *node) == 1)
			{
				if (node->left == NULL)
				{
					node->left = new BSTNode{ e.district,e.number,e.leters,node,NULL,NULL };
					len++;
					return true;
				}
				else
				{
					node = node->left;
				}
			}
			else if (Relation(e, *node) == 2)
			{
				if (node->right == NULL)
				{
					node->right = new BSTNode{ e.district,e.number,e.leters,node,NULL,NULL };
					len++;
					return true;
				}
				else
				{
					node = node->right;
				}
			}
		}
		return false;
	}



}

bool SortedSet::erase(Element e)
{
	BSTNode* z = getNode(e);
	if (z == NULL)
		return false;

	BSTNode *x, *y, *q;
	if (z->left != NULL && z->right != NULL)
	{
		y = leftMost(z->right);
	}
	else
	{
		y = z;
	}
	if (y->left != NULL)
	{
		x = y->left;
	}
	else
	{
		x = y->right;
	}
	q = y->parent;
	if (y != z)
	{
		z->district = y->district;
		z->number = y->number;
		z->leters = y->leters;
	}
	if (x != NULL)
	{
		x->parent = q;
	}
	if (q != NULL)
	{
		if (q->left == y)
			q->left = x;
		else
			q->right = x;
	}
	else
	{
		root = x;
	}
	len--;
	return true;

}

void SortedSet::destroy()
{
	IteratorSS it1 = begin();
	IteratorSS it2;
	while (it1 != NULL)
	{
		it2 = it1;
		delete(it1.current);
		it1 = it2;
		it1++;
	}
	root = NULL;
	len = 0;
	//delete(this->it);
}

int condii(Element a, Element b)
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

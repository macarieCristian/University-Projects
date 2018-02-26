#pragma once
#include"Element.h"



class BSTNode : public Element
{
public:
	BSTNode* parent;
	BSTNode* left;
	BSTNode* right;

	BSTNode() : Element{ "","","" }, parent { 0 }, left{ 0 }, right{ 0 } {}
	~BSTNode(){}

	BSTNode(std::string dis, std::string num, std::string let, BSTNode* par, BSTNode* l, BSTNode* r) :Element{dis,num,let}, parent{ par }, left{ l }, right{ r } {}

	//copy constructor

	BSTNode(const BSTNode& node)
	{
		this->district = node.district;
		this->number = node.number;
		this->leters = node.leters;
		this->parent = node.parent;
		this->left = node.left;
		this->right = node.right;
	}

	BSTNode& operator=(const BSTNode& node)
	{
		this->district = node.district;
		this->number = node.number;
		this->leters = node.leters;
		this->parent = node.parent;
		this->left = node.left;
		this->right = node.right;
		return *this;
	}

	bool operator==(const BSTNode& b)
	{
		return (district == b.district && number == b.number && leters == b.leters && parent == b.parent && left == b.left && right == b.right);
	}

	void testNode()
	{
		BSTNode bn{};
		BSTNode b{ "a","b","c",&bn,NULL,NULL };
		bn = b;
		assert(bn.district == "a");
		assert(bn == b);
		assert(b.parent == &bn);
		assert(b.left == NULL);
		assert(b.right == NULL);
	}
};




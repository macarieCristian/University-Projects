#pragma once
#include<string>
#include<assert.h>



class Element
{
public:
	std::string district;
	std::string number;
	std::string leters;


	Element(std::string dis, std::string num, std::string let) : district{dis},number{num},leters{let}{}
	Element(){}
	~Element(){}

	bool operator==(Element& e)
	{
		return (district == e.district && number == e.number && leters == e.leters);
	}

	std::string toString()
	{
		return district + " " + number + " " + leters + "\n";
	}

	std::string toStringN()
	{
		return district + " " + number + " " + leters;
	}

	void testElement()
	{
		Element e{ "d","n","das" };
		Element e1{};
		assert((e == e1) == 0);
		assert(e.toString().size() != 0);
		assert(e.toStringN().size() != 0);
	}

};


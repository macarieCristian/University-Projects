#pragma once
#include<vector>
#include<algorithm>

class Observer
{
public:
	Observer() {}
	virtual ~Observer() {}
	virtual void update() = 0;

};


class Observable
{
private:
	std::vector<Observer*> observers;
public:
	virtual ~Observable() {}

	void addObserver(Observer* o)
	{
		observers.push_back(o);
	}

	void removeObserver(Observer* o)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), o));
	}

	void notify()
	{
		for (Observer* o : observers)
			o->update();
	}

};


#pragma once
#include<vector>
#include<algorithm>

class Observer
{
public:
	Observer(){}
	virtual ~Observer(){}
	virtual void update() = 0;
};

class Observable
{
private:
	std::vector<Observer*> observers;
public:
	void addObserver(Observer* obs)
	{
		observers.push_back(obs);
	}

	void removeObeserver(Observer* obs)
	{
		observers.erase(std::remove(observers.begin(), observers.end(), obs));
	}

	void notify()
	{
		for (Observer* obs : observers)
		{
			obs->update();
		}
	}
};
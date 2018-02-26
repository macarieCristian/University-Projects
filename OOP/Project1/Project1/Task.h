#pragma once
#include<string>



class Task
{
private:
	std::string description;
	int duration;
	int priority;
public:
	Task::Task() : description(""), duration(NULL), priority(NULL) {}
	Task::Task(const std::string& description1, int duration1, int priority1) : description(description1), duration(duration1), priority(priority1) {}

	
	std::string Task::getDescription() { return description; }
	int Task::getDuration() { return duration; }
	int Task::getPriority() { return priority; }

	void Task::setDescription(std::string value) { this->description = value; }
	void Task::setDuration(int value) { this->duration = value; }
	void Task::setPriority(int value) { this->priority = value; }

	std::string Task::toString();
};




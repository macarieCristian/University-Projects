#pragma once
#include<exception>
#include<string>

class RepoExceptions : public std::exception
{
protected:
	std::string mesage;

public:
	RepoExceptions() : exception{},mesage{""}{}
	RepoExceptions(const std::string &msg) : mesage(msg){}
	virtual ~RepoExceptions(){}
	virtual const char* what();
};


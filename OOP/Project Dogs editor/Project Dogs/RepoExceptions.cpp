#include "RepoExceptions.h"

const char * RepoExceptions::what()
{
	return this->mesage.c_str();
}

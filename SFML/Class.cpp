#include "Class.h"

std::string Class::getClassID()
{
	return classID;
}

std::string Class::getClassName()
{
	return className;
}

void Class::setClassID(std::string classID)
{
	this->classID = classID;
}

void Class::setClassName(std::string className)
{
	this->className = className;
}

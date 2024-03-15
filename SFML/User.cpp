#include "User.h"

void User::setUrl(std::string url)
{
	this->url = url;
}

void User::setUsername(std::string username)
{
	this->username = username;
}

void User::setPassword(std::string password)
{
	this->password = password;
}

std::string User::getUrl()
{
	return url;
}

std::string User::getUsername()
{
	return username;
}

std::string User::getPassword()
{
	return password;
}

std::string User::getType()
{
	return type;
}

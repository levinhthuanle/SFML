#pragma once
#include "Requirement.h"
class User
{
//private:
public:
	std::string username;
	std::string password;
	std::string type; // Student and Staff
	std::string url;
	std::string fullname;
	std::string id;
	std::string courseName;
	std::string className;

	User(){}

	User(std::string username, std::string password, std::string url) {
		this->username = username;
		this->password = password;
		this->url = url;
	}

	void setUrl(std::string url);

	void setUsername(std::string username);

	void setPassword(std::string password);

	void setType(std::string type) {
		this->type = type;
	}

	std::string getUrl();

	std::string getUsername();

	std::string getPassword();

	std::string getType();

	~User() {
		username = "";
		password = "";
		type = "";
		url = "";
		fullname = "";
		id = "";
		courseName = "";
		className = "";
	}
};

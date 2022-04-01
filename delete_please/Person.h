#pragma once
#include <string>
class Person
{
private:
	std::string name;
	std::string secondname;
	std::string patronymic;
public:
	Person();
	Person(const Person&);
	const std::string& getName() const { return name; }
	const std::string& getSecondname() const { return secondname; }
	const std::string& getPatronymic() const { return patronymic; }
	void setname(const std::string&);
	void secondname(const std::string&);
	void patronymic(const std::string&);
};


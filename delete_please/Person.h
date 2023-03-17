#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <string>
#include <iostream>    
#include "EStackException.h"
#include "EStackEmpty.h"
using namespace std;
class Person
{
private:
	std::string name;
	std::string secondname;
	std::string patronymic;
public:
	Person();
	Person(string last_name, string first_name, string patronymic);
	Person(string);
	//Person(const Person&);
	const std::string& getName() const { return name; }
	const std::string& getSecondname() const { return secondname; }
	const std::string& getPatronymic() const { return patronymic; }
	void Setname(const std::string& n) { name = n; }
	void Setsecondname(const std::string& s) {  secondname=s; }
	void Setpatronymic(const std::string& p) {  patronymic=p; }

};


#pragma once
#include "tmp_stack.h"
#include "Person.h"
#define _CRT_SECURE_NO_WARNINGS 
class PersonKeeper
{
	
public:
	static PersonKeeper &GetInstance();
	void ReadPersons(std::fstream & stream);
	void WritePersons();
private:
	tmp_stack <Person> mas;
};


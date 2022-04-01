#include "PersonKeeper.h"
#include <iostream>     
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS 

PersonKeeper &PersonKeeper::GetInstance()
{
	static PersonKeeper instance;
	return instance;
}

void PersonKeeper::ReadPersons(std::fstream& stream)
{
    if(!stream.is_open())
    { 
     
    }
    tmp_stack<Person> stack;
    std::string name[3];
    for (int i=0;i<3;i++) 
    {
        try 
        {
            stream >>name[i] ;
        }
        return stack;
    }
}
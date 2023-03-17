#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "PersonKeeper.h"
#include "EStackException.h"
#include "EStackEmpty.h"
#include <fstream>
#include <iostream>    
using namespace std;
class Check_File
{
private:
    PersonKeeper& person_keeper_;
public:
    Check_File();
    void GetInfo();

};


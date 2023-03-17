#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "EStackException.h"
#include "EStackEmpty.h"
#include "tmp_stack.h"
#include "PersonKeeper.h"
#include <string>
#include "Check_File.h"
using namespace std;
int main()
{
    
    try
    {
        Check_File s;
        s.GetInfo();             
        //обработка исключения Стек пуст-попытка извлечь член-данное
    }
    catch (const EStackException & e)
    {  
        cout << e.what();
    }
    catch (const char* str)
    {          //обработка исключения не выделена память под стек
        cout <<"Error:"<<str;
    }
}


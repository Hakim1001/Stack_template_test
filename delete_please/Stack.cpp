#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "EStackException.h"
#include "EStackEmpty.h"
#include "tmp_stack.h"
using namespace std;
int main()
{
    try {
        tmp_stack<const char*> s;
        s.push("Exception");
        cout << s.pop();
        cout << s.pop();                 //обработка исключения Стек пуст-попытка извлечь член-данное
    }
    catch (const EStackException & e) {  
        cout << e.what();
    }
    catch (const EStackEmpty & e) {          //обработка исключения не выделена память под стек
        cout << e.what();
    }
}


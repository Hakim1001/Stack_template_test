#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include "EStackException.h"
#include "EStackEmpty.h"
#include "tmp_stack.h"
using namespace std;
int main()
{
	tmp_stack<const char*> s;
	s.push("Exception") ;
	cout<<s.pop();
	cout <<s.pop();
}


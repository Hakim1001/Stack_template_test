#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include <cstring>
#include <iostream>
using namespace std;
class EStackException
{
public:
	EStackException(const char* mesg)
	{
		mesg_ = new char[strlen(mesg) + 1];

		strcpy(mesg_, mesg);   // сохранение сообщения об ошибке
		cout << what();
	}
	EStackException(const EStackException& obj)
	{
		mesg_ = new char[strlen(obj.mesg_) + 1];

		strcpy(mesg_, obj.mesg_);                                          // копируем сообщение об ошибке
	}
	~EStackException()
	{
		cout << "lol";
		delete[] mesg_;
	}
	const char* what() const
	{ 
		return mesg_;
 }
private:
	char* mesg_;
};



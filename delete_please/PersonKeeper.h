#pragma once
#include "tmp_stack.h"
#include "Person.h"
#define _CRT_SECURE_NO_WARNINGS 
class PersonKeeper
{
	
public:
	static PersonKeeper &GetInstance();                        // статическая функция в которой создается экземпляр
	void ReadPersons(string);                            // записать ФИО из стека в файл
	void WritePersons(string);                                 // считать ФИО из файла в стек
	int Size();                                                // количество хранимых личностей
	void Clear();
private:
	PersonKeeper();                                            // конструкторы и оператор присвоения недоступны из вне, то есть класс можно создать только через Instance
	PersonKeeper(const PersonKeeper&);                         // оставляем конструктор копирования по умолчанию, т. к. все член данные можно скопировать простым присвоением
	~PersonKeeper();
	PersonKeeper& operator=(const PersonKeeper&);
	tmp_stack <Person> mas;                                    //Стек имен
	
};


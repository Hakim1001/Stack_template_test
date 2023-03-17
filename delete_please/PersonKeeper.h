#pragma once
#include "tmp_stack.h"
#include "Person.h"
#define _CRT_SECURE_NO_WARNINGS 
class PersonKeeper
{
	
public:
	static PersonKeeper &GetInstance();                        // ����������� ������� � ������� ��������� ���������
	void ReadPersons(string);                            // �������� ��� �� ����� � ����
	void WritePersons(string);                                 // ������� ��� �� ����� � ����
	int Size();                                                // ���������� �������� ���������
	void Clear();
private:
	PersonKeeper();                                            // ������������ � �������� ���������� ���������� �� ���, �� ���� ����� ����� ������� ������ ����� Instance
	PersonKeeper(const PersonKeeper&);                         // ��������� ����������� ����������� �� ���������, �. �. ��� ���� ������ ����� ����������� ������� �����������
	~PersonKeeper();
	PersonKeeper& operator=(const PersonKeeper&);
	tmp_stack <Person> mas;                                    //���� ����
	
};


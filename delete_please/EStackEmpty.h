#pragma once
#define _CRT_SECURE_NO_WARNINGS 
#include "EStackException.h"
#include <iostream>
using namespace std;
class EStackEmpty : public EStackException
{
public:
 EStackEmpty() : EStackException("A stack is empty.")            //������������� �������� ������ � ���������� �� ������
	{
	}
 EStackEmpty(const EStackEmpty& obj): EStackException(obj)        // �������������� ������� ����� ���������� ��������
 {

 }
 ~EStackEmpty() 
 {
 }
};
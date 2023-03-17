#include "Person.h"
Person::Person(std::string Fullname)
{
	string qs = Fullname;
	string *fullname = new string[100];
	size_t position = 0;
	int index = 0;

	while ((position = qs.find(' ')) != std::string::npos)   //���������� �� ������ �� ������������ ������� ������ � ������ array ��������
	{
		std::string token = qs.substr(0, position);          //  ��������� ���������� ������ �� �� ������ �����

		if (position!=0)
		{

		fullname[index] = token;
		index += 1;
	    }

		qs.erase(0, position + 1);
		
	}

	fullname[index] = qs;


	if (index != 2 && index != 3) // ���� � ������ ������������, ��� ������� ����� ����, �� ��� ������ ��� ������� ������ � �������� �������
	{
		throw "Error: Person(): A string has incorrect format and could not be completely parsed."; // ��������������� �� ���� ����� ������������ ������������
	}
	secondname = fullname[0]; // ���������� ������ ����� � ������ � �������� �������
	name = fullname[1]; // ������ � �������� �����

	if (index == 2) // ���� ���� 3-� �����, ���������� ��� � �������� ��������
	{
		patronymic = fullname[2];
	}
	delete[] fullname;

}
Person::Person()
{

}
Person::Person(string last_name, string first_name, string patronymic)
	: secondname(last_name)
	, name(first_name)
	, patronymic(patronymic)
{

}
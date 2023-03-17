#include "PersonKeeper.h"
#include <iostream>     
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS 
PersonKeeper::PersonKeeper()
{

}

PersonKeeper::~PersonKeeper()
{
    // ��� ����������� ��������� ��������
}


PersonKeeper &PersonKeeper::GetInstance()
{
	static PersonKeeper instance;                                 // static, ��� ���� ����� ������ �� ���������� ������ ��� ��� ������ �������
	return instance;
}

void PersonKeeper::ReadPersons(string path)
{
    std::fstream fs;                                               // ����� ��� ������-������
    fs.open(path);                                                 // �������� �� ������ 

    if(!fs.is_open())
    { 
        throw "Error: file is not open";
    }	
    string str;
    while (getline(fs, str))
    {

        mas.push(str);
       
    }
  //  cout << "s";
        fs.close();
    
}
void  PersonKeeper::WritePersons(string path)
{
    std::ofstream ofs;
    ofs.open(path);

    if (!ofs.is_open())
    {
        throw "Error: writePersons(): Couldn't open a file!";
    }
 



    mas.ForEach([&](const Person& value) // ���������� ��� ��������, ����������� � ���������
        {

            ofs << value.getSecondname() << '\t' << value.getName() << '\t' << value.getPatronymic() << endl; // ���������� �������� � ���� ���������
        });

   ofs.close(); // ��������� ����

}
int PersonKeeper::Size()
{
    return mas.Count();
}

void PersonKeeper::Clear()
{
    mas.Clear();
}
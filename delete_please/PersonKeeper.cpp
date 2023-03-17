#include "PersonKeeper.h"
#include <iostream>     
#include <fstream>
#define _CRT_SECURE_NO_WARNINGS 
PersonKeeper::PersonKeeper()
{

}

PersonKeeper::~PersonKeeper()
{
    // нет динамически созданных обьектов
}


PersonKeeper &PersonKeeper::GetInstance()
{
	static PersonKeeper instance;                                 // static, для того чтобы обьект не создавался каждый раз при вызове функции
	return instance;
}

void PersonKeeper::ReadPersons(string path)
{
    std::fstream fs;                                               // поток для чтения-записи
    fs.open(path);                                                 // открытие на чтение 

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
 



    mas.ForEach([&](const Person& value) // перебираем все значения, находящиеся в хранителе
        {

            ofs << value.getSecondname() << '\t' << value.getName() << '\t' << value.getPatronymic() << endl; // записываем значения в файл построчно
        });

   ofs.close(); // закрываем файл

}
int PersonKeeper::Size()
{
    return mas.Count();
}

void PersonKeeper::Clear()
{
    mas.Clear();
}
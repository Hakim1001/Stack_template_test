#include "Person.h"
Person::Person(std::string Fullname)
{
	string qs = Fullname;
	string *fullname = new string[100];
	size_t position = 0;
	int index = 0;

	while ((position = qs.find(' ')) != std::string::npos)   //Проходимся по строке до определенных симвлов занося в массив array значения
	{
		std::string token = qs.substr(0, position);          //  разбиваем полученную строку на не пустые слова

		if (position!=0)
		{

		fullname[index] = token;
		index += 1;
	    }

		qs.erase(0, position + 1);
		
	}

	fullname[index] = qs;


	if (index != 2 && index != 3) // если в строке недостаточно, или слишком много слов, то это значит что входные данные в неверном формате
	{
		throw "Error: Person(): A string has incorrect format and could not be completely parsed."; // сответствтвенно об этом нужно предупредить пользователя
	}
	secondname = fullname[0]; // используем первое слово в строке в качестве фамилии
	name = fullname[1]; // второе в качестве имени

	if (index == 2) // если есть 3-е слово, используем его в качестве отчества
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
#include "Check_File.h"
using namespace std;

Check_File::Check_File(): person_keeper_(PersonKeeper::GetInstance())
{

}
void Check_File::GetInfo()
{

		string path = "C:/Users/Hakim/Documents/Stack_repo/test.txt";              //Задаем для примера 
		ofstream ofs;
		ofs.open(path);
		//ofs << "Vortan Vora Vortanovjch" << '\n' << "Tora Bora Hortanovjch" << '\n' << "Gora Mora Sortanovjch"; //3  строки с полными именами 
		//ofs << "Vortan Vora " << '\n' << "Tora Bora " << '\n' << "Gora Mora Sortanovjch";                     //2  строки с неполными именами 
		//ofs << "Vortan " << '\n' << "Tora Bora " << '\n' << "Gora Mora Sortanovjch";                            //1 сторока только с именем
		//ofs << "Vortan Vora Ora Mora " << '\n' << "Tora Bora " << '\n' << "Gora Mora Sortanovjch";                //1 строка с неправильным именем
		ofs << "Vortan    Vora Ora" << '\n' << "Tora    Bora " << '\n' << "Gora Mora Sortanovjch";
		ofs.close();
		string path2 = "C:/Users/Hakim/Documents/Stack_repo/test2.txt";
		
		person_keeper_.Clear();
		person_keeper_.ReadPersons(path);                                    // считываем имена личностей из файла в хранилище личностей
		person_keeper_.WritePersons(path2);

}
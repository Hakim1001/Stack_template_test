#include "Check_File.h"
using namespace std;

Check_File::Check_File(): person_keeper_(PersonKeeper::GetInstance())
{

}
void Check_File::GetInfo()
{

		string path = "C:/Users/Hakim/Documents/Stack_repo/test.txt";              //������ ��� ������� 
		ofstream ofs;
		ofs.open(path);
		//ofs << "Vortan Vora Vortanovjch" << '\n' << "Tora Bora Hortanovjch" << '\n' << "Gora Mora Sortanovjch"; //3  ������ � ������� ������� 
		//ofs << "Vortan Vora " << '\n' << "Tora Bora " << '\n' << "Gora Mora Sortanovjch";                     //2  ������ � ��������� ������� 
		//ofs << "Vortan " << '\n' << "Tora Bora " << '\n' << "Gora Mora Sortanovjch";                            //1 ������� ������ � ������
		//ofs << "Vortan Vora Ora Mora " << '\n' << "Tora Bora " << '\n' << "Gora Mora Sortanovjch";                //1 ������ � ������������ ������
		ofs << "Vortan    Vora Ora" << '\n' << "Tora    Bora " << '\n' << "Gora Mora Sortanovjch";
		ofs.close();
		string path2 = "C:/Users/Hakim/Documents/Stack_repo/test2.txt";
		
		person_keeper_.Clear();
		person_keeper_.ReadPersons(path);                                    // ��������� ����� ��������� �� ����� � ��������� ���������
		person_keeper_.WritePersons(path2);

}
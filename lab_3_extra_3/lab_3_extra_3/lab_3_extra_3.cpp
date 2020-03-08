#include <iostream>
#include <vector>    
#include <algorithm>
#include <string>
#include <ctype.h>

# define str_len 256 
# define size 100  

using namespace std;
void enter_new();
void out();
void search();
struct Sanat
{
	char nameSanat[str_len];
	char location[str_len];
	char treatment_profile[str_len];
	int number_of_trips;
};

struct Sanat  type_of_sanat[size];
struct Sanat all;

int current_size = 0;
int choice;

int main()
{
	setlocale(LC_CTYPE, "Russian");


	do
	{
		cout << "Введите:" << endl;
		cout << "1-для ввода записи" << endl;
		cout << "2-для вывода записи" << endl;
		cout << "3-для поиска" << endl;
		cout << "4-для выхода" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();	break;
		}
	} while (choice != 4);
}
void enter_new()
{
	cout << "Ввод информации" << endl;
	if (current_size < size)
	{
		cout << "Строка номер ";
		cout << current_size + 1;
		cout << endl << "Название санатория: ";
		cin >> type_of_sanat[current_size].nameSanat;
		cout << "Место расположения: ";
		cin >> type_of_sanat[current_size].location;
		cout << "Лечебный профиль: ";
		cin >> type_of_sanat[current_size].treatment_profile;
		cout << "Количество путевок: ";
		cin >> type_of_sanat[current_size].number_of_trips;
		current_size++;
	}
	else
		cout << "Введено максимальное кол-во строк";

}
void out()
{
	for (int i = 0; i < current_size; i++)
	{
		for (int j = i + 1; j < current_size; j++)
		{
			if (strcmp(type_of_sanat[i].nameSanat, type_of_sanat[j].nameSanat) > 0)
			{
				Sanat tmp = type_of_sanat[i];
				type_of_sanat[i] = type_of_sanat[j];
				type_of_sanat[j] = tmp;
			}
		}
	}
	int sw, n;
	cout << "1-вывод 1 строки" << endl;
	cout << "2-вывод всех строк" << endl;
	cin >> sw;

	if (sw == 1)
	{
		cout << "Номер выводимой строки: " << endl;
		cin >> n;
		cout << endl;
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "|" << "Название санатория" << "|";
		cout << "Месторасположения" << "|";
		cout << "Лечебный профиль" << "|";
		cout << "Количество путевок" << "|" << "\n";
		cout << "---------------------------------------------------------------------------" << "\n";
		cout << "|" << "    " << type_of_sanat[n - 1].nameSanat << "           " << "|";
		cout << "  " << type_of_sanat[n - 1].location << "           " << "|";
		cout << " " << type_of_sanat[n - 1].treatment_profile << "            " << "|";
		cout << " " << type_of_sanat[n - 1].number_of_trips << "            " << "|" << endl;;
		cout << "----------------------------------------------------------------------------";
	}
	if (sw == 2)                                                                                           //Blood-лечебный профиль кровеносной системы
																											//Air-Лечебный профиль легких и других воздушнокапельных путей
	{                                                                                                        //Stomach-лечебный профиль пищеварительной системы
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "                        " << "Лечебный профиль:заболевания крови" << "\n";
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "|" << "Название санатория" << "|";
		cout << "Месторасположения" << "|";
		cout << "Лечебный профиль" << "|";
		cout << "Количество путевок" << "|" << "\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strlen(type_of_sanat[i].treatment_profile) == 5)
			{
				cout << "|" << "    " << type_of_sanat[i].nameSanat << "           " << "|";
				cout << "  " << type_of_sanat[i].location << "          " << "|";
				cout << " " << type_of_sanat[i].treatment_profile << "         " << "|";
				cout << " " << type_of_sanat[i].number_of_trips << "            " << "|" << "\n";
				cout << "-------------------------------------------------------------------------";
				cout << "\n\n";
			}
		}
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "                        " << "Лечебный профиль:воздушнокапельных путей" << "\n";
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "|" << "Название санатория" << "|";
		cout << "Месторасположения" << "|";
		cout << "Лечебный профиль" << "|";
		cout << "Количество путевок" << "|" << "\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strlen(type_of_sanat[i].treatment_profile) == 3)
			{
				cout << "|" << "    " << type_of_sanat[i].nameSanat << "           " << "|";
				cout << "  " << type_of_sanat[i].location << "          " << "|";
				cout << " " << type_of_sanat[i].treatment_profile << "         " << "|";
				cout << " " << type_of_sanat[i].number_of_trips << "            " << "|" << "\n";
				cout << "-------------------------------------------------------------------------";
				cout << "\n\n";
			}
		}
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "                        " << "Лечебный профиль:пищеварительной системы" << "\n";
		cout << "--------------------------------------------------------------------------" << "\n";
		cout << "|" << "Название санатория" << "|";
		cout << "Месторасположения" << "|";
		cout << "Лечебный профиль" << "|";
		cout << "Количество путевок" << "|" << "\n";
		for (int i = 0; i < current_size; i++)
		{
			if (strlen(type_of_sanat[i].treatment_profile) == 7)
			{

				cout << "|" << "    " << type_of_sanat[i].nameSanat << "           " << "|";
				cout << "  " << type_of_sanat[i].location << "          " << "|";
				cout << " " << type_of_sanat[i].treatment_profile << "         " << "|";
				cout << " " << type_of_sanat[i].number_of_trips << "            " << "|" << "\n";
				cout << "-------------------------------------------------------------------------";
				cout << "\n";
			}
		}
	}
	cout << "\n";
}
void search()
{
	char number[16];
	cout << "Введите название санатория:" << "\n";
	cin >> number;
	for (int z = 0; z < current_size; z++)
	{
		if (strcmp(number, type_of_sanat[z].nameSanat) == 0)
		{
			cout << "Название санатория: " << type_of_sanat[z].nameSanat << endl;
			cout << "Место расположения: " << type_of_sanat[z].location << endl;
			cout << "Лечебный профиль: " << type_of_sanat[z].treatment_profile << endl;
			cout << "Количество путевок: " << type_of_sanat[z].number_of_trips << endl;
		}
	}
}
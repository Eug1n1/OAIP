#include <iostream>
#include <string>


using namespace std;

void enter_new();
void out();
void search();

union Utypes
{
    char str[50];
    int num;
};

//int main(void)
//{
//    setlocale(LC_ALL, "ru");
//    int size;
//    cout << "Давайте введем информацию про университеты\n";
//    cout << "Количество университетов: "; cin >> size;
//    for (int i = 0; i < size; i++){
//        int k;
//        cout << "\nНазвание: "; cin >> info.name;
//        cout << "Адрес: "; cin >> info.ad;
//        cout << "Количество специальностей: "; cin >> k;
//        cout << "Введите размер оплаты при договорном обучении: "; cin >> info.sum;
//        cout << "Введите название специальности и конкурс прошлого года по ней\n";
//        for (int j = 0; j < k; j++){
//            cout << (j + 1) << ". "; cin >> info.spec[j]; cin >> info.ball[j];
//        }
//       
//        int min = info.ball[0];
//        for (int j = 0; j < k; j++)
//            if (info.ball[j] < min)
//                min = info.ball[j];
//        cout << "Минимальный балл по университу: " << min;
//        
//    }
//}

struct Uni
{
	Utypes name;
	Utypes adrs;
	Utypes num;
	Utypes specs[10];
	Utypes points[10];
	Utypes sum;
	int min;

	void min_points() {
		min = this->points[0].num;
			for (int j = 0; j < this->num.num; j++)
				if (this->points[j].num < min)
					min = this->points[j].num;
	}
};

Uni list[100];
int ListSize = 0;
int choice;

int main()
{
	while (true){
		cout << "\t\t\tMAIN MENU" << endl;
		cout << "\t\t1 - to enter new" << endl;
		cout << "\t\t2 - to output" << endl;
		cout << "\t\t3 - to search" << endl;
		cout << "\t\t4 - to exit" << endl;
		cout << "\t\tChoice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:  enter_new();	break;
		case 2:  out();  break;
		case 3:  search();  break;
		case 4:  exit(0);	break;
		}
	} 
}

void enter_new() {
	string buff;

	cout << "\nTitle: ";
	cin >> list[ListSize].name.str;
	cout << "Adress: ";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	getline(cin, buff);
	strcpy_s(list[ListSize].adrs.str, buff.c_str());
	cout << "Cost: ";
	cin >> list[ListSize].sum.num;
	cout << "Amount of specs: ";
	cin >> list[ListSize].num.num;
	cout << "Enter title then points\n";
	for (int j = 0; j < list[ListSize].num.num; j++){
		cout << (j + 1) << ". ";
		cin >> list[ListSize].specs[j].str;
		cin >> list[ListSize].points[j].num;
	}
	ListSize++;
}

void out() {
	for (int i = 0; i < ListSize; i++) {
		printf("\n\nTitle: %s\nAdress: %s\nCost: %d\n", list[i].name.str, list[i].adrs.str, list[i].sum.num);
		for (int j = 0; j < list[i].num.num; j++){
			printf("%d. %s: %d\n", j + 1, list[i].specs[j].str, list[i].points[j].num);
		}
	}
}

void search() {
	char choice[50];
	cin >> choice;

	for (int i = 0; i < ListSize; i++) 
		if (strcmp(list[i].name.str, choice) == 0) {
			printf("\n\nTitle: %s\nAdress: %s\nCost: %d\n", list[i].name.str, list[i].adrs.str, list[i].sum.num);
			for (int j = 0; j < list[i].num.num; j++) {
				printf("%d. %s: %d\n", j + 1, list[i].specs[j].str, list[i].points[j].num);
			}
		}	
}
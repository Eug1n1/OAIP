#include <clocale>
#include <iostream>

using namespace std;

union Utypes
{
    char name[50];
    char ad[50];
    char spec[20][10];
    int ball[10];
    int sum;
} info;

int main(void)
{
    setlocale(LC_ALL, "ru");
    int size;
    cout << "Давайте введем информацию про университеты\n";
    cout << "Количество университетов: "; cin >> size;
    for (int i = 0; i < size; i++){
        int k;
        cout << "\nНазвание: "; cin >> info.name;
        cout << "Адрес: "; cin >> info.ad;
        cout << "Количество специальностей: "; cin >> k;
        cout << "Введите размер оплаты при договорном обучении: "; cin >> info.sum;
        cout << "Введите название специальности и конкурс прошлого года по ней\n";
        for (int j = 0; j < k; j++){
            cout << (j + 1) << ". "; cin >> info.spec[j]; cin >> info.ball[j];
        }
       
        int min = info.ball[0];
        for (int j = 0; j < k; j++)
            if (info.ball[j] < min)
                min = info.ball[j];
        cout << "Минимальный балл по университу: " << min;
        
    }
}

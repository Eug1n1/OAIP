#include <iostream>
#include <fstream>

using namespace std;

struct list
{
    int number;
    list* next;
};

void insertEl(list*& p, int value) {
    list* newP = new list;
    if (newP != NULL)
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

void printList(list* p) {
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list*& p) {
    list* temp = p;
    list buf;
    ofstream frm("List.txt");
    if (!frm.is_open())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *temp;
        frm.write((char*)&buf, sizeof(list));
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.dat\n";
}

void fromFile(list*& p) {
    list buf, * first = nullptr;
    ifstream frm("List.txt");
    if (frm.fail()) {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    frm.read((char*)&buf, sizeof(list));
    while (!frm.eof()) {
        insertEl(first, buf.number);
        cout << "-->" << buf.number;
        frm.read((char*)&buf, sizeof(list));
    }
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.dat\n";
}


int del(list*& p, int value) {
    list* previous, * current, * temp;
    if (value == p->number) {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

void sum(list* p)
{
    int sum = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number >= 0)
                sum += p->number;
            p = p->next;
        }
        if (sum != 0)
            cout << "Сумма = " << sum << endl;
        else
            cout << "Таких нет" << endl;
    }
}


int main() {
    setlocale(LC_CTYPE, "Russian");
    list* first = NULL;
    int choice; int value;
    while (true)
    {
        cout << " 1 - Ввод символа" << endl;
        cout << " 2 - Запись списка в файл" << endl;
        cout << " 3 - Чтение списка из файла" << endl;
        cout << " 4 - Выход" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:  	cout << "Введите символ ";
            cin >> value;
            insertEl(first, value);
            printList(first);
            break;
        case 2:    toFile(first);
            break;
        case 3:    fromFile(first);
            break;
        case 4:
            printList(first);
            break;
        case 5:
            cin >> value;
            del(first, value);
            break;
        case 6:
            sum(first);
            break;
        case 7:
            exit(0);
        default:   cout << "Неправильный выбор" << endl;
            break;
        }
    }
}
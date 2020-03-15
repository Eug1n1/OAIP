#include <iostream>
#include <string>

int ListSize = 0;

using namespace std;



struct byte
{
    unsigned num : 9;
};

enum specialities
{
    spec1,
    spec2,
    spec3,
    spec4
};

struct University
{
    string name;
    string ad;
    specialities spec;
    byte ball[4];
    int sum;
};

University un[3];

void add() {
    cin >> un[ListSize].name;
    cin >> un[ListSize].ad;
    int bal;
    cin >> bal;
    un[ListSize].ball[spec1].num = bal;
    cin >> bal;
    un[ListSize].ball[spec2].num = bal;
    cin >> bal;
    un[ListSize].ball[spec3].num = bal;
    cin >> bal;
    un[ListSize].ball[spec4].num = bal;
    cin >> un[0].sum;

    ListSize++;
}

void output() {
    for (int i = 0; i < ListSize; i++)
        printf("\n\n%s\n%s\nПОИТ: %d\nИСИТ: %d\nДЭиВИ: %d\nПОИБМС: %d\nСтоимость обучения: %d\n\n", un[i].name.c_str(), un[i].ad.c_str(), un[i].ball[spec1].num, un[i].ball[spec2].num, un[i].ball[spec3].num, un[i].ball[spec4].num, un[i].sum);
}

void search() {
    int spec, min, num;
    cin >> spec;

    min = un[0].ball[spec].num;

    for (int i = 0; i < ListSize; i++) {
        if (un[i].ball[spec].num < min) {
            min = un[i].ball[spec].num;
            num = i;
        }
            
    }

    printf("%s: %d", un[num].name.c_str(), un[num].ball[spec].num);
}

void del() {
    char choice[50];
    printf("\nname:\t");
    std::cin >> choice;
    for (int i = 0; i < ListSize; i++)
        if (strcmp(choice, un[i].name.c_str()) == 0) {
            for (int j = i; j < ListSize; j++)
                un[j] = un[j + 1];
            ListSize--;
        }
    printf("\n\t\tCOMPLETE\n\t\t");
}


int main()
{
    setlocale(LC_ALL, "ru");
    while (true) {
        int choice;
        printf("\nPRESS:\n1 - to get information\n2 - to add\n3 - to search information\n4 - to delete information\n5 - to exit\nCHOICE:\t");
        std::cin >> choice;
        switch (choice) {
        case 1: output(); break;
        case 2: add(); break;
        case 3: search(); break;
        case 4: del(); break;
        case 5: exit(0); break;
        default: printf("incorrent value!"); break;
        }
    }
}
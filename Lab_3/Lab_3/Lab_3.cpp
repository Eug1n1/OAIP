#include <iostream>
#include <fstream>

#define ArrSize 50

using std::ofstream;
using std::ifstream;

struct Teachers
{
    char teachersSurname[50];
    char examTitle[50];
    char examDate[10];

    void write() {
        ofstream fout("save.txt", ofstream::app);
        fout.write((char*)this, sizeof(Teachers));
        fout.close();
    }
};

struct Teachers listOfTeachers[50];
struct Teachers eraser;

int size = 0;

void add();
void del();
void change();
void output();
void readList();

int main()
{
    readList();

    while (true) {
        int choice;
        printf("\n\t\t\tPRESS:\n\t\t1 - to get information\n\t\t2 - to add\n\t\t3 - to change informaton\n\t\t4 - to delete information\n\t\t5 - to exit\n\t\tCHOICE:\t");
        std::cin >> choice;
        switch (choice) {
        case 1: output(); break;
        case 2: add(); break;
        case 3: change(); break;
        case 4: del(); break;
        case 5: exit(0); break;
        default: printf("incorrent value!"); break;
        }
    }
}

void readList()
{
    ifstream fin("save.txt");
    while (fin.read((char*)&listOfTeachers[size], sizeof(Teachers)))
    {
        size++;
    }
}

void output() {
    int choice;
    printf("\n\n\t\t\tPRESS:\n\t\t1 - to get information about 1 teacher\n\t\t2 - to get information about all teachers\n\t\tCHOICE:\t");
    std::cin >> choice;
    switch (choice) {
    case 1: {
        char SNChoice[50];
        printf("\n\t\tPlease enter a teacher's surname:\t");
        std::cin >> SNChoice;
        for (int i = 0; i < size; i++) {
            if (strcmp(SNChoice, listOfTeachers[i].teachersSurname) == 0) {
                printf("\n\t\t........REPORT........\n\t\tTeacher's number: %d\n\t\tTeacher's sourname: %s\n\t\tExam title: %s\n\t\tExam date: %s\n\t\t......................\n\n\n", i + 1, listOfTeachers[i].teachersSurname, listOfTeachers[i].examTitle, listOfTeachers[i].examDate);
            }
        }
    } break;
    case 2: {
        for (int i = 0; i < size; i++) {
            printf("\n\t\t........REPORT........\n\t\tTeacher's number: %d\n\t\tTeacher's sourname: %s\n\t\tExam title: %s\n\t\tExam date: %s\n\t\t......................\n\n\n", i + 1, listOfTeachers[i].teachersSurname, listOfTeachers[i].examTitle, listOfTeachers[i].examDate);
        }
    } break;
    default: printf("incorrent value!"); break;
    }
}

void add() {
    printf("\n\t\tInformation input:");
    if (size < ArrSize) {
        printf("\n\t\tTeacher's number: %d", size + 1);
        printf("\n\t\tEnter teacher's surname:\t");
        std::cin >> listOfTeachers[size].teachersSurname;
        printf("\t\tEnter exam title:\t");
        std::cin >> listOfTeachers[size].examTitle;
        printf("\t\tEnter exam date:\t");
        std::cin >> listOfTeachers[size].examDate;
        listOfTeachers[size].write();

        size++;
    }
    else {
        printf("\n\n\t\t...........Teachers array is already full!...........\n\n");
    }
}

void del() {
    char choice[50];
    printf("\n\t\tEnter a teacher's surname:\t");
    std::cin >> choice;
    if (strcmp(choice, "ALL") != 0) {
        for (int i = 0; i < size; i++)
            if (strcmp(choice, listOfTeachers[i].teachersSurname) == 0) {
                for (int j = i; j < size; j++)
                    listOfTeachers[j] = listOfTeachers[j + 1];
                size--;
            }
    }
    else{
        for (int i = 0; i < size; i++)
            listOfTeachers[i] = eraser;
        size = 0;
    }
    printf("\n\t\tCOMPLETE\n\t\t");
}

void change() {
    char choice[50];
    int ParChoice;
    printf("\n\t\tEnter a teacher's surname:\t");
    std::cin >> choice;
    for (int i = 0; i < size; i++) {
        if (strcmp(listOfTeachers[i].teachersSurname, choice) == 0) {
            do
            {
                printf("\n\t\tEnter:\n\t\t1 - to change surname\n\t\t2 - to change exam title\n\t\t3 - to change exam date\n\t\t4 - to finish changing\n\t\tChoice:\t");
                std::cin >> ParChoice;
                switch (ParChoice){

                case 1: {
                    printf("\n\t\tEnter new surname:\t");
                    std::cin >> listOfTeachers[i].teachersSurname;
                } break;

                case 2: {
                    printf("\n\t\tEnter new exam title:\t");
                    std::cin >> listOfTeachers[i].examTitle;
                } break;

                case 3:
                {
                    printf("\n\t\tEnter new exam date:\t");
                    std::cin >> listOfTeachers[i].examDate;
                }break;
                case 4: break;
                default: printf("incorrent value!"); break;
                }
            } while (ParChoice != 4);
        }
    }
}


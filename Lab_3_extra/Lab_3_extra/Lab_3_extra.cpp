﻿#include <iostream>
#include <limits>

#define ArrSize 100

void output();
void add();
void del();
void change();
void stat();

struct Students
{
	char name[255];
	int numExams;
	int examScore[10];
};

struct Students listOfStudents[ArrSize];
struct Students eraser;

int size = 0;

int main() {
	int choice;
	while (true){
		printf("\n\t\tSTUDENTS:\n\t\t1 - to get information\n\t\t2 - to get statistics\n\t\t3 - to add new student\n\t\t4 - to change information\n\t\t5 - to delete student\n\t\t6 - to exit\n\t\tCHOICE:\t");
		std::cin >> choice;
		switch (choice){
		case 1: output(); break;
		case 2: stat(); break;
		case 3: add(); break;
		case 4: change(); break;
		case 5: del(); break;
		case 6: exit(0); break;
		default: printf("\n\t\tIncorrent value!"); break;
		}
	}
}

void output() {
    int choice;
    printf("\n\n\t\t\tPRESS:\n\t\t1 - to get information about 1 student\n\t\t2 - to get information about all students\n\t\tCHOICE:\t");
    std::cin >> choice;
    switch (choice) {
    case 1: {
        char NChoice[255];
        printf("\n\n\t\tPlease enter a teacher's surname:\t");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        gets_s(NChoice);
        for (int i = 0; i < size; i++) {
            if (strcmp(NChoice, listOfStudents[i].name) == 0) {
                printf("\n\t\t........REPORT........\n\t\tStudent's number: %d\n\t\tStudent's name: %s\n\t\tExamination number: %d\n\t\texamination rating:\n\t\t", i + 1, listOfStudents[i].name, listOfStudents[i].numExams);
                for (int j = 0; j < listOfStudents[i].numExams; j++)
                    printf("%d ", listOfStudents[i].examScore[j]);
                printf("\n\t\t......................\n\n");
            }
        }
    } break;
    case 2: {
        for (int i = 0; i < size; i++) {
            printf("\n\n\t\t........REPORT........\n\t\tStudent's number: %d\n\t\tStudent's name: %s\n\t\tExamination number: %d\n\t\texamination rating: ", i + 1, listOfStudents[i].name, listOfStudents[i].numExams);
            for (int j = 0; j < listOfStudents[i].numExams; j++)
                printf("%d ", listOfStudents[i].examScore[j]);
            printf("\n\t\t......................\n\n");
        }
    } break;
    default: printf("incorrent value!"); break;
    }
}

void add() {
    printf("\n\t\tInformation input:");
    if (size < ArrSize) {
        printf("\n\t\tStudent's number: %d", size + 1);
        printf("\n\t\tEnter student's name:\t");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        gets_s(listOfStudents[size].name, 255);
        printf("\t\tEnter number of exams:\t");
        std::cin >> listOfStudents[size].numExams;
        printf("\t\tEnter exam marks:\t\n");
        for (int i = 0; i < listOfStudents[size].numExams; i++) {
            printf("\t\t%d: ", i + 1);
            std::cin >> listOfStudents[size].examScore[i];
        }
        size++;
    }
    else {
        printf("\n\n\t\t...........Teachers array is already full!...........\n\n");
    }
}

void del() {
    char choice[255];
    printf("\n\t\tEnter a teacher's surname:\t");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gets_s(choice, 255);
    if (strcmp(choice, "ALL") != 0) {
        for (int i = 0; i < size; i++)
            if (strcmp(choice, listOfStudents[i].name) == 0) {
                for (int j = i; j < size; j++)
                    listOfStudents[j] = listOfStudents[j + 1];
                size--;
            }
    }
    else {
        for (int i = 0; i < size; i++)
            listOfStudents[i] = eraser;
        size = 0;
    }
    printf("\n\t\tCOMPLETE\n\t\t");
}

void change() {
    char choice[255];
    int ParChoice;
    printf("\n\t\tEnter a student's name:\t");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    gets_s(choice);
    for (int i = 0; i < size; i++) {
        if (strcmp(listOfStudents[i].name, choice) == 0) {
            do
            {
                printf("\n\t\tEnter:\n\t\t1 - to change name\n\t\t2 - to change number of exams\n\t\t3 - to change exam marks\n\t\t4 - to finish changing\n\t\tChoice:\t");
                std::cin >> ParChoice;
                switch (ParChoice) {

                case 1: {
                    printf("\n\t\tEnter new name: ");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    gets_s(listOfStudents[i].name);
                } break;

                case 2: {
                    printf("\n\t\tEnter new number of exams: ");
                    std::cin >> listOfStudents[i].numExams;
                } break;

                case 3:
                {
                    printf("\n\t\tEnter new exam marks:\n");
                    for (int j = 0; j < listOfStudents[i].numExams; j++) {
                        printf("\t\t%d: ", j + 1);
                        std::cin >> listOfStudents[i].examScore[j];
                    }

                }break;
                case 4: break;
                default: printf("incorrent value!"); break;
                }
            } while (ParChoice != 4);
        }
    }
}

void stat() {
    float count = 0;
    float countStudents = 0;
    for (int i = 0; i < size; i++) {
        count = 0;
        for (int j = 0; j < listOfStudents[i].numExams; j++) {
            if (listOfStudents[i].examScore[j] > 8)
                count++;
            if (j + 1 == listOfStudents[i].numExams && count == listOfStudents[i].numExams)
                countStudents++;
        }
    }
    printf("\n\t\t.....STATISTICS.....\n\t\tStudent performance: %10.2f %%\n\t\t....................\n\n", (countStudents / (size)) * 100);
}
#include <iostream>
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
struct Students eriser;

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
        char NChoice[50];
        printf("\n\n\t\tPlease enter a teacher's surname:\t");
        std::cin >> NChoice;
        for (int i = 0; i < size; i++) {
            if (strcmp(NChoice, listOfStudents[i].name) == 0) {
                printf("\n\t\t........REPORT........\n\t\tStudent's number: %d\n\t\tStudent's name: %s\n\t\tExamination number: %d\n\t\texamination rating:\n\t\t", i + 1, listOfStudents[i].name, listOfStudents[i].numExams);
                for (int j = 0; j < listOfStudents[i].numExams; j++)
                    printf("%d ", listOfStudents[i].examScore[j]);
                printf("\n\t\t......................");
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

}

void change() {

}

void stat() {

}

#include <iostream>

#define ArrSize 8

void add();
void change();
void output();

struct TRAIN
{
    char destination[100];
    char trainNumber[30];
    char departureTime[30];
};

struct TRAIN TRAINList[ArrSize];

int size = 0;

int main()
{
    while (true){

        int choice = 0;
        std::cin >> choice;

        switch (choice){
            case 1: output(); break;
            case 2: add(); break;
            case 3: change(); break;
            case 4: exit(0); break;
            default: printf("\n\n\t\tINCORRECT VALUE!\n\n"); break;
        }
    }
}

void add() {
    printf("\n\t\tInformation input:");
    if (size < ArrSize) {
        printf("\n\t\tEnter train destination:\t");
        gets_s(TRAINList[size].destination);
        printf("\t\tEnter train number:\t");
        gets_s(TRAINList[size].trainNumber);
        printf("\t\tEnter train departure time:\t");
        gets_s(TRAINList[size].departureTime);
        size++;
    }
    else {
        printf("\n\n\t\t...........Array is already full!...........\n\n");
    }
}

void change() {
    char choice[30];
    int ParChoice;
    printf("\n\t\tEnter a train number:\t");
    std::cin >> choice;
    for (int i = 0; i < size; i++) {
        if (strcmp(TRAINList[i].trainNumber, choice) == 0) {
            do
            {
                printf("\n\t\tEnter:\n\t\t1 - to change desitnation\n\t\t2 - to change train number\n\t\t3 - to change departure time\n\t\t4 - to finish changing\n\t\tChoice:\t");
                std::cin >> ParChoice;
                switch (ParChoice) {

                case 1: {
                    printf("\n\t\tEnter new destination:\t");
                    gets_s(TRAINList[i].destination);
                } break;

                case 2: {
                    printf("\n\t\tEnter new train number:\t");
                    gets_s(TRAINList[size].trainNumber);
                } break;

                case 3:
                {
                    printf("\n\t\tEnter new departure time:\t");
                    gets_s(TRAINList[size].departureTime);
                }break;
                case 4: break;
                default: printf("\n\n\t\tINCORRECT VALUE!\n\n"); break;
                }
            } while (ParChoice != 4);
        }
    }
}

void output() {

}
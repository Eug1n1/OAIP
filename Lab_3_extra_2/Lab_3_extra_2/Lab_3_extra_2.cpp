#include <iostream>

#define ArrSize 8

void add();
void change();
void output();
void sort();
void out();

struct TRAIN
{
    char destination[100];
    char trainNumber[10];
    char departureTime[5];
    int hour;
    int minutes;
};

struct TRAIN TRAINList[ArrSize];
struct TRAIN buff;

int size = 0;

int main()
{
    while (true){
        printf("\n\n\t\t.....MAIN MENU.....\n\t\t1 - to get information\n\t\t2 - add new cruise\n\t\t3 - to change cruise\n\t\t4 - to exit\n\t\tChoice: ");
                      
        int choice = 0;
        std::cin >> choice;
        printf("\t\t...................");
        switch (choice){
            case 1: output(); break;
            case 2: add(); sort(); break;
            case 3: change(); sort(); break;
            case 4: out(); break;
            default: printf("\n\n\t\tINCORRECT VALUE!\n\n"); break;
        }
    }
}

void add() {
    printf("\n\n\n\t\t.....Information input.....");
    if (size < ArrSize) {

        printf("\n\t\tEnter train destination:\t");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        gets_s(TRAINList[size].destination);

        printf("\t\tEnter train number:\t");
        std::cin >> TRAINList[size].trainNumber;

        printf("\t\tEnter train departure time:\t");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> TRAINList[size].departureTime;

        printf("\t\t...........................\n\n");

        TRAINList[size].hour = (TRAINList[size].departureTime[0] - '0') * 10 + (TRAINList[size].departureTime[1] - '0');
        TRAINList[size].minutes = (TRAINList[size].departureTime[3] - '0') * 10 + (TRAINList[size].departureTime[4] - '0');

        size++;
    }
    else {
        printf("\n\n\t\t...........Array is already full!...........\n\n");
    }
}

void change() {
    char choice[30];
    int ParChoice;
    printf("\n\n.....CHANGING.....");
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
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    gets_s(TRAINList[i].destination);
                } break;

                case 2: {
                    printf("\n\t\tEnter new train number:\t");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> TRAINList[size].trainNumber;
                } break;

                case 3:
                {
                    printf("\n\t\tEnter new departure time:\t");
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cin >> TRAINList[size].departureTime;
                }break;
                case 4: break;
                default: printf("\n\n\t\tINCORRECT VALUE!\n\n"); break;
                }
                printf("..................\n\n");
            } while (ParChoice != 4);
        }
    }
}

void sort() {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < (size - 1) - i; j++)
            if (TRAINList[j].destination[0] > TRAINList[j + 1].destination[0]) {

                for(int k = 0; k < 100; k++)
                    buff.destination[k] = TRAINList[j].destination[k];
                for (int k = 0; k < 10; k++)
                    buff.trainNumber[k] = TRAINList[j].trainNumber[k];
                for (int k = 0; k < 5; k++)
                    buff.departureTime[k] = TRAINList[j].departureTime[k];



                for (int k = 0; k < 100; k++)
                    TRAINList[j].destination[k] = TRAINList[j + 1].destination[k];
                for (int k = 0; k < 10; k++)
                    TRAINList[j].trainNumber[k] = TRAINList[j + 1].trainNumber[k];
                for (int k = 0; k < 5; k++)
                    TRAINList[j].departureTime[k] = TRAINList[j + 1].departureTime[k];
                


                for (int k = 0; k < 100; k++)
                    TRAINList[j + 1].destination[k] = buff.destination[k];
                for (int k = 0; k < 10; k++)
                    TRAINList[j + 1].trainNumber[k] = buff.trainNumber[k];
                for (int k = 0; k < 5; k++)
                    TRAINList[j + 1].departureTime[k] = buff.departureTime[k];
            }
}

void output() {
    char ChoosenTime[6];

    int count = 0;

    printf("\n\n\t\tEnter a departure time: ");
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin >> ChoosenTime;

    char hour[2] = { ChoosenTime[0], ChoosenTime[1]};
    char minutes[2] = { ChoosenTime[3], ChoosenTime[4]};

    for (int i = 0; i < size; i++) {
        char trainHour[2] = { TRAINList[i].departureTime[0], TRAINList[i].departureTime[1] };
        char trainMinutes[2] = { TRAINList[i].departureTime[3], TRAINList[i].departureTime[4] };
        if (strcmp(trainHour, hour) > 0) {
            printf("\n\n\t\t.....CRUISE.....\n\t\tDestination: %s\n\t\tTrain number: %s\n\t\tTime: %s\n\t\t................\n\n", TRAINList[i].destination, TRAINList[i].trainNumber, TRAINList[i].departureTime);
            count++;
        }
        else if (strcmp(trainHour, hour) == 0 && strcmp(trainMinutes, minutes) >= 0) {
            printf("\n\t\t.....CRUISE.....\n\t\tDestination: %s\n\t\tTrain number: %s\n\t\tTime: %s\n\t\t................\n", TRAINList[i].destination, TRAINList[i].trainNumber, TRAINList[i].departureTime);
            count++;
        }
        if (i + 1 == size && count == 0)
            printf("\n\t\tNothing suitable!");
    }
}

void out() {
    for (int i = 0; i < size; i++) {
        printf("\n\t\t........REPORT........\n\t\tTeacher's number: %d\n\t\tTeacher's sourname: %s\n\t\tExam title: %s\n\t\tExam date: %s\n\t\t......................\n\n\n", i + 1, TRAINList[i].destination, TRAINList[i].trainNumber, TRAINList[i].departureTime);
    }
}
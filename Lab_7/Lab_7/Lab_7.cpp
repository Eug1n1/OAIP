#include <iostream>
#include "Header.h"


int main()
{
	setlocale(LC_ALL, "rus");
	int size;
	printf("Размер очереди: ");
	cin >> size;
	Queue q1 = createQueue(size);

	while(true) {
		printf("\n1 - добавить\n2 - вывести\n3 - очистить\n4 - размер очереди\n5 - задание\n6 - выход\n");
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			char ch;
			cin >> ch;
			if (EnterNew(q1, ch))
				printf("Успех");
			else
				printf("\n\nОчередь переполнена\n\n");
			break;
		case 2:
			Print(q1);
			break;
		case 3:
			releaseQueue(q1);
			break;
		case 4:
			printf("Размер: %d", q1.realSize);
			break;
		case 5:
			myFunc(q1);
			break;
		case 6:
			exit(0);
		default:
			break;
		}
	}
}

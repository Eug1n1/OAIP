#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct stack {
	int value;
	stack* next;
	stack* head;
};

void output(stack* st);
void input(stack* st, int value);
void clear(stack* st);
void save(stack* st);
void read(stack* st);
void myFunc(stack* st);

int main() {
	int choice = 7;
	stack* st = new stack;
	st->head = NULL;
	while (true) {

		std::cin >> choice;
		switch (choice) {
		case 1:
			output(st);
			break;
		case 2:
			int value;
			std::cin >> value;
			input(st, value);
			break;
		case 3:
			clear(st);
			break;
		case 4:
			save(st);
			break;
		case 5:
			read(st);
			break;
		case 6:
			myFunc(st);
			break;
		case 7:
			exit(0);
		default:
			printf("Incorrect value!");
			break;
		}
	}
}
void output(stack* st) {
	stack* e = st->head;
	if (e == NULL) {
		printf("stack is empty!");
	}
	while (e != NULL) {
		printf(" %d ", e->value);
		e = e->next;
	}
}

void input(stack* st, int value) {
	stack* e = new stack;
	e->value = value;
	e->next = st->head;
	st->head = e;
}

void clear(stack* st) {

}

void save(stack* st) {
	ofstream frm("list.txt");
	stack* current = st->head;
	while (current != NULL)
	{
		frm << current->value << " ";
		current = current->next;
	}
	frm.close();
}


void read(stack* st) {
	ifstream frm("list.txt");
	if (!frm.is_open())
	{
		cout << "\n Ошибка открытия файла";
		exit(1);
	}
	string temp;
	while (getline(frm, temp))
	{
		frm >> temp;
		cout << temp << " ";
	}
	frm.close();
}

void myFunc(stack* st) {

}
#ifndef SYMBOL
#define SYMBOL

#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::ofstream;
using std::getline;
using std::string;

struct STACK {
	int data;
	STACK* head;
	STACK* next;
};

void AddEl(int elem, STACK* stack);
int TakeFromStack(STACK* stack);
void PrintStack(STACK* stack);
void ToFile(STACK* stack);
void FromFile(STACK* stack);
int DeleteSame(STACK* stack);
void clear(STACK* stack);
void Delete3(STACK* stack);
void DeleteSameHelp(STACK* stack, int point);

#endif
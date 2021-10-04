#include "header.h"

void AddEl(int elem, STACK* stack)
{
	STACK* NewEl = new STACK;
	NewEl->data = elem;
	NewEl->next = stack->head;
	stack->head = NewEl;
}

int TakeFromStack(STACK* stack)
{
	if (stack->head == NULL)
	{
		cout << "Стек пуст";
		return -1;
	}
	else {
		STACK* intermEl = new STACK;
		int elData = stack->head->data;
		stack->head = stack->head->next;
		delete intermEl;
		return elData;
	}
}

void PrintStack(STACK* stack)
{
	STACK* sthead = stack->head;
	int elData;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->data;
		cout << elData << " ";
		sthead = sthead->next;
	}
	cout << "\n";
}

void ToFile(STACK* stack)
{
	ofstream getf;
	getf.open("File13.txt");
	if (getf.is_open())
	{
		STACK* StackHead = stack->head;
		while (StackHead != NULL)
		{
			getf << StackHead->data << " ";
			StackHead = StackHead->next;
		}; cout << "\n";
	}
	getf.close();
	cout << "Информация записана в файл!\n\n";
}

void FromFile(STACK* stack)
{
	string line;
	ifstream outf("File13.txt");
	if (outf.is_open())
	{
		while (getline(outf, line))
		{
			outf >> line;
			cout << line << " ";
		}
	}
	outf.close();
	cout << "\nИнформация выведена из файла!\n\n";
}

int DeleteSame(STACK* stack)
{
	STACK* sthead = stack->head;
	int elData, arr[20], i = 0, point = -1;
	if (sthead == NULL)
		cout << "Стек пуст";
	while (sthead != NULL)
	{
		elData = sthead->data;
		arr[i] = elData;
		sthead = sthead->next;
		i++;
	}
	for (int j = 0; j < i; j++)
	{
		int interm = arr[j], count = 0;
		for (int p = 0; j + p - 1 < i; p++)
		{
			if (arr[p] == interm)
				count++;
			if (count > 1)
			{
				point = p;
				j = i + 1;
				break;
			}
		}
	}
	return point;
}

void DeleteSameHelp(STACK* stack, int point)
{
	STACK* sthead1 = stack->head;
	for (int k = 0; k < point - 1; k++)
		sthead1 = sthead1->next;

	sthead1->next = sthead1->next->next;
}

void clear(STACK* stack)
{
	if (stack->head == NULL)
		cout << "Стек пуст";
	while (stack->head != NULL)
	{
		STACK* f = stack->head;
		stack->head = stack->head->next;
		delete f;
	}
	cout << "\n";
}
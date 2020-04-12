#pragma once
#define MYQUEUE1_EQE  0x0000

using std::cin;

struct Queue
{
	int Head;
	int Tail;
	int Size;
	int realSize = 0;
	char* Data;
	Queue(int size)
	{
		Head = Tail = 0;
		Data = new char[Size = size];
	}
	bool isFull() const;
	bool isEmpty()const;
};

Queue createQueue(int n);
Queue createQueue(const Queue& pq);
bool  EnterNew(Queue& q, char x);
void DeleteEl(Queue& q); 
void clearQueue(Queue& q);
void deleteQueue(Queue* q);
void releaseQueue(Queue& q);
void Print(Queue& q);
void myFunc(Queue& q);

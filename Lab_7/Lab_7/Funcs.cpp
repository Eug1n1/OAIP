#include <iostream>
#include "Header.h"

bool Queue::isFull() const
{
	return (Head % Size == (Tail + 1) % Size);
}
bool Queue::isEmpty() const
{
	return (Head % Size == Tail % Size);
}

Queue createQueue(int n)          // Выделить ресурс для очереди
{
	return *(new Queue(n));
};
Queue createQueue(const Queue& pq)   // Создать очередь 
{
	Queue* rc = new Queue(pq.Size - 1);
	rc->Head = pq.Head;
	rc->Tail = pq.Tail;
	for (int i = 0; i < pq.Size; i++)
		rc->Data[i] = pq.Data[i];
	return *rc;
}

bool EnterNew(Queue& q, char x)
{
	bool rc = true;
	if (rc = !q.isFull())
	{
		q.Data[q.Tail] = x;
		q.Tail = (q.Tail + 1) % q.Size;
	}
	else
		rc = false;
	q.realSize++;
	return rc;
}

void DeleteEl(Queue& q)               // Удалить элемент 
{
	for (int i = 0; i < q.Size - 1; i++)
		q.Data[i] = q.Data[i + 1];
	q.realSize--;
}

void  deleteQueue(Queue* q)       // Очистить очередь
{
	printf("Удалено %d элементов", q->Size);
	delete q;
}

void Print(Queue& q)    // Вывод на экран 
{
	for (int i = 0; i < q.realSize; i++)
		printf("%c ", q.Data[i]);
}

void releaseQueue(Queue& q)     // Освободить ресурсы очереди
{
	for (int i = 0; i < q.Size - 1; i++)
		q.Data[i] = '\0';
	q.Size = 1;
	q.Head = q.Tail = 0;
}

void myFunc(Queue& q) {

	char et, ch;
	cin >> et;

	for (int i = 0; i < q.Size - 1; i++) {
		printf("Введите символ: ");
		cin >> ch;
		if (ch != et) {
			EnterNew(q, ch);
		}
		else
		{
			EnterNew(q, ch);
			DeleteEl(q);
			DeleteEl(q);
			printf("Размер: %d", q.realSize);
			break;
		}
	}
}
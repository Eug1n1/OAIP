#include "Tree.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Tree* mainRoot = new Tree;
	int choice;

	while (1)
	{
		cout << "\n\t........Меню работы с деревом........\n";
		cout << "\t...1. Добавление эллементов....\n";
		cout << "\t...2. Вывод дерева в консоль....\n";
		cout << "\t...3. Удаление....\n";
		cout << "\t...4. Прямой(нисходящий) обход с выводом....\n";
		cout << "\t...5. Обратный(смешанный) обход с выводом....\n";
		cout << "\t...6. Проверка на балансировку дерева....\n";
		cout << "\t...7. Задание\n";
		cout << "\t...0. Выход....\n\n";

		cout << "Ваш выбор: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
		{
			cout << "\nДобавление будет осуществляться пока вы не введёте отрицательное число. " << endl;
			cout << "Введите эл-т: "; cin >> choice;
			while (choice > 0)
			{
				mainRoot->AddNode(choice);
				cout << "Введите эл-т: "; cin >> choice;
			}
			break;
		}

		case 2:
		{
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else mainRoot->PrintTree(mainRoot->node, 0);
			break;
		}

		case 3:
		{
			int key;
			cout << "Введите ключ эл-та который хотите удалить: "; cin >> key;
			mainRoot->Delete(key);
			break;
		}

		case 4:
		{
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else mainRoot->DirectBypass(mainRoot->node);
			break;
		}

		case 5:
		{
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else mainRoot->ReverseBypass(mainRoot->node);
			break;
		}
		case 6:
		{
			mainRoot->counter = 0;
			if (!mainRoot->node) cout << "В дереве ничего нет.\n";
			else
				if (mainRoot->Balance(mainRoot->node))
					cout << "Дерево сбалансировано" << endl;
				else
					cout << "Дерево не сбалансировано" << endl;
			break;
		}
		case 7:
		{
			mainRoot->countR = 0;
			mainRoot->countRight(mainRoot->node->right);
			printf("countR = %d", mainRoot->countR);
			break;
		}
		case 0:
		{
			exit(0);
			break;
		}
		default:
		{
			cout << "Такого пункта нет. Выберете снова.\n";
			break;
		}

		}
	}
}
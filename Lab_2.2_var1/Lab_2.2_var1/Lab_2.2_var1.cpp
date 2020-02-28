#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fout("file_1.txt");

	char Buff[255];
	gets_s(Buff);

	fout << Buff;

	fout.close();

	ifstream fin("file_1.txt");

	fin.getline(Buff, 255);

	char Arr[5] = {'1', '3', '5', '7', '9'};

	for (int i = 0; i < strlen(Buff); i++) {
		for (int j = 0; j < strlen(Arr); j++)
			if (Buff[i] == Arr[j]) 
				printf("A[%d] = %c", i, Buff[i]);

	}
}

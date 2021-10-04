#include <iostream>
#include <fstream>

using namespace std;

int main()
{	
	ifstream fin;
	fin.open("file_1.txt");
	ofstream fout;
	fout.open("file_2.txt");

	char ***Arr = new char**[10];
	for (int i = 0; i < 10; i++) {
		Arr[i] = new char*[30];
		for (int j = 0; j < 30; j++) {
			Arr[i][j] = new char[30];
		}
	}

	char ch;
	int str = 0, word = 0;
	while (!fin.eof()) {
		fin >> Arr[str][word];
		printf("Arr[%d][%d]: %s\n", str, word, Arr[str][word]);
		word++;
		fin.get(ch);
		if (ch == '\n') {
			str++;
			word = 0;
		}
	}


	bool norm = false;
	int Num = 0;
	int* num = (int*)calloc(10, sizeof(int));
	for (int i = 0; i < str; i++) {
		norm = false;
		for (int j = 0; j < 20; j++) {
			if (norm == true)
				break;
			for (int k = 0; k < 20; k++) {
				if (strcmp(Arr[i][j], Arr[i][k]) == 0 && j != k && k > j && k < 11 && j < 11) {

					for (int a = 0; a < 10; a++) {
						fout << " ";
						fout << Arr[i][a];
					}
					fout << '\n';
					break;
				}
			}
		}
	}
	
	fout.close();
	fin.close();
	getchar();
}

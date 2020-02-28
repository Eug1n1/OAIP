#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("file_1.txt");
    ofstream fout("file_2.txt");
    char Buff;
    int i = 1;
    int size_1 = 0; int size_2 = 0;
    while (!fin.eof()) {
        fin.get(Buff);
        size_1 += sizeof(Buff);
        if (i % 2 == 0) {
            fout << Buff;
            size_2 += sizeof(Buff);
        }
        if (Buff == '\n')
            i++;
    }

    printf("size of file_1: %d;\nsize of file_2: %d;\n", size_1, size_2);

    fout.close();
    fin.close();
    system("pause");
}


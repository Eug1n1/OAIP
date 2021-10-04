#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("file_1.txt");

    char Buff[255];
    gets_s(Buff);

    fout << Buff;

    fout.close();

    ifstream fin("file_1.txt");

    
    char min[30];
    char Buff_2[30];

    fin >> min;
    
    while (!fin.eof()) {
        fin >> Buff_2;
        if (strlen(Buff_2) < strlen(min)) {
            for (int i = 0; i < 30; i++)
                min[i] = Buff_2[i];
        }
        else if (strlen(Buff_2) == strlen(min) && Buff_2 < min)
                for (int i = 0; i < 30; i++)
                    min[i] = Buff_2[i];
        }
    printf("min: %s\n", min);
    fin.close();
    system("pause");
}


#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("file_1.txt");
    ofstream fout("file_2.txt");
    
    char Buff[255];
    char Buff_2[30];
    while (!fin.eof()) {
        fin.getline(Buff, 255);
        if (Buff[0] == 'A' || Buff[0] == 'А') {
            fout << Buff;
            fout << '\n';
        }   
    }

    fout.close();
    fin.close();

    ifstream fin_2("file_2.txt");

    int count = 0;

    while(fin_2 >> Buff_2)
        count++;

    printf("count = %d", count);

    fin.close();
}


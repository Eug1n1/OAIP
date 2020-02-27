#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("file_1.txt");

    char ch[512] = "string slkdfn xklfjb xkjbfa klf aldnfkh kjsdbvf zjhdv xvhjbasjd sjdhfvbgx";
    fout << ch;
    
    fout.close();

    ifstream fin;
    fin.open("file_1.txt");

    char** str = (char**) calloc(10, sizeof(char));
    for (int i = 0; i < 10; i++)
        str[i] = (char*)calloc(10, sizeof(char));
    
    int i = 0;
    while (!fin.eof()) {
        fin >> str[i];
        i++;
    }

    //for (int i = 0; i < 10; i++) {
    //    printf("%s\n", str[i]);
    //}

    for(int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++) {
            if (str[i][j] == 'x') {
                printf("%s\n", str[i]);
            }
        }
    fin.close();
    getchar();
}



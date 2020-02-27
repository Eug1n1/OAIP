#include <stdio.h>

int main(void)
{
    char *str;
    str = (char*) calloc(100, sizeof(char));
    FILE* mf;
    int sym;
    mf = fopen("file_1.txt", "r");
    int i = 1, size = 0;
    int first;
    for (int a = 0; a < 100; a++)
    {
        str[a] = fgetc(mf);
        if (str[a] == EOF)
        {
            break;
        }
        if (str[a] != 10 && str[a] != 32 && str[a] != 0) {
            size++;
        }
        if (i == 1) {
            first = str[a] - '0';
        }
        i++;
    }
    printf("%d\n", size);
    char *str2 = (char*) calloc(size, sizeof(char));
    for (int i = 0, a = 0; i < 100; i++) {
        if (str[i] != 10 && str[i] != 32 && str[i] != 0) {
            str2[a] = str[i];
            a++;
        }
    }
    for (int i = 0; i < 100; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
    int k = 0;
    scanf("%d", &k);
    if (k > first || k <= 0)
        exit(0);
    FILE* file_2 = fopen("file_2.txt", "w");
    for (int i = 0; i < first; i++) {
        fprintf(file_2, "%c", str2[(k - 1) + first * i]);
    }
    fclose(mf);
    return 0;
}
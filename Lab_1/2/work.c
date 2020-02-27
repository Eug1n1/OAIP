#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    FILE* F1;
    F1 = fopen("file.txt", "wt");
    if (!F1)
    {
        printf("Error!");
        return 0;
    }
    for (i = 1; i < 11; i++) {
        fprintf(F1, "%d\n", i);
    }
    fclose(F1);
    int k = 0;
    FILE* finput;
    int s;
    finput = fopen("file.txt", "r+");

    while ((fscanf(finput, "%d", &s) != EOF))
    {
        if (!finput) break;
        k++;
    }
    int* c = (int*)malloc(k * sizeof(int));
    rewind(finput);
    FILE* F2;
    F2 = fopen("file2.txt", "wt");
    int a;
    scanf("%i", &a);
    for (i = 0; i < 10; i++)
    {
        fscanf(finput, "%d", &c[i]);
        if(i == a - 1 || i == a || i == a + 1 || i == a + 2)
            fprintf(F2, "%d\n", c[i]);
    }
    fclose(finput);
    free(c);
    fclose(F2);
    printf("DONE!");
    return 0;
}
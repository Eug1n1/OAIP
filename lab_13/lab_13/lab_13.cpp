#include <iostream>

void bubbleSort(int a[], int size)
{
    int t;
    for (int i = 1; i < size; i++)
        for (int j = size - 1; j >= i; j--)
            if (a[j - 1] < a[j])
            {
                t = a[j - 1];
                a[j - 1] = a[j];
                a[j] = t;
            }
}

int getHoarBorder(int A[], int sm, int em)
{
    int i = sm - 1, j = em + 1;
    int brd = A[sm];
    int buf;
    while (i < j)
    {
        while (A[--j] < brd);
        while (A[++i] > brd);
        if (i < j)
        {
            buf = A[j];
            A[j] = A[i];
            A[i] = buf;
        };
    }
    return j;
}

int* sortHoar(int A[], int sm, int em)
{
    if (sm < em)
    {
        int hb = getHoarBorder(A, sm, em);
        sortHoar(A, sm, hb);
        sortHoar(A, hb + 1, em);
    }
    return A;
};


int main()
{
    int* A = new int[10]{ 10, 21, 32, 34, 55, 12, 45, 84, 17, 14 };
    int* B = new int[5]{ 16, 23, 45, 24, 15 };
    int* C = new int[10];
    
    int maxB = B[0];
    for (int i = 0; i < 5; i++) {
        if (B[i] > maxB)
            maxB = B[i];
    }
    
    for (int i = 0, j = 0; i < 10; i++) {
        if(A[i] < maxB)
            C[j++] = A[i];
    }


    for (int i = 0, j = 0; i < 7; i++) {
        std::cout << C[i] << std::endl;
    }
    std::cout << std::endl << std::endl;

    //bubbleSort(C, 7);

    sortHoar(C, 0, 6);

    for (int i = 0, j = 0; i < 7; i++) {
        std::cout << C[i] << std::endl;
    }


}

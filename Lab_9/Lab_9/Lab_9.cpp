#include <iostream>
#define DEBUG1

int test(int a) {
#ifdef DEBUG
    std::cout << "вызов функции" << a << std::endl;
#endif // DEBUG
    return a < 100 ? a + 10 : test(a - 4);
}

int test2(int number, int limit) {
    if (limit == 0) {
        if (number == 0)
            return 1;
        return 0;
    }

    if (limit <= number)
        return test2(number, limit - 1) + test2(number - limit, limit);
    return test2(number, number);
}

int main()
{
    setlocale(LC_ALL, "ru");
    int a = 200;
    std::cout << test(a) << std::endl;
    int m = 4, n = 4;
    std::cout << test2(m, n) << std::endl;
}



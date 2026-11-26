#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, ".65001");

    int summa = 0;

    for (int i = 1; i < 200; i += 2)
    {
        summa += i;
    }

    cout << "Сумма целых положительных нечётных чисел меньших 200: " << summa << endl;

    return 0;
}

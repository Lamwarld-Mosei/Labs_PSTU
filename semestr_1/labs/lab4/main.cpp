#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <clocale>

using namespace std;

void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(4) << a[i];
    cout << endl;
}


void removeAllZeros(int a[], int& n)
{
    int j = 0;

    for (int i = 0; i < n; i++)
        if (a[i] != 0)
            a[j++] = a[i];

    n = j;
}

void insertAfterFirstEven(int a[], int& n)
{
    int pos = -1;

    for (int i = 0; i < n; i++)
        if (a[i] % 2 == 0)
        {
            pos = i;
            break;
        }

    if (pos == -1)
        return;

    int value = (pos > 0) ? a[pos - 1] : 2;

    for (int i = n; i > pos + 1; i--)
        a[i] = a[i - 1];

    a[pos + 1] = value;
    n++;
}

int main()
{
    setlocale(LC_ALL, "ru");
    srand((time(nullptr)));

    int a[100];
    int n;

    cout << "Введите реальную длину массива (не больше " << 99 << "): ";
    cin >> n;


    for (int i = 0; i < n; i++)
        a[i] = rand() % 21 - 10;

    cout << "\n1. Исходный массив:" << endl;
    printArray(a, n);


    removeAllZeros(a, n);
    cout << "\n2. Массив после удаления нулей:" << endl;
    printArray(a, n);


    insertAfterFirstEven(a, n);
    cout << "\n3. Массив после вставки:" << endl;
    printArray(a, n);

    return 0;
}
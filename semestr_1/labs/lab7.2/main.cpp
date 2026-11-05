#include <iostream>
#include <clocale>
#include <cstdarg>

int sum(int count, ...)
{
	va_list args;
	va_start(args, count);

	int summa = 0;

	for (int i = 0; i < count; i++)
	{
		summa += va_arg(args, int);
	}
	va_end(args);

	return summa;
}

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int sum1, sum2, sum3;

	sum1 = sum(5, 1, 2, 3, 4, 5);
	sum2 = sum(10, 2, 3, 0, 0, 0, 0, 0, -1, -1, -1);
	sum3 = sum(12, -1, -1, -1, -1, -1, -1111, 0, 0, 0, 0, 100000, 123);

	std::cout << "Сумма из 5 элементов: " << sum1 << std::endl;
	std::cout << "Сумма из 10 элементов: " << sum2 << std::endl;
	std::cout << "Сумма из 12 элементов: " << sum3 << std::endl;

	return 0;
}
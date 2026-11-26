#include <iostream>
#include <clocale>

int multiply(const int a, const int b)
{
	return a * b;
}

void multiply(const double a, const double b, const double c, const double d)
{
	// (a + bi) * (c + di)
	double real_piece = (a * c) - (b * d);
	double imaginary_piece = (a * d) + (b * c);

	std::cout << "Результат: " << real_piece;

	if (imaginary_piece >= 0)
	{
		std::cout << " + " << imaginary_piece << "i";
	}
	else
	{
		std::cout << " - " << imaginary_piece << "i";
	}

	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int x, y;

	std::cout << "Введите два числа типа int через пробел: ";
	std::cin >> x >> y;

	std::cout << "Произведение 2 чисел: " << multiply(x, y) << std::endl;

	double a, b, c, d;

	std::cout << "\nВведите первое комплексное число (a и b) через пробел: ";
	std::cin >> a >> b;

	std::cout << "Введите второе комплексное число (c и d) через пробел: ";
	std::cin >> c >> d;

	std::cout << "Первое число: " << a << " + " << b << "i" << std::endl;
	std::cout << "Второе число: " << c << " + " << d << "i" << std::endl;

	multiply(a, b, c, d);

	return 0;
}
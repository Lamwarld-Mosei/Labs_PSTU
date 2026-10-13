#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

template <typename T>
void FindResult(T a, T b, int c)
{
	T first_value = pow(a + b, 3);

	T value1 = a * a * a;
	T value2 = 3 * a * a * b;
	T second_value = (value1 + value2);

	T value3 = 3 * a * b * b;
	T value4 = b * b * b;
	T second_result = value3 + value4;

	T first_result = first_value - second_value;
	T result = first_result / second_result;

	cout << "======" << typeid(T).name() << "======" << "\n";
	cout << setprecision(c);

	cout << "(a+b)^3: " << first_value << "\n\n";
	cout << "a^3: " << value1 << "\t3ab^2: " << value2 << "\n\n";
	cout << "(a^3 + 3ab^2): " << second_value << "\n\n";
	cout << "3ab^2: " << value3 << "\tb^3: " << value4 << "\n\n";
	cout << "(3ab^2 + b^3): " << second_result << "\n\n";
	cout << "(a+b)^3 - (a^3 + 3ab^2): " << first_result << "\n\n";
	cout << "result = " << result << "\n\n\n\n";
}

int main()
{
	setlocale(LC_ALL, "ru");

	cout << fixed;

	FindResult(1000.0f, 0.0001f, 7);
	FindResult(1000.0, 0.0001, 15);
}	
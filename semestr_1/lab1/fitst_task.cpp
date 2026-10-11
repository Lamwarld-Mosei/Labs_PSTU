#include <iostream>
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "ru");

	double a_d = 1000.0;
	double b_d = 0.0001;

	double d_1 = ((a_d + b_d) * (a_d + b_d) * (a_d + b_d)) - (a_d * a_d * a_d + 3 * a_d * a_d * b_d);
	double d_2 = 3 * a_d * b_d * b_d + b_d * b_d * b_d;
	double result_d = d_1 / d_2;


	float a_f = 1000.0f;
	float b_f = 0.0001f;

	float f_1 = ((a_f + b_f) * (a_f + b_f) * (a_f + b_f)) - (a_f * a_f * a_f + 3 * a_f * a_f * b_f);
	float f_2 = 3 * a_f * b_f * b_f + b_f * b_f * b_f;
	float result_f = f_1 / f_2;

	std::cout << std::fixed << std::setprecision(15);
	std::cout << "--- float result ---" << std::endl;
	std::cout << "Числитель: " << f_1 << std::endl;
	std::cout << "Знаменатель " << f_2 << std::endl;
	std::cout << "result " << result_f << std::endl;

	std::cout << std::fixed << std::setprecision(7);
	std::cout << "--- double result ---" << std::endl;
	std::cout << "Числитель: " << d_1 << std::endl;
	std::cout << "Знаменатель " << d_2 << std::endl;
	std::cout << "result " << result_d << std::endl;

	return 0;
}
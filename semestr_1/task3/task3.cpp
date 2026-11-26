#include <iostream>
#include <clocale>

int main()
{
	std::setlocale(LC_ALL, "ru");

	int arr[10] = { 10, 20,31, 31, 31, 30, 20, -1, 10, 24 };

	bool f = false;
	int i = 0;

	while (i < 10 - 1 && !f)
	{
		if (arr[i] >= arr[i + 1])
			f = true;

		i++;
	}

	if (f == false)
		std::cout << "Массив упорядочен" << std::endl;
	else
		std::cout << "Массив НЕ упорядочен" << std::endl;

	return 0;
}
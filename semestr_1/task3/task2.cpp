#include <iostream>
#include <clocale>

int main()
{
	std::setlocale(LC_ALL, "ru");

	int arr[10] = { 10, 20,31, 31, 31, 30, 20, -1, 10, 24 };

	// max and min
	int max = arr[0];
	int count_max = 1;
	int idx_max = 0;
	int min = arr[0];
	int count_min = 1;
	int idx_min = 0;
	for (int i = 1; i < 10; i++)
	{
		//для max
		if (arr[i] > max)
		{
			max = arr[i];
			count_max = 1;
			idx_max = i;
		}
		else if (arr[i] == max)
			count_max += 1;

		//для min
		if (arr[i] < min)
		{
			min = arr[i];
			count_min = 1;
			idx_min = i;
		}
		else if (arr[i] == min)
			count_min += 1;
	}

	std::cout << "максимальный элемент = " << max << std::endl;
	std::cout << "номер = " << idx_max + 1 << "\tиндекс = " << idx_max << std::endl;
	if (count_max > 1)
		std::cout << "количество максимальных элементов = " << count_max << std::endl;

	std::cout << "\n\n";
	std::cout << "минимальный элемент = " << min << std::endl;
	std::cout << "номер = " << idx_min + 1 << "\tиндекс = " << idx_min << std::endl;
	if (count_min > 1)
		std::cout << "количество минимальных элементов = " << count_min << std::endl;

	return 0;
}
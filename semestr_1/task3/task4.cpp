#include <iostream>
#include <clocale>

int main()
{
	std::setlocale(LC_ALL, "ru");

	int arr[2][3] = { {3, 7, 100}, {6, 31, 99} };

	int max = arr[0][0];
	int max_row = 0;
	int max_col = 0;

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				max_row = i;
				max_col = j;
			}
		}
	}

	std::cout << "макс = " << max << "\nиндексы: [" << max_row << "," << max_col << "]" << std::endl;

	return 0;
}
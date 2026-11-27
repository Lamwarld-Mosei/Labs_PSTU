#include <iostream>
#include <clocale>

int main()
{
	setlocale(LC_ALL, "ru");

	const int ROWS = 2;
	const int COLS = 4;

	int arr[ROWS][COLS] = { {1000, 123, 444, -1233}, {12, 3, -44, 123445} };
	int col_max_width[COLS];

	// ищем максимальную длину числа для СТОЛБЦА
	for (int i = 0; i < COLS; i++)
	{
		int max_col_width = 0;

		for (int j = 0; j < ROWS; j++)
		{
			int width = 0;
			int value = arr[j][i];

			if (value < 0)
			{
				width += 1;
				value = -value;
			}

			while (value > 0)
			{
				width += 1;
				value /= 10;
			}

			if (width > max_col_width)
				max_col_width = width;
		}

		col_max_width[i] = max_col_width;
	}

	for (int i = 0; i < ROWS; i++)
	{
		int row_sum = 0;

		for (int j = 0; j < COLS; j++)
		{
			row_sum += arr[i][j];

			int current_width = 0;
			int value = arr[i][j];

			if (value < 0)
			{
				current_width += 1;
				value = -value;
			}

			while (value > 0)
			{
				current_width += 1;
				value /= 10;
			}

			// Выравнивание столбцов и вывод массива
			int spaces = col_max_width[j] - current_width + 1;
			for (int k = 0; k < spaces; k++)
			{
				std::cout << " ";
			}
			std::cout << arr[i][j];
		}

		std::cout << " . Сумма = " << row_sum << std::endl;
	}

	return 0;
}
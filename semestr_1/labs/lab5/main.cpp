#include <iostream>
#include <clocale>

void PrintArray(const int arr[], const int row, const int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			std::cout << arr[i][j] << "\t";
		}

		std::cout << "\n";
	}
}

int[] MatrixFolding(int arr[], const int row, const int col)
{
	int transposed_matrix[col][row];

	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
			transposed_matrix[i][j] = arr[j][i]
	}

	int matrix[row][col]; 

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			matrix[i][j] = transposed_matrix[i]
		}
	}

	return matrix;
}

int main()
{
	const int ROW = 4;
	const int COL = 4;

	int arr[ROW][COL] = { {3, 4, 1, 2}, {0, 2, 3, 100}, {1000, 2, 3, 0}, {10, 0, 0, -1000} };

	PrintArray(arr, ROW, COL);

	int folded_matrix = MatrixFolding(arr);
	PrintArray(arr, ROW, COL);

	return 0;
}
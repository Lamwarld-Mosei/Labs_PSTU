#include <iostream>
#include <clocale>

const int ROW = 4;
const int COL = 4;

void PrintArray(const int arr[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			std::cout << arr[i][j] << "\t";
		}

		std::cout << "\n";
	}
}

void TrasposeMatrix(const int arr[ROW][COL], int returning_matrix[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			returning_matrix[i][j] = arr[ROW - 1 - j][i];
		}
	}
}

void MatrixFolding(const int arr[ROW][COL], const int arr2[ROW][COL], int matrix[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			matrix[i][j] = arr[i][j] + arr2[i][j];
		}
	}
}

int main()
{
	int arr[ROW][COL] = { {3, 4, 1, 2}, {0, 2, 3, 100}, {1000, 2, 3, 0}, {10, 0, 0, -1000} };
	PrintArray(arr);
	std::cout << "\n\n";

	int transposed_matrix[ROW][COL];
	TrasposeMatrix(arr, transposed_matrix);
	PrintArray(transposed_matrix);
	std::cout << "\n\n";

	int matrix[ROW][COL];
	MatrixFolding(arr, transposed_matrix, matrix);
	PrintArray(matrix);

	return 0;
}
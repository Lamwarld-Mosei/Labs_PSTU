#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int arr[7] = { 5,3,-5, 1, 3, 6, 7 };
	int temp;

	for (int i = 0; i < 7; i++)
	{
		int minIndex = i;
		for (int j = i + 1; j < 7; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}


	cout << "Сортировка выбором" << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	return 0;
}
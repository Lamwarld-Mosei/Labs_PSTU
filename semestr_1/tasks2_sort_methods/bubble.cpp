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
		for (int j = 0; j < 7 - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << "Сортировка обмена (\"пузырьком\")" << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	return 0;
}
#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int arr[7] = { 5,3,-5, 1, 3, 6, 7 };

	for (int i = 1; i < 7; i++)
	{
		int curr = arr[i];
		int j = i - 1;

		while (j >= 0 && curr < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = curr;
	}

	cout << "Сортировка вставками" << endl;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";

	return 0;
}
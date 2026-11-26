#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	bool f = false;
	int a, b;

	cin >> a;

	if (a != 0)
	{
		cin >> b;

		while (b != 0 && !f == true)
		{
			if (b > a)
				a = b;
			else
				f = true;

			cin >> b;
		}

		if (f == true)
			cout << "Последовательность не отсортирована" << endl;
		else
			cout << "Последовательность отсортирована" << endl;
	}
	else
		cout << "Число a = 0" << endl;

	return 0;
}
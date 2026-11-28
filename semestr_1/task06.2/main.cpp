#include <iostream>
#include <string>
#include <clocale>

using namespace std;

struct Wages
{
public:
	string name;
	string last_name;
	string patronymic;
	int count_days = 0;
	int payment_per_day = 0;
	int prize = 0;

	int calculateWages()
	{
		return count_days * payment_per_day + prize;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");

	Wages man;

	cout << "Имя: ";
	cin >> man.name;

	cout << "Фамилие: ";
	cin >> man.last_name;

	cout << "Отчество: ";
	cin >> man.patronymic;

	cout << "Количество отработанных дней: ";
	cin >> man.count_days;

	cout << "Оплата за день: ";
	cin >> man.payment_per_day;

	cout << "Премия: ";
	cin >> man.prize;

	cout << "\nЗарплата: " << man.calculateWages();

	return 0;
}
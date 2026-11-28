#include <iostream>
using namespace std;

struct Advertising
{
public:
	int count_ads;
	int count_percent;
	int avarage_money_per_click;

	int multiple()
	{
		return count_ads * count_percent * avarage_money_per_click;
	}

private:
};

int main()
{
	setlocale(LC_ALL, "ru");

	Advertising adv;

	cout << "введите количество рекламы: ";
	cin >> adv.count_ads;

	cout << "введите количество процентов: ";
	cin >> adv.count_percent;

	cout << "введите количество дохода за клик: ";
	cin >> adv.avarage_money_per_click;

	cout << "доход: " << adv.multiple();

	return 0;
}
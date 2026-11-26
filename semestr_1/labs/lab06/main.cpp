#include <iostream>
#include <clocale>
#include <windows.h>

void Gets(char s[])
{
	std::cin.getline(s, 256);
}

bool HasVowels(char s[], const int start, const int end)
{
	for (int i = start; i < end; i++)
	{
		char c = s[i];

		if (c == 'у' || c == 'е' || c == 'ы' || c == 'а' || c == 'ё' ||
			c == 'о' || c == 'э' || c == 'я' || c == 'и' || c == 'ю' ||
			c == 'У' || c == 'Е' || c == 'Ы' || c == 'А' || c == 'О' ||
			c == 'Э' || c == 'Я' || c == 'И' || c == 'Ю' || c == 'Ё')
		{
			return true;
		}
	}

	return false;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::setlocale(LC_ALL, "Russian");

	char s[256];

	std::cout << "Введите текст: ";
	Gets(s);

	std::cout << "Слова без гласных: " << std::endl;

	int i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == ' ' || s[i] == ',')
			i++;

		int start = i;

		while (s[i] != ' ' && s[i] != '.' && s[i] != '\0' && s[i] != ',')
			i++;

		int end = i;

		if (start < end && !HasVowels(s, start, end))
		{
			for (int j = start; j < end; j++)
				std::cout << s[j];

			std::cout << std::endl;
		}

		if (s[i] == '.')
			break;
	}

	return 0;
}
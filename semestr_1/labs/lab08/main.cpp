#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <clocale>

using namespace std;


FILE* FL;
FILE* TEMP;


struct State
{
	char name[50];
	char capital[50];
	unsigned int population_size;
	unsigned short int area;
};


void deleteStates();
void printFile();
void createFile();
void inputStruct(State& state);
void addCountry();


int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setlocale(LC_ALL, ".UTF8");

	cout << "===== СОЗДАНИЕ ФАЙЛА =====\n";
	createFile();

	cout << "\n===== ИСХОДНЫЙ СПИСОК ГОСУДАРСТВ =====\n";
	printFile();

	cout << "\n===== УДАЛЕНИЕ ГОСУДАРСТВ =====\n";
	deleteStates();

	cout << "\n===== СПИСОК ПОСЛЕ УДАЛЕНИЯ =====\n";
	printFile();

	cout << "\n===== ДОБАВЛЕНИЕ ГОСУДАРСТВА =====\n";
	addCountry();

	cout << "\n===== СПИСОК ПОСЛЕ ДОБАВЛЕНИЯ =====\n";
	printFile();

	return 0;
}



void deleteStates()
{
	unsigned short int min_people_count = 0;
	cout << "Введите минимальную численность населения (в млн): ";
	cin >> min_people_count;

	FL = fopen("file.dat", "rb");
	TEMP = fopen("temp.dat", "wb");

	if (FL == NULL || TEMP == NULL)
	{
		perror("Ошибка открытия файла");

		if (FL != NULL)
			fclose(FL);
		if (TEMP != NULL)
			fclose(TEMP);

		return;
	}

	State state;

	while (fread(&state, sizeof(State), 1, FL) == 1)
	{
		if (state.population_size >= min_people_count)
		{
			if (fwrite(&state, sizeof(State), 1, TEMP) != 1)
			{
				cout << "Ошибка при записи в файл temp.dat";
				fclose(FL);
				fclose(TEMP);
				remove("temp.dat");

				return;
			}
		}
	}

	if (ferror(FL))
	{
		cout << "Ошибка чтения файла!\n";
		fclose(FL);
		fclose(TEMP);
		remove("temp.dat");
		return;
	}

	bool error = false;

	if (fclose(FL) != 0)
		error = true;

	if (fclose(TEMP) != 0)
		error = true;

	if (error)
	{
		cout << "Ошибка при обработке файлов\n";
		remove("temp.dat");
		return;
	}

	if (rename("file.dat", "backup.dat") != 0)
	{
		perror("Ошибка при создании резервной копии");
		return;
	}

	if (rename("temp.dat", "file.dat") != 0)
	{
		perror("Ошибка при переименовании файла");

		rename("backup.dat", "file.dat");

		return;
	}

	remove("backup.dat");

	cout << "Удаление успешно";
}



void printFile()
{
	if ((FL = fopen("file.dat", "rb")) == NULL)
	{
		perror("Ошибка открытия файла");
		return;
	}

	State state;
	unsigned short int i = 1;

	while (fread(&state, sizeof(State), 1, FL) == 1)
	{
		cout << "\nГосударство №" << i++ << '\n';
		cout << "Название государства: " << state.name << '\n';
		cout << "Столица: " << state.capital << '\n';
		cout << "Занимаемая площадь (в км2): " << state.area << '\n';
		cout << "Численность населения: " << state.population_size << '\n';
	}

	if (ferror(FL))
	{
		cout << "Произошла ошибка чтения файла!\n";
	}

	fclose(FL);
}



void createFile()
{
	if ((FL = fopen("file.dat", "wb")) == NULL)
	{
		perror("Ошибка открытия файла");
		return;
	}

	State state;

	for (size_t i = 0; i < 5; i++)
	{
		cout << "\nГосударство №" << i + 1 << '\n';

		inputStruct(state);

		if (fwrite(&state, sizeof(State), 1, FL) != 1)
		{
			cout << "Ошибка записи!" << '\n';
			fclose(FL);
			return;
		}
	}

	cout << "Файл создан!\n";

	fclose(FL);
}



void inputStruct(State& state)
{
	cout << "Название государства: ";
	cin >> state.name;

	cout << "Столица: ";
	cin >> state.capital;

	cout << "Занимаемая площадь (в км2): ";
	cin >> state.area;

	cout << "Численность населения: ";
	cin >> state.population_size;
}



void addCountry()
{
	unsigned int position = 0;
	cout << "Введите, после какого элемента добавить новое государство: ";
	cin >> position;

	if (position > 5)
	{
		cout << "Некоректное число!\n";
		return;
	}

	FL = fopen("file.dat", "rb");
	TEMP = fopen("temp.dat", "wb");

	if (FL == NULL || TEMP == NULL)
	{
		perror("Ошибка открытия файла");

		if (FL != NULL)
			fclose(FL);
		if (TEMP != NULL)
			fclose(TEMP);

		return;
	}

	State state;
	State newState;

	inputStruct(newState);

	unsigned int i = 0;
	bool error = false;

	while (fread(&state, sizeof(State), 1, FL) == 1)
	{
		if (i == position)
		{
			if (fwrite(&newState, sizeof(State), 1, TEMP) != 1)
			{
				error = true;
				break;
			}
		}

		if (fwrite(&state, sizeof(State), 1, TEMP) != 1)
		{
			error = true;
			break;
		}

		i++;
	}

	if (ferror(FL))
	{
		cout << "Ошибка чтения файла!\n";
		fclose(FL);
		fclose(TEMP);
		remove("temp.dat");
		return;
	}

	if (!error && i == position)
	{
		if (fwrite(&newState, sizeof(State), 1, TEMP) != 1)
		{
			error = true;
		}
	}

	if (fclose(FL) != 0)
		error = true;

	if (fclose(TEMP) != 0)
		error = true;

	if (error)
	{
		cout << "Ошибка при добавлении в файл!\n";
		remove("temp.dat");
		return;
	}

	if (rename("file.dat", "backup.dat") != 0)
	{
		perror("Ошибка при создании резервной копии");
		return;
	}

	if (rename("temp.dat", "file.dat") != 0)
	{
		perror("Ошибка при переименовании файла");

		rename("backup.dat", "file.dat");

		return;
	}

	remove("backup.dat");

	cout << "Добавление после " << position << " элемента успешно!";
}
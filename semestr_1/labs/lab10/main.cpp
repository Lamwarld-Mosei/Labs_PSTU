#include <iostream>
#include <clocale>
#include <ctime>
#include <cstdlib>


int* createArray(int size)
{
	int* array = new int[size];

	return array;
}


void deleteArray(int*& array)
{
	delete[] array;

	array = nullptr;
}


void fillArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		array[i] = rand() % 1000 - 500;
}


void printArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		std::cout << array[i] << " ";

	std::cout << '\n';
}


int* deleteElements(int* array, int number, int number_of_deleted, int& size)
{
	int old_size = size;
	size -= number_of_deleted;
	int* newArray = createArray(size);

	int j = 0;
	for (size_t i = 0; i < old_size; i++)
	{
		if (i >= number - 1 && i < number + number_of_deleted - 1)
			continue;

		newArray[j] = array[i];

		j++;
	}

	deleteArray(array);

	return newArray;
}


int* appendElement(int* array, int value, int& size)
{
	size++;
	int* newArray = createArray(size);

	for (size_t i = 0; i < size - 1; i++)
	{
		newArray[i] = array[i];
	}

	newArray[size - 1] = value;

	deleteArray(array);

	return newArray;
}


int main()
{
	std::setlocale(LC_ALL, "ru");
	srand(time(0));

	int size;
	std::cout << "Введите количество элементов в массиве: ";
	std::cin >> size;

	std::cout << "\n========МАССИВ СФОРМИРОВАН========" << '\n';
	int* array = createArray(size);

	std::cout << "\n========МАССИВ ЗАПОЛНЕН СЛУЧАЙНО========" << '\n';
	fillArray(array, size);

	std::cout << "\n========ВЫВОД МАССИВА========" << '\n';
	printArray(array, size);

	int number;
	std::cout << "Введите номер элемента, с которого хотите удалить элементы: ";
	std::cin >> number;

	int count_of_deleted_elements;
	std::cout << "Введите количество элементов, которые хотите удалить: ";
	std::cin >> count_of_deleted_elements;

	std::cout << "\n========ИЗ МАССИВА УДАЛИЛИ ЭЛЕМЕНТЫ========" << '\n';
	array = deleteElements(array, number, count_of_deleted_elements, size);

	std::cout << "\n========ВЫВОД МАССИВА========" << '\n';
	printArray(array, size);

	int value;
	std::cout << "Введите значение: ";
	std::cin >> value;

	std::cout << "\n========В МАССИВ ДОБАВЛЕН 1 ЭЛЕМЕНТ========" << '\n';
	array = appendElement(array, value, size);

	std::cout << "\n========ВЫВОД МАССИВА========" << '\n';
	printArray(array, size);

	return 0;
}
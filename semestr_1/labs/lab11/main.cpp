#include <iostream>
#include <clocale>
#include <fstream>

using namespace std;

struct Point
{
	int data;
	Point* p_next;
};

Point* Make_Point(int size)
{
	Point* first, * p;

	first = nullptr;

	for (int i = size; i > 0; i--)
	{
		p = new Point;
		p->data = i;
		p->p_next = first;
		first = p;
	}

	return first;
}

Point* Make_One_Point(int value)
{
	Point* point = new Point;
	point->data = value;
	point->p_next = nullptr;

	return point;
}

Point* Print_Point(Point* first)
{
	if (first == nullptr)
	{
		cout << "Список пуст!\n";
		return nullptr;
	}

	Point* p = first;

	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->p_next;
	}

	return first;
}

void Delete_Elements(Point*& first, int& size, int index, int K)
{
	Point* deleting_point = first;

	if (index == 0)
	{
		Point* temp = first->p_next;

		for (size_t i = 0; i < K; i++)
		{
			first = first->p_next;
		}

		for (size_t i = 0; i < K - 1; i++)
		{
			delete deleting_point;
			deleting_point = temp;
			temp = deleting_point->p_next;
		}

		delete deleting_point;
		size -= K;

		return;
	}

	Point* previous_point = first;

	for (size_t i = 1; i < index; i++)
	{
		previous_point = deleting_point;
		deleting_point = deleting_point->p_next;
	}

	Point* temp = deleting_point;

	for (size_t i = 0; i < K; i++)
	{
		deleting_point = temp;
		temp = deleting_point->p_next;
		delete deleting_point;
	}

	previous_point->p_next = temp;
	size -= K;
}

void Add_Element(Point*& first, int& size, int value)
{
	if (first == nullptr)
	{
		first = Make_One_Point(value);

		return;
	}

	Point* temp = first;

	while (temp->p_next != nullptr)
	{
		temp = temp->p_next;
	}

	Point* point = Make_Point(value);
	temp->p_next = point;
}

void Add_Element_By_Key(Point*& first, int& size, int key, int value)
{
	Point* temp = nullptr;
	Point* checking = first;

	if (checking->data == key)
	{
		Point* point = new Point;

		point->data = value;
		point->p_next = first;

		first = point;
		size++;

		return;
	}

	while (checking->data != key)
	{
		temp = checking;
		checking = checking->p_next;
	}

	Point* point = new Point;
	point->data = value;
	point->p_next = checking;

	temp->p_next = point;
	size++;
}

void Destroy_List(Point*& first, int& size)
{
	Point* temp = nullptr;

	for (size_t i = 0; i < size; i++)
	{
		temp = first;
		first = first->p_next;
		delete temp;
	}

	size = 0;
}

void Save_List(Point*& first)
{
	ofstream file("file.txt");

	Point* point = first;

	while (point != nullptr)
	{
		file << point->data << " ";
		point = point->p_next;
	}

	file.close();
}

Point* Read_List(int& size)
{
	ifstream file("file.txt");

	int data;
	size = 0;

	if (!(file >> data))
		return nullptr;

	Point* first = Make_One_Point(data);
	Point* last = first;
	size++;

	while (file >> data)
	{
		Point* point = Make_One_Point(data);

		last->p_next = point;
		last = point;

		size++;
	}

	return first;
}

int main()
{
	setlocale(LC_ALL, "ru");

	int size = 10;
	int i = 1;

	/*Создание пустого списка и добавление 1 элемента и его уничтожение*/
	Point* point = Make_Point(0);
	Print_Point(point);
	Add_Element(point, size, 5);
	cout << "Элементы после добавления в конец: ";
	Print_Point(point);
	Destroy_List(point, i);
	cout << "\n\n------------------------------\n\n";

	/*Создание списка из size элементов, удаление, добавление по ключу*/
	point = Make_Point(size);
	cout << "Элементы: ";
	Print_Point(point);

	cout << "\nЭлементы после удаления: ";
	Delete_Elements(point, size, 2, 3);
	Print_Point(point);

	cout << "\nЭлементы после добавления: ";
	Add_Element_By_Key(point, size, 8, 100);
	Print_Point(point);

	cout << "\nЗапись элементов и уничтожение списка!\n";
	Save_List(point);
	Destroy_List(point, size);
	Print_Point(point);

	cout << "\nВосстановление списка, вывод, уничтожение\n";
	point = Read_List(size);
	Print_Point(point);
	Destroy_List(point, size);

	return 0;
}
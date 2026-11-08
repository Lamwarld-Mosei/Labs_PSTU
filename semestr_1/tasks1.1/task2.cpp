#include <iostream>

int main()
{
	int size;
	std::cin >> size;

	for (int i = 0; i < size; i++)
	{
		std::cout << "*";

		for (int j = 1; j < size - 1; j++)
		{
			std::cout << (i == 0 || i == size - 1 ? '*' : ' ');
		}

		std::cout << "*" << std::endl;
	}

	return 0;
}	
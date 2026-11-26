#include <iostream>

int main()
{
	int a = 12;
	int* ptr = &a;
	int copy = *ptr;
	(*ptr)++;

	/* ptr хранит адрес переменной <a>, а <copy> - скопированное значение <a>, 
	после копирования между <copy> и <a> не остаётся связи, поэтому <a> = 13, <copy> = 12*/
	std::cout << "a = " << a << "\ncopy = " << copy;

	return 0;
}
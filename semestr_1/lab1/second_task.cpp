#include <iostream>

int main()
{
	int m = 10;
	int n = 5;

	int a = n-- - m;
	std::cout << "1) n---m\t" << a << std::endl;
	bool b = m-- < n;
	std::cout << "2) n--<m\t" << b << std::endl;
	bool c = n++ > m;
	std::cout << "3) n++>m\t" << c << std::endl;

	return 0;
}
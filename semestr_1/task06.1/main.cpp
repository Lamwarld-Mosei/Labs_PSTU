#include <iostream>

void hanoyTower(int N, char from, char to, char suppotive)
{
	if (N == 0)
		return;

	hanoyTower(N - 1, from, suppotive, to);
	std::cout << from << " -> " << to << "  " << N << '\n';
	hanoyTower(N - 1, suppotive, to, from);
}

int main()
{
	hanoyTower(3, 'A', 'C', 'B');

	return 0;
}
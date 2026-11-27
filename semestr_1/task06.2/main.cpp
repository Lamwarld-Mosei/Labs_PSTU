#include <iostream>
#include <vector>
#include <cstdlib>

bool FLAG = true;

bool isTwoChessAttackEachOther(int r1, int c1, int r2, int c2);
bool isUnderAttack(const std::vector<int>& array, int current_queen_row, int possible_column_index);
int findCountSolutions(std::vector<int>& pos, int row = 0);
void printQueensPermutation(std::vector<int>& pos);


bool isTwoChessAttackEachOther(int r1, int c1, int r2, int c2)
{
	int expression = std::abs(r2 - r1);

	return (c1 == c2 || r1 == r2 || c2 - expression == c1 || c2 + expression == c1);
}


bool isUnderAttack(const std::vector<int>& pos, int current_row, int possible_column_index)
{
	for (int i = 0; i < current_row; i++)
	{
		if (isTwoChessAttackEachOther(i, pos.at(i), current_row, possible_column_index))
		{
			return true;
		}
	}

	return false;
}


void printQueensPermutation(std::vector<int>& pos)
{
	for (size_t i = 0; i < pos.size(); i++)
	{
		for (size_t j = 0; j < pos.size(); j++)
		{
			if (pos[i] == j)
			{
				std::cout << "!";
			}
			else
			{
				std::cout << "#";
			}
		}

		std::cout << '\n';
	}
}


int findCountSolutions(std::vector<int>& pos, int row)
{
	if (row == pos.size())
	{
		if (FLAG)
		{
			FLAG = false;
			printQueensPermutation(pos);
		}

		return 1;
	}

	int summa = 0;

	for (int c = 0; c < pos.size(); c++)
	{
		if (!isUnderAttack(pos, row, c))
		{
			pos[row] = c;
			summa += findCountSolutions(pos, row + 1);
		}
	}

	return summa;
}


int main()
{
	std::vector<int> pos(8);

	std::cout << findCountSolutions(pos);
}
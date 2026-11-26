#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double CalculateSN(float x, int n)
{
	double SN = x;
	double term = x;

	for (int i = 1; i <= n; i++)
	{
		term *= -(x * x) / ((2.0 * i) * (2.0 * i + 1.0));
		SN += term;
	}

	return SN;
}

double CalculateSE(float x, double E)
{
	cout << fixed << setprecision(10);

	double SE = x;
	double term = x;
	int i = 1;

	while (abs(term) > E)
	{
		term *= -(x * x) / ((2.0 * i) * (2.0 * i + 1.0));
		SE += term;
		i++;
	}

	return SE;
}


int main()
{
	float a = 0.1f;
	float b = 1.0f;
	float k = 10.0f;

	for (float x = a; x <= b; x += (b - a) / k)
	{
		cout << "X = " << x << "\t";
		cout << "SN = " << CalculateSN(x, 10) << "\t";
		cout << "SE = " << CalculateSE(x, 0.0001) << "\t";
		cout << "Y = " << sin(x) << "\t" << endl;
	}

	return 0;
}

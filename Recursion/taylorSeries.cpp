#include <bits/stdc++.h>
using namespace std;
//normal recursion
double taylor(double x, double n)
{
	static double p = 1, f = 1;

	if (n == 0)
		return 1;
	double val = taylor(x, n - 1);
	p = p * x;
	f = f * n;
	return val + (p / f);
}
//normal loop

double taylorLoop(double x, double n)
{
	double s = 1;
	double p = 1;
	double f = 1;
	for (int i = 1; i <= n; i++)
	{
		p *= x;
		f *= i;
		s += p / f;
	}
	return s;
}

//efficient recursion
double taylorEfficient(double x, double n)
{
	static double s = 1;
	if (n == 0)
		return s;
	s = 1 + ((x / n) * s);
	return taylorEfficient(x, n - 1);
}

//efficient loop

double exponential(double x, double n)
{
	double sum = 1; // initialize sum of series

	for (int i = n - 1; i > 0; --i )
		sum = 1 + x * sum / i;

	return sum;
}


int main()
{
	int n = 10;
	//taylor(x,n);
	double ans1 = taylor(3, 100);
	cout << ans1 << endl;
	double ans4 = taylorLoop(3, 100);
	cout << ans4 << endl;

	double ans2 = taylorEfficient(3, 100);
	cout << ans2 << endl;

	double ans3 = exponential(3, 100);
	cout << ans3 << endl;

}


#include <bits/stdc++.h>
using namespace std;

//memorization process is storing the value of function call to use again

int ara[100000];

int fibo(int n)
{
	if (n <= 1)
	{
		ara[n] = n;
		return ara[n];
	}
	if (ara[n - 2] == -1)
	{
		ara[n - 2] = fibo(n - 2);
	}
	if (ara[n - 1] == -1)
	{
		ara[n - 1] = fibo(n - 1);
	}
	return ara[n - 2] + ara[n - 1];
}


int main()
{
	memset(ara, -1, sizeof(ara));
	cout << fibo(6) << endl;
}
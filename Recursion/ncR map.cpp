#include <bits/stdc++.h>
using namespace std;

//memorization process is storing the value of function call to use again
//though memorization is not necessary here, but if one needs to calaculate many nCr with a while
//loop,then it is good
map< pair<int, int>>, int > ara;


int nCr(int n, int r)
{
	if (r == 0 || n == r) {
		ara[ {n, r}] = 1;
		return ara[ {n, r}];
	}
	if (ara[ {n - 1, r - 1}] == 0)
	{
		ara[ {n - 1, r - 1}] = nCr(n - 1, r - 1);
	}
	if (ara[ {n - 1, r}] == 0)
	{
		ara[ {n - 1, r}] = nCr(n - 1, r);
	}
	return ara[ {n - 1, r - 1}] + ara[ {n - 1, r}];
}



int main()
{
	cout << nCr(10, 6) << endl;
}
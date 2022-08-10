#include <bits/stdc++.h>
using namespace std;

//time consuming
//time O(n)
//space O(n)
int power1(int m, int n)
{
	if (n == 0)
		return 1;
	return power1(m, n - 1) * m;
}

//efficient
int power2(int m, int n)
{
	if (n == 0)
		return 1;
	if (n % 2 == 0)
		return power2(m * m, n / 2);
	else
		return m * power2(m * m, (n - 1) / 2);
}


int main()
{
	int n = 10;
	int ans = power1(3, 9);
	cout << ans << endl;
	ans = power2(2, 3);
	cout << ans << endl;
	//pow always returns double, not safe to use


	// pow(2,3);
	cout << (1LL << 3) << endl;
	int ara[3] = { -1,0,1 };
	if (ara[0])
		cout << "hi" << endl;
}


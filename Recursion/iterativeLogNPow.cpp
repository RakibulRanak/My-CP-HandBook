#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

//steinums mod

int Pow(int a, int b) {
	int r = 1; while (b) {
		if (b & 1)r = 1LL * r * a % mod;
		a = 1LL * a * a % mod;
		b >>= 1;
	} return r;
}

int main()
{
	cout << Pow(2, 3) << endl;
}
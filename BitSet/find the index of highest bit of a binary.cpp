#include<bits/stdc++.h>
using namespace std;
#define ll long long
//https://codeforces.com/contest/1420/problem/B
//my func
int fi(ll a) {
	for (ll i = 31; i >= 0; i--) {
		//cout << (1LL << i) << endl;
		if (a & (1LL << i))return i;
	} return -1;
}
//8 =28(0)1000 ->index 3 is the 1st one counted from right to left (0 based index)
int main()
{
	int t;
	cin >> t;
	while (t--) {
		ll a;
		cin >> a;
		int k = fi(a);
		cout << k << endl;
		//built in
		cout << 31 - __builtin_clz(a) << endl;
	}
	return 0;
}

//steinums hash
// https://www.spoj.com/problems/ADACLEAN/
#include <bits/stdc++.h>
using namespace std;
#define lll __int128
#define ll long long
#define endl '\n'
const ll mod = 11111111111111111LL, base = 111;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		string s;
		cin >> n >> m >> s;
		unordered_set<ll> exist;
		ll b = 1, h = 0;
		for (int i = 0, j = m - 1; j < n; i++, j++)
		{
			if (i == 0)
			{
				for (int k = 0; k < m; k++)
				{
					h = ((lll)h * base + s[k]) % mod;
					b = ((lll)b * base) % mod;
				}
			}
			else
			{
				h = ((lll)h * base + s[j]) % mod;
				h = (h - (lll)b * s[i - 1]) % mod;
				if (h < 0)
					h += mod;
			}
			exist.insert(h);
		}
		cout << exist.size() << endl;
	}

}
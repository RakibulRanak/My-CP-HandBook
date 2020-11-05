#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
vector<int>coins;

//recursive by memorization
//just give the result

int value1[1000001];

int solve1(int x)
{
	if (x < 0) return INF;
	else if (x == 0)return 0;
	else if (value1[x])return value1 [x];

	int best = INF;
	for (auto c : coins)
	{

		best = min(best, solve1(x - c) + 1);
	}
	value1[x] = best;
	return best;
}

int value2[1000001];
int main()
{
	//target value
	int n;
	cin >> n;
	int totalcoins;
	cin >> totalcoins;
	for (int i = 0; i < totalcoins; i++)
	{
		int temp;
		cin >> temp;
		coins.push_back(temp);
	}
	//recursive
	int ans1 = solve1 (n);
	cout << ans1 << endl;
	//iterative
	// give both result and the solution
	int sol[n + 1];
	for (int x = 1; x <= n; x++)
	{
		value2[x] = INF;
		for (auto c : coins)
		{
			if (x - c >= 0 && value2[x - c] + 1 < value2[x])
			{
				value2[x] = value2[x - c] + 1;
				sol[x] = c;

			}
		}
	}
	cout << value2[n] << endl;
	while (n > 0)
	{
		cout << sol[n] << " ";
		n -= sol[n];
	}
	cout << endl;

	//both solutions time coplexity is O(n*totalcoins)

	/* for limited use of one coin, we can have a map and decrease it
	whenever we use that specific coin . If m[coin[i]]==0 , skip it*/
}
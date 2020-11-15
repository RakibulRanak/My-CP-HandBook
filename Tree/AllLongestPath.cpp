//https://www.youtube.com/watch?v=Xng1Od_v6Ug (THANKS)
//heights of all nodes in a tree
/*
6
1 2
1 3
1 4
2 5
2 6

*/
#include <bits/stdc++.h>
using namespace std;
#define N 100001
vector<int> tree[N];
int in[N], out[N], dp[N];


void dfs1(int src, int par)
{
	for (int child : tree[src])
	{
		if (child != par)
		{
			dfs1(child, src);
			in[src] = max(in[src], 1 + in[child]);
		}
	}
}

void dfs2(int src, int par) {
	int mx1 = -1, mx2 = -1;

	//find top 2 maximum values of in[v]
	for (int child : tree[src]) {
		if (child == par) continue;
		if (in[child] >= mx1) mx2 = mx1, mx1 = in[child];
		else if (in[child] > mx2) mx2 = in[child];
	}
	for (int child : tree[src]) {
		if (child == par) continue;
		int use = mx1;

		if (mx1 == in[child])
			use = mx2;

		out[child] = max(1 + out[src], 2 + use);

		dfs2(child, src);
	}
}


int main()
{
	int n;
	cin >> n;
	//n-1 edges when n is node, in tree
	for (int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	dfs1(1, 0);
	dfs2(1, 0);

	for (int i = 1; i <= n; i++) {
		dp[i] = max(in[i], out[i]);
		cout << dp[i] << " " ;
	}

	return 0;
}


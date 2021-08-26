#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
vector<vector<int>>vec;
vector<int> visited;

void dfs(int u) {
	cout << u << '\n';
	visited[u] = 1;
	for (auto v : vec[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vec.resize(n + 1);
	visited.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs(1);
	vec.clear();
	visited.clear();
}

int main() {
	FastIO;
	solve();

	return 0;
}
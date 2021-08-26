// https://codeforces.com/contest/1559/problem/D1
#include<bits/stdc++.h>
using namespace std;

struct dsu {
	vector<int> par;
	dsu(int n) {
		par.resize(n);
		for (int i = 0; i < n; i++) {
			par[i] = i;
		}
	}
	int find(int u) {return par[u] = u == par[u] ? u : find(par[u]);}
	void merge(int u, int v) {par[find(u)] = find(v);}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int n, p, q; cin >> n >> p >> q;
	dsu a(n + 1), b(n + 1);
	while (p--) {
		int u, v; cin >> u >> v;
		a.merge(u, v);
	}
	while (q--) {
		int u, v; cin >> u >> v;
		b.merge(u, v);
	}
	vector<pair<int, int>> v;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a.find(i) != a.find(j) && b.find(i) != b.find(j)) {
				a.merge(i, j);
				b.merge(i, j);
				v.push_back({i, j});
			}
		}
	}
	cout << v.size() << '\n';
	for (auto [x, y] : v) {
		cout << x << ' ' << y << '\n';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);




void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>vec(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	stack<int> q;
	q.push(1);
	vector<int>visited(n + 1, 0);
	// memset(visited, 0, sizeof(visited));
	visited[1] = 1;
	while (!q.empty()) {

		int f = q.top();
		cout << f << '\n';
		q.pop();
		for (auto x : vec[f]) {
			if (!visited[x]) {
				q.push(x);
				visited[x] = 1;
			}
		}
		// for (int i = 0; i < vec[f].size(); i++) {
		// 	if (!visited[vec[f][i]]) {

		// 		q.push(vec[f][i]);
		// 		visited[vec[f][i]] = 1;
		// 	}
		// }
	}


}

int main() {
	FastIO; ll t;
	//  cin >> t;

	// for (ll i = 0; i < t; i++)
	solve();

	return 0;
}
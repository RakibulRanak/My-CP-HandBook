#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);




void solve(ll cs) {
	int n;
	cin >> n ;
	vector<vector<int>>vec(n + 1);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	int visited[n + 1];
	memset(visited, 0, sizeof(visited));
	visited[1] = 1;
	map<int, int>parent;
	parent[1] = 0;
	while (!q.empty()) {

		int f = q.front();
		q.pop();
		for (int i = 0; i < vec[f].size(); i++) {
			if (!visited[vec[f][i]]) {

				q.push(vec[f][i]);
				visited[vec[f][i]] = 1;
			}
		}
	}


}

int main() {
	FastIO; ll t; cin >> t;

	for (ll i = 0; i < t; i++) solve(i + 1);

	return 0;
}
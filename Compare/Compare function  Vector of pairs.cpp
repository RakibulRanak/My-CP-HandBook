#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<long double, ll>  pi;


//compare vector of pairs 1st value descending second value ascending
bool Compare(pi p1, pi p2) {
	return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
};


void solve() {
	int n;
	cin >> n;
	vector<pair<ll, ll>>vec1;
	vector<pair< long double, ll>>vec2;
	pair<ll, ll>p;

	for (ll i = 0; i < n; i++)
	{
		ll a, b;
		cin >> a >> b;
		vec1.push_back({a, b});
		vec2.push_back({(long double)a / (long double) b, i});

	}
	sort(vec2.begin(), vec2.end(), Compare);
	for (int i = 0; i < n; i++)
	{
		ll x = vec2[i].second;
		//cout << vec2[i].first << endl;
		p = vec1[x];
		cout << p.first << " " << p.second << endl;
	}
}

int main() {
	FastIO; solve();
	return 0;
}
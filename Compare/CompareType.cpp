#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef pair<int , pair<int, int> > pi;

//somehow this is totally ulta
//priority queue of pair of pairs ; [a1,(b1,c1)],  [a2,(b2,c2)]
//a is descending , then b is ascending

struct Compare {
	bool operator()(pi const & a, pi const & b)
	{
		return a.first < b.first || (a.first == b.first && a.second.first > b.second.first);
	}

};


void solve(ll cs) {

	int n;
	cin >> n;
	//priority_queue < pi, vector<pi>, greater < pi > > pq;
	priority_queue < pi , vector<pi> ,
	               Compare> pq;

}

int main() {
	FastIO; ll t; cin >> t;

	for (ll i = 0; i < t; i++) solve(i + 1);

	return 0;
}

//https://codeforces.com/contest/1353/submission/80156526
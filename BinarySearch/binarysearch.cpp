#include<bits/stdc++.h>
using namespace std;

int ara[] = {1, 11, 13, 19, 100, 167};

int binarySearch(int x) {
	int n = sizeof(ara) / sizeof(ara[0]);
	int l = 0, r = n - 1, an = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ara[mid] >= x) {
			an = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	return an;
}


void solve() {
	//lowest index of such element that greater than or equal to x (lower_bound);
	int an =  binarySearch(20);
	int n = sizeof(ara) / sizeof(ara[0]);
	if (n == an)
		cout << "Not found!" << endl;
	else
		cout << ara[an] << endl;
	cout << ((an =  binarySearch(20)) == n ? "Not found!" : to_string(ara[an])) << endl;
}

int main() {
	solve();
https://www.facebook.com/st3inums
	return 0;
}
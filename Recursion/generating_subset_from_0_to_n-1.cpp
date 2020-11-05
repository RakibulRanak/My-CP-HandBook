#include <bits/stdc++.h>
using namespace std;

//bitwise
void way1(int n)
{
	//b= 0->2^n -1
	// (1<<i) = 2^i
	for (int b = 0; b < (1 << n); b++) {
		//starting of a subset
		for (int i = 0; i < n; i++) {
			if (b & (1 << i)) {
				cout << i << " ";
			}
		}
		cout << endl;
	}
}
//recursion

vector<int>subset;

void way2(int k, int n) {
	if (k == n) {
		// process subset
		for (int i = 0; i < subset.size(); i++)
		{
			cout << subset[i] << " ";
		}
		cout << endl;
	}
	else {
		way2(k + 1, n);
		subset.push_back(k);
		way2(k + 1, n);
		subset.pop_back();
	}
}



int main()
{
	int n;
	cin >> n;
	cout << "bitwise" << endl;
	way1(n);
	cout << "recursion" << endl;
	way2(0, n);
	return 0;
}
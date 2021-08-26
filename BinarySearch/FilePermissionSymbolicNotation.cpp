#include <bits/stdc++.h>
using namespace std;

int decodeSymbolicNotation(string notation) {
	map<char, int>mapping;
	mapping['r'] = 4;
	mapping['w'] = 2;
	mapping['x'] = 1;
	mapping['-'] = 0;
	if (notation.size() != 9) {
		return -1;
	}
	int sum = 0;
	for (int i = 0; i < 9; i += 3) {
		int blocksum = 0;
		for (int j = i; j < i + 3; j++) {
			blocksum += mapping[notation[j]];
		}
		sum = (sum * 10) + blocksum;
	}
	return sum;
}

int main()
{
	string input;
	cin >> input;
	int ans = decodeSymbolicNotation(input);
	if (ans == -1) {
		cout << "Not Valid Command!!";
	} else {
		cout << ans << endl;
	}
}
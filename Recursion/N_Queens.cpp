/*calculating the number of ways n queens can be placed on an n × n chessboard so that no two
queens attack each other*/

#include <bits/stdc++.h>
using namespace std;


int column[1000];
int diag1[1000];
int diag2[1000];
int total;
int n;

//column size would be n,diag1=diag2=2n-1

void search(int y) {
	if (y == n) {
		total++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (column[x] || diag1[x + y] || diag2[x - y + n - 1]) continue;
		column[x] = diag1[x + y] = diag2[x - y + n - 1] = 1;
		search(y + 1);
		column[x] = diag1[x + y] = diag2[x - y + n - 1] = 0;
	}
}

int main()
{
	n = 4;

	search(0);

	cout << total << endl;
	return 0;
}
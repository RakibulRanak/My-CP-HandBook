#include <bits/stdc++.h>
using namespace std;
int L[5001][5001];

string lcs(string X, string Y, int m, int n )
{

	int i, j;
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
	i = m;
	j = n;
	string mylcs = "";
	while (L[i][j] != 0)
	{
		if (X[i - 1] == Y[j - 1])
		{
			mylcs = X[i - 1] + mylcs;
			i--;
			j--;

		}
		else
		{
			if (L[i - 1][j] > L[i][j - 1])
				i--;
			else if (L[i - 1][j] < L[i][j - 1])
				j--;
			else
			{
				if (i >= j)
					j--;
				else
					i--;
			}
		}
	}
	//cout << mylcs << endl;
	return mylcs ;
}



int main() {
	int x, y;
	cin >> x >> y;
	string s1, s2;
	cin >> s1 >> s2;
	string mylcs = lcs(s1, s2, x, y);
	cout << mylcs << " " << mylcs.size() << endl;
	return 0;
}
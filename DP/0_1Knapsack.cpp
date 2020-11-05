// A Dynamic and Iterative Programming based
//https://www.youtube.com/watch?v=8LusJS5-AGo
#include <bits/stdc++.h>
using namespace std;

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack1(int W, int wt[], int val[], int n)
{

	int K[n + 1][W + 1];

	// Build table K[products][1 to n weight] in bottom up manner
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (wt[i - 1] <= w)
				K[i][w] = max(
				              val[i - 1] + K[i - 1][w - wt[i - 1]],
				              K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}

	return K[n][W];
}
/* as we always need only two rows we can use them by turn for space optimization
but this only gives us the result,not the full soltion ,ex knapsack2 */

int knapSack2(int W, int wt[], int val[], int n)
{

	int K[2][W + 1];
	memset(K, 0, sizeof(K));

	// Build table K[products][1 to n weight] in bottom up manner
	int i = 0;
	while (i <= n)
	{
		if (i % 2 == 0)
		{
			//work with 2nd row
			int w = 1;
			while (w <= W)
			{
				if (wt[i - 1] <= w)
					K[1][w] = max(
					              val[i - 1] + K[0][w - wt[i - 1]],
					              K[0][w]);
				else
					K[1][w] = K[0][w];

				w++;
			}
		}
		else
		{
			int w = 1;
			while (w <= W)
			{
				if (wt[i - 1] <= w)
					K[0][w] = max(
					              val[i - 1] + K[1][w - wt[i - 1]],
					              K[1][w]);
				else
					K[0][w] = K[1][w];

				w++;
			}
		}
		i++;
	}
	if (i % 2 == 0)
		return K[0][W];
	else
		return K[1][W];
}

int main()
{
	int val[] = { 60, 100, 120 };
	int wt[] = { 10, 20, 30 };
	int W = 50;
	int n = sizeof(val) / sizeof(val[0]);
	cout << knapSack1(W, wt, val, n) << endl;
	cout << knapSack2(W, wt, val, n) << endl;
	return 0;
}

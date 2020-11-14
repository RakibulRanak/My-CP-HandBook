#include <bits/stdc++.h>
using namespace std;
#define INF 100
//INF should be modified according to needs

int main()
{
	int node, edge, cost;
	cin >> node >> edge;
	//adjacency matrics
	int distance[node + 1][node + 1];
	for (int i = 1; i <= node; i++)
	{
		for (int j = 1; j <= node; j++)
		{
			if (i == j)
				distance[i][j] = 0;
			else
				distance[i][j] = INF;
		}

	}

	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to >> cost;
		distance[from][to] = cost;
	}
	for (int k = 1; k <= node; k++)
	{
		for (int i = 1; i <= node; i++)
		{
			for (int j = 1; j <= node; j++)
				distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
		}
	}

	cout << distance[1][5]  << endl;

	return 0;

}
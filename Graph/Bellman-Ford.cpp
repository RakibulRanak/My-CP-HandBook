#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
//INF should be modified according to needs

int main()
{
	int node, edge, cost;
	cin >> node >> edge;
	//for storinng {from,to,cost}
	vector<tuple<int, int, int>>edges;
	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to >> cost;
		edges.push_back({from, to, cost});
	}
	int distance[node + 1];
	for (int i = 1; i <= node; i++)
	{
		distance[i] = INF;
	}
	//we by default start from index 1, distance is zero
	distance[1] = 0;
	map<int, int>parent;
	parent[1] = -1;
	for (int i = 1; i < node; i++)
	{
		bool flag = true;
		for (auto e : edges)
		{
			int from, to, cost;
			tie(from, to, cost) = e;
			if (distance[from] + cost < distance[to])
			{
				distance[to] = distance[from] + cost;
				parent[to] = from;
				flag = false;
			}
		}
		//if no node's distance is changed , break the loop
		if (flag)
			break;

	}
	vector<int>path;
	int end = node; //just assume
	cout << distance[end] << endl;
	path.push_back(end);
	while (parent[end] != -1)
	{
		end = parent[end];
		path.push_back(end);
	}
	for (int i = path.size() - 1; i >= 0; i--)
		cout << path[i] << " ";
	cout << endl;
	return 0;

}
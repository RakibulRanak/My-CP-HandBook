#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
//INF should be modified according to needs

int main()
{
	int node, edge, cost;
	cin >> node >> edge;
	//for storinng node>(node,cost)
	vector<pair<int, int>>vec[node + 1];
	for (int i = 0; i < edge; i++)
	{
		int from, to;
		cin >> from >> to >> cost;
		vec[from].push_back({to, cost});
	}

	map<int, int>visited;
	int distance[node + 1];
	for (int i = 1; i <= node; i++)
	{
		distance[i] = INF;
	}
	priority_queue<pair<int, int>>q;
	//queue of {distance,node} pair
	//we by default start from index 1, distance is zero
	distance[1] = 0;
	q.push({0, 1});
	map<int, int>parent;
	parent[1] = -1;
	while (!q.empty())
	{
		int top = q.top().second;
		q.pop();
		if (!visited[top])
		{
			visited[top] = 1;
			for (auto u : vec[top])
			{
				int to = u.first, cost = u.second;
				if (distance[top] + cost < distance[to])
				{
					distance[to] = distance[top] + cost;
					/*as priority queue by default stores descending, we are storing as
					 negative as we need ascending in dijkstra,it is just used to select
					 the less weighted node first , by the algorithm rule
					*/
					q.push({ -distance[to], to});
					parent[to] = top;
				}
			}
		}
	}
	vector<int>path;
	int end = node; //just assume
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
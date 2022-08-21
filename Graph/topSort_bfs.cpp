#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/course-schedule-ii/
// top sort bfs by Kahn's Algorithm

vector<int>myGraph[3];
vector<int>ans;

bool topSort(vector<int> myGraph[], vector<int>& degree, int nodes)
{
    queue<int> q;
    for (int i = 0; i < nodes; i++)
        if (degree[i] == 0) q.push(i);
    while (!q.empty()) {
        int curr = q.front(); q.pop(); nodes--;
        ans.push_back(curr);
        for (auto next : myGraph[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return nodes == 0;
}

int main()
{

    //next 2 lines are inputs
    vector<vector<int>> prerequisites{ {0,1},{1,2},{0,2} };
    int subjects = 3;

    vector<int> degree(subjects, 0);
    //creating graph from inputs
    for (auto x : prerequisites) {
        myGraph[x[1]].push_back(x[0]);
        degree[x[0]]++;
    }
    if (topSort(myGraph, degree, subjects))
    {
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "Not possible!" << endl;

}

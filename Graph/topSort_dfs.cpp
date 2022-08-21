#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/course-schedule-ii/
// top sort dfs by Cormen

vector<int>myGraph[3];
vector<int>ans;

bool isCycle(int node, unordered_map<int, int>& vis)
{
    vis[node] = 1;
    for (int i = 0; i < myGraph[node].size(); i++)
    {
        int dep = myGraph[node][i];
        if (vis[dep] == 0 && isCycle(dep, vis))
            return true;
        if (vis[dep] == 1)
            return true;
    }
    vis[node] = 2;
    ans.push_back(node);
    return false;
}

bool topSort(vector<int> myGraph[], unordered_map<int, int>& vis, int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        if (vis[i] == 0) {
            if (isCycle(i, vis))
                return false;
        }
    }
    return true;
}

int main()
{

    //next 2 lines are inputs
    vector<vector<int>> prerequisites{ {0,1},{1,2},{0,2} };
    int subjects = 3;

    //creating graph from inputs
    for (auto x : prerequisites)
        myGraph[x[1]].push_back(x[0]);
    unordered_map<int, int>vis;
    if (topSort(myGraph, vis, subjects))
    {
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    else
        cout << "Not possible!" << endl;

}
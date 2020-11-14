//thanks to https://www.youtube.com/watch?v=qNObsKl0GGY
#include<bits/stdc++.h>
using namespace std;

vector<int> tree[200001];
//diameter[i] : what is diameter if path pass through node i
int diameter[200001];
//downPath[i] : longest simple path in subtree rooted at i that starts at i
int downPath[200001];

void eval_downPaths(int src, int par)
{
    int bestChildDownPath = 0;
    bool leaf = 1;
    for (int child : tree[src])
    {
        if (child != par)
        {
            leaf = 0;
            eval_downPaths(child, src);
            bestChildDownPath = max(bestChildDownPath, downPath[child]);
        }
    }
    if (leaf)downPath[src] = 0;
    else downPath[src] = 1 + bestChildDownPath;
}

void solve(int src, int par)
{
    int ans = 0;
    int childrenDownPathsMax = 0, childrenDownPaths2ndMax = 0;
    int numOfchildren = 0;
    for (int child : tree[src])
    {
        if (child != par)
        {
            solve(child, src);
            if (downPath[child] >= childrenDownPathsMax)
            {
                childrenDownPaths2ndMax = childrenDownPathsMax;
                childrenDownPathsMax = downPath[child];
            }
            else if (downPath[child] > childrenDownPaths2ndMax)
            {
                childrenDownPaths2ndMax = downPath[child];
            }
            numOfchildren++;
            ans = max(ans, diameter[child]); //ans stores the best diameters of the childs
        }
    }
    //if diameter includes the src
    if (numOfchildren == 0)diameter[src] = 0;
    else if (numOfchildren == 1)diameter[src] = 1 + childrenDownPathsMax;
    else diameter[src] = 2 + childrenDownPathsMax + childrenDownPaths2ndMax;
    //if diameter doesn't include the source,ans has the best diameters of the cilds of src
    diameter[src] = max(diameter[src], ans);
}

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    eval_downPaths(1, 0);
    solve(1, 0);
    cout << diameter[1];

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int r = 10, c = 5;
    int ara[r][c] = { };
    cout << ara[0][1] << endl;
    // only 0 or -1
    memset(ara, -1, sizeof(ara[0][0]) * r * c);
    cout << ara[0][2] << endl;

    fill(ara[0], ara[0] + r * c, 10);
    cout << ara[0][1] << endl;
    //fill with a value after initialization


    /// for 1 d
    int n = 10;
    int ara2[n] = {};
    cout << ara2[1] << endl;
    memset(ara2, -1, sizeof(ara2));
    cout << ara2[1] << endl;
    fill(ara2, ara2 + n, 1212);
    cout << ara2[1];



}
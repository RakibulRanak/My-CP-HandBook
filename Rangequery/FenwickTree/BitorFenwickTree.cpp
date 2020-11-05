
#include <bits/stdc++.h>
using namespace std;

#define mx 10000
int ar[mx];
int tree[mx];

int read(int idx1, int idx2) {
    int sum = 0;
    while (idx2 > 0) {
        sum += tree[idx2];
        idx2 -= (idx2 & -idx2);
    }
    idx1--;
    while (idx1 > 0) {
        sum -= tree[idx1];
        idx1 -= (idx1 & -idx1);
    }
    return sum;
}

void update(int idx, int val, int n) {
    while (idx <= n) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

void print(int *ar, int n) {
    for (int i = 1; i <= n; ++i) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 10;
    int ar[n + 1] = {0, 1, 4, 2, 6, 4, 90, 98, 64, 35, 2};
    for (int i = 1; i <= n; ++i)
        update(i, ar[i], n);

    print(ar, n);
    // cout << "tree array:\t";
    // print(tree, n);
    cout << read(2, 4) << endl;
    //increase 7 at index 3
    update(3, 7, n);
    //for the exact update(not increase) we have to customize
    cout << read(2, 4) << endl;



    return 0;
}
//A simple segment tree for returning sum of a range and updating one index at a time
//http://www.shafaetsplanet.com/?p=1557

#include <bits/stdc++.h>
using namespace std;
#define n 8 //0 index faka

int ara[n] = {0, 1, 2, 3, 4, 5, 6, 7};
int tree[n * 3]; //my idea is 2*n-1

void init(int node, int b, int e)
{
	if (b == e)
	{
		tree[node] = ara[b];
		return;
	}
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;
	init(left, b, mid);
	init(right, mid + 1, e);
	tree[node] = tree[left] + tree[right];

}

int query(int node, int b, int e , int i , int j)
{
	if (i > e || j < b)
		return 0; //বাইরে চলে গিয়েছে
	else if (b >= i && e <= j)
		return tree[node];  //রিলেভেন্ট সেগমেন্ট
	//আরো ভাঙতে হবে
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;

	int p1 = query(left, b, mid, i, j);
	int p2 = query(right, mid + 1, e, i, j);
	return p1 + p2;  //বাম এবং ডান পাশের যোগফল
}

void update(int node, int b, int e, int i, int newvalue)
{
	if (i > e || i < b)
		return;   //বাইরে চলে গিয়েছে
	else if (b >= i && e <= i) {
		tree[node] = newvalue;  //রিলেভেন্ট সেগমেন্ট
		return;
	}

	//আরো ভাঙতে হবে
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;
	update(left,  b, mid,  i,  newvalue);
	update(right,  mid + 1, e,  i,  newvalue);
	tree[node] = tree[left] + tree[right];


}


int main()
{
	init(1, 1, 7);
	int ans = query(1, 1, 7, 1, 3);
	cout << ans << endl;
	update(1, 1, 7, 3, 10);
	ans = query(1, 1, 7, 1, 3);
	cout << ans << endl;

}
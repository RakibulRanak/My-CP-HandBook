//Lazy segment tree for returning sum of a range and updating a range at a time
//https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

#include <bits/stdc++.h>
using namespace std;
#define n 8 //0 index faka

int ara[n] = {0, 1, 2, 3, 4, 5, 6, 7};
int tree[n * 3]; //my idea is 2*n-1
int lazy[n * 3];

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

	if (lazy[node] != 0)
	{
		tree[node] += (e - b + 1) * lazy[node];
		if (b != e)
		{
			//not leaf node
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
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

void updateRange(int node, int b, int e, int i, int j, int value)
{
	if (lazy[node] != 0)
	{
		tree[node] += (e - b + 1) * lazy[node];
		if (b != e)
		{
			//not leaf node
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (i > e || j < b)
		return;   //বাইরে চলে গিয়েছে
	else if (b >= i && e <= j) {
		tree[node] += (e - b + 1) * value; //রিলেভেন্ট সেগমেন্ট
		if (b != e)
		{
			//not leaf node
			lazy[2 * node] += value;
			lazy[2 * node + 1] += value;
		}
		return;
	}

	//আরো ভাঙতে হবে
	int left = 2 * node;
	int right = 2 * node + 1;
	int mid = (b + e) / 2;
	updateRange(left,  b, mid,  i, j, value);
	updateRange(right,  mid + 1, e,  i, j, value);
	tree[node] = tree[left] + tree[right];

}


int main()
{
	init(1, 1, 7);
	int ans = query(1, 1, 7, 1, 3);
	cout << ans << endl;
	updateRange(1, 1, 7, 1, 3, 10);
	ans = query(1, 1, 7, 1, 3);
	cout << ans << endl;

}
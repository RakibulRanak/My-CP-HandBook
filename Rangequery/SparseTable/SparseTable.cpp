#include <bits/stdc++.h>
using namespace std;
#define n 100001
//log2 sometimes buggy,use custom log
int sparse[n][(int)log2(n) + 1];

//sparse table minimum maximum query method
//change all min to all max if you need maximum


//buildsparse take nlogn time where n is number of elements

void buildsparse(int ara[], int len)
{
	for (int i = 0; i < len; i++)
		sparse[i][0] = ara[i];
	for (int j = 1; (1 << j) <= len; j++)
	{
		int range = 1 << j;
		int half = range / 2;
		for (int i = 0; i + range <= len; i++)
			sparse[i][j] = min(sparse[i][j - 1], sparse[i + half][j - 1]);
		//jth column stores the range from i to i+pow(2,j)-1;
	}
}
//querysparse take O(1)time

int querysparse(int start, int end)
{
	int range = (end - start) + 1;
	int col = log2(range);//the column that should be searched
	int total = 1 << col; //range size in this coloumn
	return min(sparse[start][col], sparse[(end - total) + 1][col]);
}

int main()
{
	int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
	buildsparse(a, 10);
	cout << querysparse(0, 4) << endl;
	cout << querysparse(4, 7) << endl;
	cout << querysparse(7, 8) << endl;
}
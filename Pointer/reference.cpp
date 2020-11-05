#include <bits/stdc++.h>
using namespace std;

void hudai(int &x)
{
	cout << x << endl;
	x++;
}

int main()
{
	int a = 10;
	int &r = a;
	hudai(a);
	a++;
	cout << r << endl;
	r++;
	cout << a << endl;


}
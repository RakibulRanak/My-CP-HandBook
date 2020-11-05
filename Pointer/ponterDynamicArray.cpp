#include <bits/stdc++.h>
using namespace std;

int main()
{
	int *ara;
	//in C
	ara = (int *) malloc(5 * sizeof(int));
	for (int i = 0; i < 5; i++)
	{
		ara[i] = 2;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << ara[i] << " ";
	}
	delete []ara;

	cout << endl;
	//in C++

	int *ara2;

	ara2 = new int[5];

	for (int i = 0; i < 5; i++)
	{
		ara2[i] = 2;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << ara2[i] << " ";
	}
	delete []ara2;
	cout << endl;

}
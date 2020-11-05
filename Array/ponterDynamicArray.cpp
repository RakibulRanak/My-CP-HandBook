#include <bits/stdc++.h>
using namespace std;

int main()
{
	int *ara;
	//in C
	ara = (int *) malloc(5 * sizeof(int)); //malloc auto returns void pointer,malloc needs
	//stdlib.h in c
	for (int i = 0; i < 5; i++)
	{
		ara[i] = 2;
	}

	for (int i = 0; i < 5; i++)
	{
		cout << ara[i] << " ";
	}
	delete []ara;
	//free(ara) in C

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

	delete []ara2; //deallocation
	ara2 = NULL;
	cout << endl;

}
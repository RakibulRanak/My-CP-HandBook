#include<bits/stdc++.h>
using namespace std;



int main()
{

	//Case:1 whole array in stack
	int a[2][2] = {{1, 2}, {3, 4}};
	int f[2][2] = {{1, 2}} ;//{{1,2},{0,0}};
	int b[][2] = {{1, 2}, {3, 4}}; //coloumn must be given
	int z[2][2]; // all garbage

	//Case:2 a pointer array(array of pointers) in stack that points every row created in heap
	//half stack,half heap;

	int *d[2]; //d is an array of pointer
	d[0] = new int[2];
	d[1] = new int[2];
	delete []d[0];
	delete []d[1];

	//case:3 a pointer is created that points to an array of pointers in heap which point to every
	//row of the 2d array // all are in heap except **c(stack)
	int **c;
	int **x;
	c = new int *[2]; //so c is pointer that points to an array of pointer created in heap
	x = c;
	c[0] = new int[2];
	int &t = c[0][0];
	c[1] = new int[2];
	c[0][0] = 10;
	delete []c[0];
	delete []c[1];
	delete c;


}
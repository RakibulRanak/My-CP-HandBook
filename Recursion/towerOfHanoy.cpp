#include<bits/stdc++.h>
using namespace std;

//complexity 2^n
void TOH(int n, int a, int b, int c)
{
	if (n > 0)
	{
		TOH(n - 1, a, c, b);
		cout << "Move a pile from " << a << " to " << c << endl;
		TOH(n - 1, b, a, c);
	}
}

int main()
{
	//3 piles, move from 1 to 3 , use 2 for help
	//TOH(nomber of piles in source,source,empty pole,destination)
	TOH(3, 1, 2, 3);

}
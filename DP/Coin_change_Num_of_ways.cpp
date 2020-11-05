#include <bits/stdc++.h>
using namespace std;




int main()
{
	//target value
	long long n;
	while (cin >> n) {
		vector<long long>coins;
		map<long long, long long>value2;
		coins.push_back(1);
		coins.push_back(5);
		coins.push_back(10);
		coins.push_back(25);
		coins.push_back(50);
		long long sol[n + 1];
		value2[0] = 1;

		//it can calculate up to n= 10^5, if n is bigger solution exceeds memory
		// complexity n*coins
		//if n=6 , (1,5),(1,1,1,1,1,1)=2 (Number of  combination)


		for (auto c : coins)
		{
			for (int x = c; x <= n; x++)
			{
				if (x - c >= 0 )
				{
					value2[x] += value2[x - c];
				}
			}
		}
		cout << value2[n] << endl;
		value2.clear();
		value2[0] = 1;

		//if n=6 , (1,5),(1,1,1,1,1,1),(5,1)=3 //Number of permutation
		//it can calculate around n=10^5
		for (int x = 1; x <= n; x++)
		{
			for (auto c : coins)
			{
				if (x - c >= 0)
				{
					value2[x] += value2[x - c] ;
				}
			}
		}
		cout << value2[n] << endl;
	}
}
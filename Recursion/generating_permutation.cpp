#include <bits/stdc++.h>
using namespace std;

vector<int> permutation;
bool chosen[100];
int n;
void search1()
{
	if (permutation.size() == n)
	{
		for (auto x : permutation)
			cout << x << " ";
		cout << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (chosen[i])
				continue;
			chosen[i] = true;
			permutation.push_back(i);
			search1();
			chosen[i] = false;
			permutation.pop_back();
		}
	}
}
void search2() {
	for (int i = 0; i < n; i++) {
		permutation.push_back(i);
	}
	do {
		// process permutation
		for (auto x : permutation)
			cout << x << " ";
		cout << endl;
	} while (next_permutation(permutation.begin(), permutation.end()));

}
int main()
{
	cin >> n;
	cout << "My Function" << endl;
	search1();
	permutation.clear();
	cout << "Built In Function" << endl;
	//for builtin only sorted vector will produce all the permutations
	search2();

	/*if we need custom elements instead of 0 to n-1 we have to use permutation.push_back(ara[i])
	whereas ara/string will contain the custom elements
	*/
	return 0;
}
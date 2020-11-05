#include <bits/stdc++.h>
using namespace std;

template<class T>
class number
{
private:
	T a, b;
public:
	number()
	{
		a = 10;
		b = 10;
	}
	number(T x, T y);
	T add();
	T sub();

};

template<class T>
number<T>::number(T x, T y)
{
	a = x;
	b = y;
}
template<class T>
T number<T>::add()
{
	return a + b;
}
template<class T>
T number<T>::sub()
{
	return abs(a - b);
}

int main()
{
	number<int> num(20, 10);
	cout << num.add() << endl;

	number<float> num2(20.1, 10.0);
	cout << num2.add() << endl;

	return 0;
}
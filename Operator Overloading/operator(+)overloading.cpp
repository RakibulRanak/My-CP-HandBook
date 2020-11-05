//  https://www.youtube.com/watch?v=BO2KagRMS3M (reference)
#include <bits/stdc++.h>
using namespace std;

class Complex {
private:
	int real;
	int img;
public:
	Complex()
	{
		real = 0;
		img = 0;
	}
	Complex(int a, int b)
	{
		real = a;
		img = b;
	}
	void print()
	{
		cout << real << " " << img << endl;
	}
	Complex operator +(Complex temp)
	{
		Complex c;
		c.real = real + temp.real;
		c.img = img + temp.img;
		return c;
	}

};

int main()
{
	Complex a(10, 20);
	Complex b(5, 7);
	Complex c = a + b;
	c.print();
	c = a + b + a;
	c.print();
}
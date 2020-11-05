#include <bits/stdc++.h>
using namespace std;

struct mystack
{
	int size;
	int *ara;
	int top;
};

void push(mystack &st, int val)
{
	if (st.top >= st.size - 1)
	{
		cout << "STACK-SIZE FULL ALREADY!" << endl;
	}
	else
	{
		st.top++;
		st.ara[st.top] = val;

	}
}
int pop(mystack &st)
{
	int x = -1;
	if (st.top <= - 1)
	{
		cout << "STACK IS EMPTY!" << endl;
	}
	else
	{

		x = st.ara[st.top];
		st.top--;

	}
	return x;
}
int valueIn(mystack *st, int index)
{
	if (st->top + 1 < index || index < 0)
		return -1;
	else
		return st->ara[st->top + 1 - index];
}

int main()
{
	mystack st;
	cout << "Input Size of Stack:" << endl;
	cin >> st.size;
	st.ara = new int[st.size];
	st.top = -1;
	push(st, 5);
	push(st, 1);
	cout << pop(st) << endl;
	cout << valueIn(&st, 1) << endl;
}
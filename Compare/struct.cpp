#include <bits/stdc++.h>
using namespace std;

struct Student {
	string name;
	int roll;
	double marks;
};

bool compare(Student a, Student b)
{
	return ((a.marks > b.marks) || (a.marks == b.marks && a.roll < b.roll));
}


int main()
{
	Student mystd[5];
	for (int i = 0; i < 5; i++)
	{
		cin >> mystd[i].name;
		cin >> mystd[i].roll;
		cin >> mystd[i].marks;
	}
	sort(mystd, mystd + 5, compare);
	for (int i = 0; i < 5; i++) {
		cout << mystd[i].roll << " " << mystd[i].name << " " << mystd[i].marks << endl;
	}
}
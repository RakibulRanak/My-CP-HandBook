#include <bits/stdc++.h>
using namespace std;

struct Student {
	string name;
	int roll;
	double marks;
};

void change1(Student p)
{
	p.name = "kashem";
}
void change2(Student *p)
{
	p->name = "changed2";
}
void change3(Student &p)
{
	p.name = "changed3";
}



int main()
{


	Student kashem;
	kashem.name = "Kashem";
	kashem.roll = 2;
	kashem.marks = 80;
	//call by value
	change1(kashem);
	cout << kashem.name << endl;
	//call by address
	change2(&kashem);
	cout << kashem.name << endl;
	//call by reference . because change3 function receives the reference
	change3(kashem);
	cout << kashem.name << endl;

	Student *pointerkashem;
	pointerkashem = &kashem;
	//call by address
	change2(pointerkashem);
	cout << kashem.name << endl;

}
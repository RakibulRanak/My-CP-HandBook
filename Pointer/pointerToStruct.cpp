#include <bits/stdc++.h>
using namespace std;

struct Student {
	string name;
	int roll;
	double marks;
};

void change6(Student *x) {

	x->name = "Rakib";

}
void change5(Student *x) {
	for (int i = 0; i < 5; i++)
	{
		x[i].name = "Rakib";
	}
}
int main()
{
	struct Student *kashem;
	kashem = new Student;
	kashem->name = "Kashem";
	kashem->roll = 2;
	kashem->marks = 80;
	change6(kashem);
	cout << kashem->name << endl;


	//array of struct

	struct Student *kashem2;
	kashem2 = new Student[5];
	for (int i = 0; i < 5; i++)
	{
		kashem2[i].name = "Kashem";
		kashem2[i].roll = 2;
		kashem2[i].marks = 80;
	}
	change5(kashem2);
	for (int i = 0; i < 5; i++) {
		cout << kashem2[i].roll << " " << kashem2[i].name << " " << kashem2[i].marks << endl;
	}

	change6(kashem2);



}

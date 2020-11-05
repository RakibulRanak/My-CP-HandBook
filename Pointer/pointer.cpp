//passing stl and array as a pointer to a function

#include <bits/stdc++.h>
using namespace std;

struct Student {
	string name;
	int roll;
	double marks;
};

void change0(int x[]) {
	//not pointer array?then int x[]; or int[n][];
	x[0] = 50;
}

void change1(int *x) {
	//not pointer array?then int x[]; or int[n][];
	x[0] = 5;
}
void change2(vector<int>*x) {
	x->at(0) = 5;
}
void change3(map<int, int>*x) {
	x->at(0) = 100;
}
void change4(vector<pair<int, int>>*x) {
	x->at(0).first = 1;
	x->at(0).second = 2;
}
void change5(Student *x) {
	for (int i = 0; i < 5; i++)
	{
		x[i].name = "Rakib";
	}
}

void change6(Student *x) {

	x->name = "Rakib";

}


int main()
{
	int x;
	x = 5;
	int *p;
	p = &x;
	cout << p << endl; //address stored in p
	cout << &p << endl; //address of p
	cout << *p << endl;  //value of the address stored in p
	cout << &x << endl;


	int ara[3] = {1, 2, 3};
	//no need to write &ara for array
	change0(ara);
	cout << "int[]" << ara[0] << endl;
	change1(ara);
	cout << ara[0] << endl;
	vector<int>vec;
	vec.push_back(0);
	vec.push_back(1);
	change2(&vec);
	cout << vec[0] << endl;


	map<int, int>m;
	m[0] = 10;
	m[1] = 11;
	change3(&m);
	cout << m[0] << endl;


	vector<pair<int, int>>vecc;
	vecc.push_back({10, 20});
	vecc.push_back({20, 40});
	change4(&vecc);
	cout << vecc[0].first << " " << vecc[0].second << endl;
	cout << vecc[1].first << " " << vecc[1].second << endl;


	Student mystd[5];
	for (int i = 0; i < 5; i++)
	{
		mystd[i].name = "Ranak";
		mystd[i].roll = 1;
		mystd[i].marks = 100;
	}
	change5(mystd);
	for (int i = 0; i < 5; i++) {
		cout << mystd[i].roll << " " << mystd[i].name << " " << mystd[i].marks << endl;
	}


	Student kashem;
	kashem.name = "Kashem";
	kashem.roll = 2;
	kashem.marks = 80;
	change6(&kashem);
	cout << kashem.name << endl;
}
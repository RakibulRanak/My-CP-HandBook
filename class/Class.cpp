#include <bits/stdc++.h>
using namespace std;



class Person1 {
	string name; // name is private by default
	int age; // age is private by default

public:
	int birthYear;
	Person1() //constructor
	{
		name = "Default";
		age = 18;
	}
	Person1(string name, int a) //constructor
	{
		this->name = name;
		age = a;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName()const {
		return name;
	}
	int ageplus10();
	int ageplus10plusx(int x);
	~Person1(); //destructer function
};

int Person1::ageplus10()
{
	return age + 10;
};

int Person1::ageplus10plusx(int x)
{
	return age + 10 + x;
};
Person1::~Person1()
{
	//deallocate something here
	//this method runs automatically before finishing the execution
	cout << "destroyed" << endl;
};





int main()
{
	Person1 t("rakib", 23);
	//t.age = 20; // compiler error because x is private
	//t.birthYear = 1997;
	// cout << t.name << endl;
	// string x = "fol";
	// t.setName(x);
	cout << t.getName() << endl;
	cout << t.ageplus10() << endl;
	cout << t.ageplus10plusx(6) << endl;

	return 0;
}
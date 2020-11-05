#include <bits/stdc++.h>
using namespace std;

//Bigger active objects that carry private data , interfaced through public member functions

class Person1 {
	string name; // name is private by default
	int age; // age is private by default

public:
	int birthYear;
	void setName(string name) {
		this->name = name;
	}
	string getName()const {
		return name;
	}
};

//small passive objects that carry public data and have no or few basic member function

struct Person2 {
	string name;// name is public by default
private:
	int age;
public:
	void read(void)
	{
		cin >> age;

	}
	void print()
	{
		cout << "age: " << age << endl;
	}

};





int main()
{
	Person1 t;
	//t.age = 20; // compiler error because x is private
	t.birthYear = 1997;
	cout << t.birthYear << endl;
	string x = "fol";
	t.setName(x);
	cout << t.getName() << endl;

	//structure
	Person2 ranak, rahat;
	ranak.name = "ranak";
	rahat.name = "rahat";
	cout << ranak.name << endl;
	ranak.read();
	ranak.print();
	return 0;
}
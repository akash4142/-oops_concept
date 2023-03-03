#include <iostream>
#include "practice.h"

using namespace std;
using namespace sdds;
int main() {
	employee e1("shiva", 23 , 40000);
	employee e2;
	employee e3(e1);
	employee e4;
	cout << "welcome " << endl;
	cin >> e2;
	cout << "before modify " << endl;
	cout << e1;
	++e2;
	cout << e2;
	e4 = e1;
	//e3++;


	char modname[40];
	cout << "enter the modify name : ";
	cin >> modname;
	e1.modifyname(modname);
	e1 += 100;
	cout << "after modify " << endl;
	cout << e1;
	if (e1 == e3) {
		cout << "equal " << endl;
	}
	else {
		cout << "not equal " << endl;
	}
	int total = 0 ;
	cout << "E3 is the object" << endl;
	cout << e3;
	cout << e4;
	total = e1 + e2;
	cout << "total : " << total<<endl;
	cout << "the end " << endl;


	return 0;
}

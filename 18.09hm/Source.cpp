#include "pergruz.h"
#include <iostream>
using namespace std;

Student::Student() 
{
	char* name1;
	const double step;// !!
	int num;
}

Student::Student(const char* n, double st, const char* bookName, int bookPages)	{

	num = bookPages;
}

void Student::Setnum(int bookPages) {
	num = bookPages;
}
int& Student::Getnum() {
	return num;
}


void Student::Input() {
	cout << "Enter date: ";
	cin >> num;
}

void Student::Print() {
	cout << num << endl;
}
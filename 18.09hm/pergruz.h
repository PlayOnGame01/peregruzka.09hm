#pragma once
class Student {
	char* name1;
	const double step;// !!
	int num;
	Book book; //!!!

public:
	Student();
	Student(const char* n, double st, const char* bookName, int bookPages);


	void Setname1(int n);
	int& Getname1();

	void Setstep(int st);
	int& Getstep();

	void Setnum(int bookPages);
	int& Getnum();

	void Input();
	void Print();

};
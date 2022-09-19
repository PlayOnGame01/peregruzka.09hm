#include "pergruz.h"
#include<iostream>
using namespace std;

class Book
{
	char* name;
	int pages;
public:
	Book()
	{
		cout << "construct\n";
		pages = 0;
	}
	Book(int p)
	{
		cout << "construct\n";
		pages = p;
	}
	Book(const char* n, int p) :Book(p)
	{
		cout << "construct\n";
		pages = p;
	}
	void Output()
	{
		cout << "Name: " << name << "\tpages: " << pages << endl;
	}
	int Getpages()const
	{
		return pages;
	}
	void Print()
	{
		cout << "name : " << name << endl;
	}
	void Input() {
		char buf[200];
		cout << "Enter Name : ";
		cin.getline(buf, 200);
		if (name != nullptr) {
			cout << name << " is removed! \n";
			delete[]name;
		}
		name = new char[strlen(buf) + 1];
		strcpy_s(name, strlen(buf) + 1, buf);
	}

	~Book() {
		cout << "Destructor\n";
		delete[]name;
	}
};
//
//class Test
//{
//	int temp;
//	int temp2;
//public:
//	/*Test()
//	{
//		temp = 0;
//	}*/
//	Test(int t, int t2)
//	{
//		temp = t;
//		temp2 = t2;
//	}
//	void Show()
//	{
//		cout << temp << endl;
//	}
//	int Gettemp()
//	{
//		return temp;
//	}
//};

class Student
{

	char* name1;
	const double step;// !!
	int num;
	Book book; //!!!
public:
	Student(const char* n, double st, const char* bookName, int bookPages) :step(0), book(nullptr, 0)
	{
		cout << "Construct by 4 param\n";
		n = bookName;
	}
	Student(const char* n, double st, const char* bookName, int bookPages, int nu) :step(0), book(nullptr, 0)
	{
		cout << "Construct by 4 param\n";
		n = bookName;
		nu = bookPages;

	}
	Student(const Student& a) :step(0), book(nullptr, 0) // copy constructor
	{
		cout << "Copy constructor\n";
		this->name1 = a.name1;
		this->num = a.num;
	}
	void Init()
	{
		num = rand() % 10;
	}
	void Output()const
	{
		cout << "name: " << name1 << "\tstep: " << step << endl;
	}
	int Getobj()
	{
		return obj.Gettemp();
	}
	void Print()
	{
		cout << "pages : " << name1 << endl;
	}
	void operator() ()
	{
		cout << name1 << "\t" << num << endl;
	}
	Student& operator=(const Student& obj)
	{
		if (this == &obj)
		{
			return *this;
		}
		if (name1 != nullptr)
		{
			//delete[] name;
			this->~Student();
		}
		// глубокое копирование 
		name1 = new char[strlen(obj.name1) + 1];
		strcpy_s(name1, strlen(obj.name1) + 1, obj.name1);
		num = obj.num;

		return *this;
	}
	~Student() {
		cout << "Destructor\n";
		delete[]name1;
	}

	Student& operator--(Student& obj, const char* n) {
		Student temp(obj);
		obj.Setname1(obj.Getname1() - 1);
		return temp;
	}

	Student& operator++(Student& obj, const char* n) {
		Student temp(obj);
		obj.Setname1(obj.Getname1() + 1);
		return temp;
	}

	Student operator+(Student& obj, int bookPages) {
		cout << "Enter amount: ";
		cin >> num;

		Student temp(obj);
		obj.Setname1(obj.Getname1() + num);

		if (obj.Getname1() > 31) {
			obj.Setnum(obj.Getnum() + 1);
			obj.Setname1(obj.Getname1() - 31);
		}
		return temp;
	}
	char operator[](int index)
	{
		if (index >= 0 && index < strlen(name1))
		{
			return name1[index];
		}
		return '\0';
	}
};

int main()
{
	srand(unsigned(time(0)));
	Student step(10, 1, 100, 1000, 8);
	Student name(20, 2, 200, 2000, 9);
	cout << step.Getobj() << endl;



	name.Output();
}



#include <iostream>
#include <string>
using namespace std;

class Worker {
protected:
	string name_;
	string sur_;
	unsigned int year_;
public:
	Worker(string n, string s, unsigned int year);
	virtual void print() = 0;
	~Worker() {}
};

Worker::Worker(
	string n,
	string s,
	unsigned int year)
{
	this->name_ = n;
	this->sur_ = s;
	this->year_ = year;
}

class Salary : public Worker {
protected:
	double monthSalary_;
	double daySalary_;
public:
	Salary(string n,
		string s,
		unsigned int year,
		double monthSalary_);
	void print();
};

Salary::Salary(string n, string s, unsigned int year, double monthSalary_) :
	Worker(n, s, year) 
{
	this->monthSalary_ = monthSalary_;
	daySalary_ = monthSalary_ / 30;
}

void Salary::print()
{
	cout << name_ << endl;
	cout << sur_ << endl;
	cout << year_ << endl;
	cout << monthSalary_ << endl;
	cout << daySalary_ << endl;
	cout << endl;
}

int main() {
	Worker *pF[2];
	
	pF[0] = new Salary("Alex", "Kosykh", 1999, 100000);
	pF[1] = new Salary("domi", "asdas", 1998, 100022);
	
	for (unsigned int i = 0; i < 2; ++i) {
		pF[i]->print();
	}
	system("pause");
	return 0;
}
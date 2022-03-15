#pragma once
#include <iostream>
#include <cstring>
using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	Date();
	Date(int day, int month, int year);
	void setDate(int day, int month, int year);
	int getday();
	int getmonth();
	int getyear();
	int check_D(Date x);
	int check_big(int d, int m, int y);


	friend Date operator +(int in,Date a);

	Date operator +(int add);


	Date operator ++();
	Date operator ++(int);

	Date operator -();
	bool operator !();

	Date operator +=(Date e);

	bool operator >=(Date b);
	bool operator ==(Date q);



	friend istream& operator>>(istream& in, Date& q);
	friend ostream& operator <<(ostream& print, Date& Date_opject);

};
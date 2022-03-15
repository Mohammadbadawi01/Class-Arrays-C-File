#include "Date.h"
#include <cstring>
#include <iostream>
using namespace std;
bool chek(int day, int month, int year);
int q2(int y);
int q(int y);

bool chek(int day, int month, int year)
{
	if ((year >= 1) && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day >= 1 && day <= 31)
	{
		return true;
	}
	else if ((year >= 1) && (month == 4 || month == 6 || month == 9 || month == 11) && day >= 1 && day <= 30)
	{
		return true;
	}
	else if ((year >= 1) && month == 2 && day >= 1 && day <= 28)
	{
		return true;
	}
	else
	{
		return false;
		cout << "\nWrong Date <!>\n";
	}
}

Date::Date()
{

	day = month = 1;
	year = 1970;


}

Date::Date(int day, int month, int year)
{


	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::setDate(int day, int month, int year)
{
	if (chek(day, month, year))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
	else
	{
		cout << "wrong date !\n";

		cout << "Enter corect Date: \n";
		cout << "Enter the day: ";
		cin >> this->day;
		cout << "\nEnter the month: ";
		cin >> this->month;
		cout << "\nEnter the Year: ";
		cin >> this->year;

		if (chek(this->day, this->month, this->year))
		{
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else
		{
			cout << "again wrong date !!";
			exit(1);
		}
	}
}

int Date::getday()
{
	return day;
}

int Date::getmonth()
{
	return month;
}

int Date::getyear()
{
	return year;
}

int Date::check_D(Date x)
{
	return chek(x.getday(), x.getmonth(), x.getyear());
}

int Date::check_big(int d, int m, int y)
{

	if (y >= this->year)
	{
		return true;
	}
	else if (y == this->year)
	{
		if (m >= this->month)
		{
			return true;
		}
		else if (d >= this->day)
		{
			return true;
		}
	}
	return false;
}

Date Date::operator+(int add)
{
	this->day += add;
	this->month += add;
	this->year += add;
	return *this;
}

Date Date::operator++()
{
	this->month += 1;

	return *this;



}

Date Date::operator++(int)
{

	Date i;
	i.day = day;
	this->day +=5;
	return i;
}

Date Date::operator-()
{
	day *= -1;
	month *= -1;
	year *= -1;
	return *this;
}

bool Date::operator!()
{
	return (day==0 && month ==0&& year==0);
}

Date Date::operator+=(Date e)
{

	e.day += day;
	e.month += month;
	e.year += year;

	return e;

}

bool Date::operator==(Date q)
{
	return (day == q.day && month == q.month && year == q.year);

}

int q2(int y)
{
	if (y == 11 || y == 4 || y == 6 || y == 9)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int q(int x)
{

	if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) { return true; }
	else
	{
		return false;
	}

}
Date operator+(int in, Date a)
{
	a.day += in;
	a.month += in;
	a.year += in;
	return a;
}
istream& operator>>(istream& in, Date& q)
{
	in >> q.day >> q.month >> q.year;
	return in;
}

ostream& operator<<(ostream& print, Date& Date_object)
{
	print << Date_object.day << "/" << Date_object.month << "/" << Date_object.year;

	return print;
}
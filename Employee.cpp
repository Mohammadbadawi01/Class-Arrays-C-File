
#include "Employee.h"
#include "Date.h"
#include "Date.h"
#include <cstring>
#include <iostream>

Employee::Employee()
{
	First_name = "Defolt";
	Last_name = "Defolt";
	Salary = 0;
	BirthDate.setDate(BirthDate.getday(), BirthDate.getmonth(), BirthDate.getyear());
	HireDate.setDate(HireDate.getday(), HireDate.getmonth(), HireDate.getyear());
}

Employee::Employee(string First_name, string Last_name, Date BirthDate, Date HireDate)
{
	this->First_name = First_name;
	this->Last_name = Last_name;
	this->BirthDate = BirthDate;
	this->HireDate = HireDate;
	this->Salary = 0;
}

void Employee::setEmployee(string First_name, string Last_name,int Salary,Date BirthDate, Date HireDate)
{
	this->First_name = First_name;
	this->Last_name = Last_name;
	this->Salary = Salary;
	this->BirthDate = BirthDate;
	this->HireDate = HireDate;

}

string Employee::get_First_name()
{ 
	return First_name;
}
string Employee::get_Last_name()
{
	return Last_name;
}
int Employee::get_B_d()
{
	return BirthDate.getday();
}
int Employee::get_B_m()
{
	return BirthDate.getmonth();
}
int Employee::get_B_y()
{
	return BirthDate.getyear();
}
int Employee::get_s()
{
	return Salary;
}
int Employee::get_H_d()
{
	return HireDate.getday();
}
int Employee::get_H_m()
{
	return HireDate.getmonth();
}
int Employee::get_H_y()
{
	return HireDate.getyear();
}

ostream& operator<<(ostream& print, Employee& Employee_opject)
{
	//cout << "First-name    Last-name    Salary     Birth-date     Hire-date  \n";

	print << Employee_opject.First_name << " " << Employee_opject.Last_name << " " << Employee_opject.Salary<<" "<< Employee_opject.BirthDate<<" "<< Employee_opject.HireDate;

	return print;
	
}

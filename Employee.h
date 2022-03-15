#pragma once
#include <iostream>
#include <cstring>
using namespace std;
#include "Date.h"

class Employee
{
private:
	string First_name;
	string Last_name;
	Date BirthDate;
	Date HireDate;
	int Salary;

public:
	Employee();	
	Employee(string First_name, string Last_name, Date BirthDate, Date HireDate);
	void setEmployee(string First_name, string Last_name,int Salary, Date BirthDate, Date HireDate);
	friend ostream& operator <<(ostream& print, Employee& Date_opject);
	string get_First_name();
	string get_Last_name();
	int get_B_d();
	int get_B_m();
	int get_B_y();
	int get_s();
	int get_H_d();
	int get_H_m();
	int get_H_y();
};
#include "Student.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
//#define_CRT_SECURE_NO_WARNINGS;
Student::Student()//constructor
{
	this->student_Id = 0;
	firstName = ' ';
	lastName = ' ';
}
Student::Student(int num, string fiName, string laName)//constructor
{
	this->student_Id = num;
	firstName = fiName;
	lastName = laName;
}
ostream&  operator<<(ostream& out, const Student& st)//operator cout of student
{
	out << st.student_Id << " ";
	out << st.firstName << " ";
	out << st.lastName << endl;
	return out;
}

istream& operator>>(istream& in, Student& st)//operator cin 
{
	in >> st.student_Id >> st.firstName >> st.lastName;
	return in;
}
void Student::operator=(Student std)//operator =
{
	this->student_Id = std.student_Id;
	this->firstName = std.firstName;
	this->lastName = std.lastName;
}
bool Student:: operator==(Student std)//operator ==
{
	if (this->student_Id == std.student_Id && this->firstName == std.firstName && this->lastName == std.lastName)
		return true;
	return false;
}
bool Student::operator<(Student other)//operator <
{
	return ((firstName < other.firstName) && (lastName < other.lastName));
}
bool Student:: operator!=(Student std)//operator !=
{
	if (this->student_Id == std.student_Id && this->firstName == std.firstName && this->lastName == std.lastName)
		return false;
	return true;
}
bool Student::operator>(Student other)//operator >
{
	return firstName > other.firstName && lastName > other.lastName;
}
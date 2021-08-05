#pragma once
using namespace std;
#include <iostream>

class Student
{
protected:
	int idNumber; // the id num
	string firstName;
	string lastName;
	int numberOfCourses;
	   
public:
	Student() {}; // default constructor 
	Student(int, string, string, int);//constructor with parametters id-firstname-lastname-numberofcourses
	virtual ~Student() {};
	virtual bool milga() = 0; // fonction implement in the sons / abstract class
	virtual void print();

};


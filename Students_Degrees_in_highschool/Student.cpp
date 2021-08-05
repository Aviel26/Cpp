#include "Student.h"
#include <iostream>
#include <string>
using namespace std;

Student::Student(int theId, string theFirstName, string theLastName, int thenumOfCourses) {
	idNumber = theId;
	firstName = theFirstName;
	lastName = theLastName;
	numberOfCourses = thenumOfCourses;
}
void Student::print() {
	cout << "ID: " << idNumber << "\n"
		<< "first name: " << firstName << "\n"
		<< "last name: " << lastName << "\n"
		<< "num courses: " << numberOfCourses << "\n";
}
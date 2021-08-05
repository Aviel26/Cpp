#include "BA.h"
#include<iostream>
using namespace std;

BA::BA(int theId, string theFirstName, string theLastName, int theNumberOfCourses, int theSize,int *theGrade) 
	:Student(theId, theFirstName, theLastName, theNumberOfCourses) {
	pointerToGradeTabe = new int[theSize];
	tabSize = theSize;
	for (int i = 0; i <theSize ; i++)
	{
		pointerToGradeTabe[i] = theGrade[i];
	}
}
BA::BA(BA& copy) {
	tabSize = copy.tabSize;
	pointerToGradeTabe = new int[tabSize];
	firstName = copy.firstName;
	lastName = copy.lastName;
	idNumber = copy.idNumber;
	numberOfCourses = copy.numberOfCourses;
	for (int i = 0; i < tabSize; i++) {
		this->pointerToGradeTabe[i] = copy.pointerToGradeTabe[i];
	}
}
BA::~BA()
{delete pointerToGradeTabe;}

bool BA::milga() {
	bool isTrue(true);
	if (tabSize > 9)
	{
		int sum = 0;
		for (int i = 0; i < 10; i++)
		{
			sum += pointerToGradeTabe[i];
		}
		sum = sum / tabSize;
		if (sum > 95)
			return isTrue;
	}
	return !isTrue;
}

void BA::print() {
	Student::print();
	cout << "grades: ";
	for (int i = 0; i < tabSize; i++) {
		cout << pointerToGradeTabe[i] << " ";
	}
}
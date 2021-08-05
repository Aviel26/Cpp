#include "MA.h"
#include<iostream>
#include <string>
using namespace std;

MA::MA(int theId, string theFirstName, string theLastName, int theNumberOfCourses, int theSize, int*theGrades, bool inResearch)
	:BA(theId, theFirstName, theLastName, theNumberOfCourses, theSize, theGrades) {
	isInTheResearch = inResearch; // if is in research 
}
bool MA::milga() {
	bool isMilga(true); 
	if (numberOfCourses >= 7) { // if he takes 7 coures ore more
		
		float average(0); // local parametter
		for (int i = 0; i < tabSize; i++) {
			average += pointerToGradeTabe[i];
		}
		average /= tabSize; // calcul the avrage of all the grades
		if (average > 90 && (isInTheResearch)) // average more of 90 and he is in research ===== he is apt to receive milga
			return isMilga;
	}
	return !(isMilga);
}
void MA::print()
{
	BA::print(); // print of the class BA
	cout << "research: ";
	if (isInTheResearch)
		cout << "yes";
	else
		cout << "no";
	cout << "\n";
}

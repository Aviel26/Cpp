#include "PHD.h"
using namespace std;
#include<string>

PHD::PHD(int theId, string theFirstName, string theLastName, int theNumberOfCourses, int numberHours)
	:Student(theId, theFirstName, theLastName, theNumberOfCourses) {
	numberHourOfResearchForWeek = numberHours;
}
bool PHD::milga() {
	return (numberOfCourses >= 2 && numberHourOfResearchForWeek >= 25); // he takes 2 courses or more and in researche 25 hours or more
}
void PHD::print()
{
	Student::print();
	cout << "hours: " << numberHourOfResearchForWeek << endl;
}
PHD::~PHD(){};
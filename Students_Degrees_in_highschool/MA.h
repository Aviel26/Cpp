#pragma once
#include "BA.h"
class MA : public BA
{
private :
	bool isInTheResearch;
public:

	MA(int theId, string theFirstName, string theLastName, int theNumberOfCourses, int theSize, int*, bool isInResearch);
	bool milga()override; //override of the fonction because the conditions to receive milga are differents
	void print()override;// there ares elements to add at the print fonction of the class Student

	
	
		
	
};


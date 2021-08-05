#pragma once
#include "Student.h"
class BA :public  Student
{
protected:
	int *pointerToGradeTabe;
	int tabSize;

public:
	BA(int theId, string theFirstName, string theLastName, int theNumberOfCourses, int theSize, int*);
	BA(BA&);
	~BA();
	bool milga()override;
	void print()override;
};


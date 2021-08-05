#pragma once
#include "Student.h"

class PHD :public Student
{
private:
	int numberHourOfResearchForWeek;

public:
	PHD(int theId, string theFirstName, string theLastName, int theNumberOfCourses, int numberHours );
	~PHD();
	bool milga()override;
	void print()override;
};


#include"Student.h"
#include"BA.h"
#include"MA.h"
#include"PHD.h"
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void milgot(Student ** arr) // 2D tab
{
	for (int i = 0; i < 7; i++)
	{
		if (arr[i]->milga() != 0) // if the student apt to receive milga
			arr[i]->print(); // ===> we will print the data of this student
	}
}
using namespace std;
int main()
{
	Student* theData[7];
	int grade1[] = { 90,100,90 };
	int grade2[] = { 100,100,90,100,90,100,90,100,90,100 };
	int grade3[] = { 90, 100, 90, 100, 90, 100, 90 };
	int grade4[] = { 90, 100, 90, 100, 90, 100, 90 };
	theData[0] = new BA(123, "abe", "avraham", 3, 3, grade1);
	theData[1] = new BA(234, "yitzhak", "avrahamson", 10, 10, grade2);
	theData[2] = new MA(345, "yaacov", "jacobson", 7, 7, grade3, 0);
	theData[3] = new MA(456, "sara", "emanu", 7, 7, grade4, 1);
	theData[4] = new PHD(567, "rivka", "imanu", 1, 30);
	theData[5] = new PHD(678, "rachel", "jacobs", 2, 20);
	theData[6] = new PHD(789, "leah", "jacobs", 2, 30);
	milgot(theData);
	


	return 0;
}


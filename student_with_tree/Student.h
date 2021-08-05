
#include <iostream>
using namespace std;
class Student
{
protected:
	int student_Id;// id number of the stud
	string firstName;// name of the stud
	string lastName;//family name of the stud
public:
	Student();//constrctor default
	Student(int num, string Finame, string name2);//constructor
	friend ostream& operator <<(ostream& os, const Student& theStudent);//operator (cout)
	friend istream& operator >>(istream& is, Student& theStudent);//operator (cin)
	void operator=(Student std);//operator=
	bool operator!=(Student std);//operator !=
	bool operator==(Student std);//operator==
	bool operator<(Student std);//operator <
	bool operator>(Student std);//operator>

};
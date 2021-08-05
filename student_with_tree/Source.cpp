

#include "SearchTree.h"
#include"Student.h"
#include <iostream>
using namespace std;
int main()
{
	SearchTree<Student> tree;
	Student st;
	char ch;
	cout << "enter a-e" << endl;
	cin >> ch;
	while (ch != 'e')

	{
		switch (ch)
		{
		case'a':// Add student.
			cout << "enter a student" << endl;
			cin >> st;
			tree.add(st);
			break;
		case 'b':// Deleting a student
			cout << "enter a student" << endl;
			cin >> st;
			tree.remove(st);
			break;
		case 'c'://Search student
			cout << "enter a student" << endl;
			cin >> st;
			if (tree.search(st))
				cout << "exist" << endl;
			else cout << "no exist" << endl;
			break;
		case 'd'://Printing of all students registered at the Institute.
			tree.inOrder();
			break;
		case 'e'://Exit - end program.
			break;
		default://If the input is not right: error.
			cout << "error" << endl;
			break;
		}
		cout << "enter a-e" << endl;
		cin >> ch;
	}
	//	system("pause");
	return 0;
}/*
 exemple

 enter a-e
a
enter a student
2 b b
enter a-e
a
enter a student
5 e e
enter a-e
a
enter a student
1 a a
enter a-e
a
enter a student
4 d d
enter a-e
a
enter a student
7 g g
enter a-e
a
enter a student
3 c c
enter a-e
b
enter a student
5 e e
enter a-e
d
1 a a
2 b b
3 c c
4 d d
7 g g
enter a-e
e
*/
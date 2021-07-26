#include "Student.h"
#include "Single_list.h"
#include "Double_list.h"

int main()
{
	srand(1);

	Student pr = { "John \t\tScoth", 3, 2001, 57, 1 };
	Student* p = &pr;

	Add(p, "Peter \t\tScoth", 4, 2000, 88);
	Add(p, "Pamella \tScoth", 1, 2002, 85);
	Add(p, "Ethan \t\tScoth", 2, 2001, 78);
	Add(p, "Tim \t\tScoth", 3, 2005, 98);
	Add(p, "Ella \t\tScoth", 4, 2009, 99);
	Add(p, "Rick \t\tScoth", 5, 2111, 100);

	DeleteEl(p, 5);

	Insert(p, 3, "Peppa \t\tScoth", 5, 2000, 77);

	Insert(p, 5, "Penna \t\tScoth", 2, 2007, 100);

	makeCir(p);
	UnmakeCir(p);

	cout <<"#\t"<< "First" << "\t\tLast NM\t" << "Number" << "\t" << "Year" << "\t" << "Marks" << "\n";
	show(p);
	//DeleteAll(p);

	cout << "2 task\n";
	int a[12];

	for (int i = 0; i < 12; i++)
		a[i] = rand()%100;

	Double_List br = { 5 };
	Double_List* b = &br;

	for (int i = 1; i < 12; i++)
		AddDL(b, a[i]);

	DL_show(b);

	return 0;
}
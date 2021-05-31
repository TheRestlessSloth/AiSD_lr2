#pragma once
#include <iostream>

using namespace std;

struct Student
{
	string Name;
	int numOgroup;
	int year;
	int marks;
	
	int number;

	Student* Next;
	Student* Prev;
};

Student* Add(Student* Head, string Name, int numOgroup, int year, int marks)
{
	Student* p = Head;
	p->Prev = NULL;

	int num = 2;
	while (p->Next != NULL)
	{
		p = p->Next;
		num++;
	}

	Student* NewItem = new(Student);
	NewItem->Name = Name;
	NewItem->numOgroup = numOgroup;
	NewItem->year = year;
	NewItem->marks = marks;
	NewItem->Next = NULL;
	NewItem->number = num;
	NewItem->Prev = p;

	p->Next = NewItem;
	

	return p;
}

Student* DeleteEl(Student* Head, int number)
{
	Student* ptr;
	Student* Current = Head;
	for (int i = 1; i < number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) 
	{
		if (Current == Head) 
		{
			Head = Head->Next;
			cout << Current->Name << " has deleted\n";
			delete(Current);
			Current = Head;
		}
		else 
		{
			ptr = Head;
			while (ptr->Next != Current)
				ptr = ptr->Next;
			ptr->Next = Current->Next;
			delete(Current);
			Current = ptr;
		}
	}
	return Head;
}

void DeleteAll(Student* Head)
{
	if (Head != NULL) 
	{
		DeleteAll(Head->Next);
		delete Head;
	}
	cout << "All has deleted\n";
}

double FindMaxValue(Student* Head)
{
	int r = 0;
	Student* p = Head;
	do
	{
		if (p->marks >= r)
			r = p->marks;
		p = p->Next;
	} while (p->Next != NULL);
	
	return r;
}

Student* Insert(Student* Head, int number, string Name, int numOgroup, int year, int marks)
{
	//для двусвязного
	number--;
	Student* NewItem = new(Student);
	NewItem->Name = Name;
	NewItem->numOgroup = numOgroup;
	NewItem->year = year;
	NewItem->marks = marks;
	NewItem->Next = NULL;

	if (Head == NULL)
	{
		Head = NewItem; //Изменить бошку, если бошки нет
	}
	else
	{
		Student* Current = Head; 
		for (int i = 1; i < number && Current->Next != NULL; i++)
			Current = Current->Next; //передвинуться до цифры, и если адреса следующего элемента нет
		if (number == 0)
		{
			NewItem->Next = Head; //Следующий после нового будет бошка
			Head = NewItem; //Бошка становится новым
		}
		else
		{
			if (Current->Next != NULL) //Если у нынеш. след. адрес не равен нулю 
				NewItem->Next = Current->Next;
			Current->Next = NewItem;
		}
	}
	return Head;
}

void updateNum(Student* Head)
{
	int num = 1;
	while (Head != NULL)
	{
		Head->number = num;
		Head = Head->Next;
		num++;
	}
}

void show(Student* Head)
{
	updateNum(Head);
	Student* p = Head;
	while (p != NULL)
	{
		cout << p->number <<"\t" << p->Name << "\t" << p->numOgroup << "\t" << p->year << "\t" << p->marks << "\n";
		p = p->Next;
		
	}
	cout << "Max mark =\t" << FindMaxValue(Head) << endl;
	cout << "\n";
}

void makeCir(Student* Head)
{
	Student* first = Head;
	while (Head->Next != NULL)
	{
		Head = Head->Next;
	}
	Head->Next = first;
	first->Prev = Head; //для двусвязного
}

void UnmakeCir(Student* Head)
{
	Student* first = Head;
	Head = Head->Next;
	while (Head->Next != first)
	{
		Head = Head->Next;
	}
	Head->Next = NULL;
	first->Prev = NULL; //для двусвязного
}
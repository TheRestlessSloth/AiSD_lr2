#pragma once
#include <iostream>
#include <cstdlib>

using namespace std;

struct Double_List {//структура данных                     
	int Data; //информационное поле   
	Double_List* Next; //адресное поле
	Double_List* Prev; //адресное поле
};

Double_List* AddDL(Double_List* Head, int marks)
{
	Double_List* p = Head;
	p->Prev = NULL;

	while (p->Next != NULL)
		p = p->Next;

	Double_List* NewItem = new(Double_List);
	NewItem->Data = marks;
	NewItem->Next = NULL;
	NewItem->Prev = p;

	p->Next = NewItem;

	return p;
}

double DLMaxValue(Double_List* Head)
{
	int r = 0;
	Double_List* p = Head;
	do
	{
		if (p->Data >= r)
			r = p->Data;
		p = p->Next;
	} while (p->Next != NULL);

	return r;
}

double DLSum(Double_List* Head)
{
	int r = 0;
	Double_List* p = Head;

	while (p->Next != NULL)
	{
		r += p->Data;
		p = p->Next;
	}

	return r;
}

void DL_show(Double_List* Head)
{
	Double_List* p = Head;
	while (p != NULL)
	{
		cout << p->Data << " ";
		p = p->Next;

	}
	cout << endl;
	cout << "Max =\t" << DLMaxValue(Head) << endl;
	cout << "Sum =\t" << DLSum(Head)<<"\n";
}
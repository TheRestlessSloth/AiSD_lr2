#pragma once
#include <math.h>

struct Single_List {//структура данных                     
	int Data; //информационное поле   
	int Number;
	Single_List* Next; //адресное поле
};

Single_List* Head; //указатель на первый элемент списка 
Single_List* Current;  //указатель на текущий элемент списка (при необходимости) 

Single_List* Insert_Item_Single_List(Single_List* Head, int Number, int DataItem) /*вставка элемента с заданным номером в однонаправленный список*/
{
	Number--;
	Single_List* NewItem = new(Single_List);
	NewItem->Data = DataItem;
	NewItem->Next = NULL;
	if (Head == NULL)
	{//список пуст     
		Head = NewItem;//создаем первый элемент списка   
	}
	else
	{//список не пуст     
		Single_List* Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
			Current = Current->Next;
		if (Number == 0) {     //вставляем новый элемент на первое место       
			NewItem->Next = Head;
			Head = NewItem;
		}
		else
		{//вставляем новый элемент на непервое место       
			if (Current->Next != NULL)
				NewItem->Next = Current->Next;
			Current->Next = NewItem;
		}
	}
	return Head;
}

Single_List* Delete_Item_Single_List(Single_List* Head, int Number) /*удаление элемента с заданным номером из однонаправленного списка*/
{
	Single_List* ptr;//вспомогательный указатель   
	Single_List* Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) {//проверка на корректность     
		if (Current == Head) {//удаляем первый элемент       
			Head = Head->Next;
			delete(Current);
			Current = Head;
		}
		else {//удаляем непервый элемент       
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

void Add(Single_List* Head, int Data)
{

	if (Head->Next != NULL)
	{
		Head = Head->Next;
		Add(Head, Data);
	}

	Single_List* NewItem = new(Single_List);

	NewItem->Data = Data;
	NewItem->Next = NULL;
	NewItem->Number = Head->Number + 1;

	Head->Next = NewItem;
}

bool Contains(Single_List* Head, int DataItem) //поиск элемента в однонаправленном списке 
{
	Single_List* ptr; //вспомогательным указатель   
	ptr = Head;
	while (ptr != NULL)
	{//пока не конец списка     
		if (DataItem == ptr->Data)
			return true;
		else ptr = ptr->Next;
	}
	return false;
}

void Delete_Single_List(Single_List* Head) /*освобождение памяти, выделенной под однонаправленный список*/
{
	if (Head != NULL)
	{
		Delete_Single_List(Head->Next);
		delete Head;
	}
}

void massToList(Single_List* Head, int mass[])
{
	for (int i = 1; i <= sizeof(mass); i++)
		Add(Head, mass[i - 1]);
	//Insert_Item_Single_List(Head, i, mass[i - 1]);
}
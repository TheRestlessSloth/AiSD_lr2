#pragma once
#include <iostream>

using namespace std;

//создание однонаправленного списка (добавления в конец)
void Make_Single_List(int n, Student** Head) {
	if (n > 0) {
		(*Head) = new Student();
		//выделяем память под новый элемент
		cout << "Введите значение ";
		cin >> (*Head)->Name;
		//вводим значение информационного поля
		(*Head)->Next = NULL;//обнуление адресного поля
		Make_Single_List(n - 1, &((*Head)->Next));
	}
}
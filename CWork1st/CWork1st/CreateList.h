#pragma once
#include "Struct.h"

List* NewTable(int* counter);								//Начальное создание таблицы
List* AddStudent(List* l, List* r, int* counter);			//Добавление в список
List* AddNS(Inf a);											//Создание первого элемента (для чтения)
List* AddS(List* r, Inf a);									//Создание элементов (для чтения)
int WriteFile(const string filename, List* l);						//Запись данных в файл
int ReadFile(const string filename, List** l, List** r, List* end);	//Чтение данных из файла
#pragma once
#include "Struct.h"

void Print(List* l, int* id);								//Просмотр списка по 10 записей
void PrintAll(List* l, int* id);							//Просмотр всего списка
void PrintBySur(List* l, string surname);					//Просмотр списка студентов по фамилии
int PrintById(List* l, int id);								//Просмотр списка по номеру
List* PrintTen(List* l);
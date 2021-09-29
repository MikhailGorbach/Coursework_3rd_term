#pragma once
#include "Struct.h"

void SortSurToLow(List* l);									//Сортировка фамилий по убыванию
void SortSurToHigh(List* l);								//Сортировка фамилий по возрастанию
void SortSHoursToHigh(List* l);								//Сортировка пропущенных часов(пропущ.) по убыванию
void SortSHoursToLow(List* l);								//Сортировка пропущенных часов(пропущ.) по возрастанию
void SortJHoursToHigh(List* l);								//Сортировка пропущенных часов(оправд.) по возрастанию
void SortJHoursToLow(List* l);								//Сортировка пропущенных часов(оправд.) по убыванию
void SortYearToHigh(List* l);								//Сортировка года рождения по возрастанию
void SortYearToLow(List* l);								//Сортировка года рождения по убыванию
void SortGenderToLow(List* l);								//Сортировка гендера по убыванию
void SortGenderToHigh(List* l);								//Сортировка гендера по возрастанию
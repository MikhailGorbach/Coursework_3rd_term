#pragma once
#include "Struct.h"

List* DelFirstStudent(List* l, int* id);					//Удаление первого студента
void DelStudent(List* l, int counter, int* id);				//Удаление студента по ключу
List* DelLastStudent(List* l, List* r, int* id);			//Удаление последнего студента
List* DelAllStudents(List* l, int* id, bool* skip_cinget);  //Удаление всего списка
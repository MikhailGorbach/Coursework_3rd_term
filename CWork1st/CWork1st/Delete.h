#pragma once
#include "Struct.h"

List* DelFirstStudent(List* l, int* id);					//�������� ������� ��������
void DelStudent(List* l, int counter, int* id);				//�������� �������� �� �����
List* DelLastStudent(List* l, List* r, int* id);			//�������� ���������� ��������
List* DelAllStudents(List* l, int* id, bool* skip_cinget);  //�������� ����� ������
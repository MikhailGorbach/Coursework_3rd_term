#pragma once
#include "Struct.h"

List* NewTable(int* counter);								//��������� �������� �������
List* AddStudent(List* l, List* r, int* counter);			//���������� � ������
List* AddNS(Inf a);											//�������� ������� �������� (��� ������)
List* AddS(List* r, Inf a);									//�������� ��������� (��� ������)
int WriteFile(const string filename, List* l);						//������ ������ � ����
int ReadFile(const string filename, List** l, List** r, List* end);	//������ ������ �� �����
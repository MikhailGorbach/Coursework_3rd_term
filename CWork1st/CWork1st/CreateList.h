#pragma once
#include "Struct.h"

List* NewTable(int* counter, bool skip_cinget);				//��������� �������� �������
List* AddStudent(List* l, List* r, int* counter);			//���������� � ������
List* AddNS(Inf a);											//�������� ������� �������� (��� ������)
List* AddS(List* r, Inf a);									//�������� ��������� (��� ������)
int WriteFile(const string filename, List* l);						//������ ������ � ����
int ReadFile(const string filename, List** l, List** r, List* end);	//������ ������ �� �����
void WriteReport(int sum, float perc);						//����� ������ � �����
string ReadReport();										//������ ������ �� ����� ������
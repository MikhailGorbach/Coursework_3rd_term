#pragma once
#include "Struct.h"

void Print(List* l, int* id);								//�������� ������ �� 10 �������
void PrintAll(List* l, int* id);							//�������� ����� ������
void PrintBySur(List* l, string surname);					//�������� ������ ��������� �� �������
int PrintById(List* l, int id);								//�������� ������ �� ������
List* PrintTen(List* l);
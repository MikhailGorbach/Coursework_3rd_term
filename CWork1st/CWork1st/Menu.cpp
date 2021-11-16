#include "Menu.h"

void MenuMain(int iItem)
{
	system("cls");
	printf("\n\t\t\t\t\t\t\x1b[32m����� ����������!\n\x1b[0m\n");
	printf("\t\t\t\x1b[36m--------------------------------------------------------------------\x1b[0m\n\n");
	printf("\t\t\t\t\t %s ��������� �������� �������\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s �������� �������\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ���������� ����� ������\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s �������� ������\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ������������� ������\x1b[0m\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ���������� �������\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ����� ��������\n\n", iItem == 7 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ���������� ������ � ����\n\n", iItem == 8 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ��������� ������ �� �����\n\n", iItem == 9 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ��ר�\n\n", iItem == 10 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s \x1b[31m�����\x1b[0m\n\n", iItem == 11 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\t\t\x1b[36m--------------------------------------------------------------------\x1b[0m\n\n");
	printf("\t\t\t\x1b[36m<!--���������� �������������� ��������� �����, ����, ������-->\n\n\n\x1b[0m");
}
void MenuCorrect(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32m�������� ���� ��� ��������������: \x1b[0m\n\n");
	printf("\t%s �������\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ��� ��������\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ��� ������\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ���������� ����������� ����� (�� ����. �������)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ���������� ����������� ����� (�� ������. �������)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ���\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s \x1b[31m�����\x1b[0m\n\n", iItem == 7 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--���������� �������������� ��������� �����, ����, ������-->\n\x1b[0m");
}
void MenuSort(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32m�������� ���� ��� ����������: \x1b[0m\n\n");
	printf("\t%s �������\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ��� ��������\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ��� ������\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ���������� ����������� ����� (�����������)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ���������� ����������� ����� (�������������)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s ���\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s \x1b[31m�����\x1b[0m\n\n", iItem == 7 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--���������� �������������� ��������� �����, ����, ������-->\n\x1b[0m");
}
void MenuExit(int iItem)
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t\x1b[31m�� �������, ��� ������ �����?\x1b[0m\n\n\n");
	printf("\t\t\t\t\t%s ��\n\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t%s ���\n\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t%s �����, �������� ������ � ����\n\n\n", iItem == 3 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\t\t\t\x1b[36m<!--���������� �������������� ��������� �����, ����, ������-->\n\x1b[0m");
}
void MenuSortFirst(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32m�������� ����������\x1b[0m\n\n");
	printf("\t%s �� �����������\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s �� ��������\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s \x1b[31m�����\x1b[0m\n\n", iItem == 3 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--���������� �������������� ��������� �����, ����, ������-->\n\x1b[0m");
}	
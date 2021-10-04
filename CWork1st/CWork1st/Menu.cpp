#include "Menu.h"

void ShowMenu(int iItem)
{
	system("cls");
	cout << "\t\t\t\t\t\x1b[32m����� ����������!\x1b[0m" << endl;
	printf("\t\t\t\t%s 1 - ��������� �������� �������\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 2 - �������� �������\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 3 - ���������� ����� ������ � �������\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 4 - �������� ������\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 5 - ������������� ������ � �������\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 6 - ���������� �������\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 7 - ����� ������ � �������\n\n", iItem == 7 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 8 - ���������� ������� � �����\n\n", iItem == 8 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 9 - ������ ������ �� �����\n\n", iItem == 9 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s10 - ���������� ����������� �����(�����������) � ���� ���������\n\n", iItem == 10 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s11 - ������� �����������(�������������) �����\n\n", iItem == 11 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s12 - �����\n", iItem == 12 ? "\x1b[33m--->\x1b[0m" : " ");
	printf("\t\t\t\t\x1b[36m!���������� �������������� ����������� �����, ����, ������!\n\n\x1b[0m");
}
void MenuSearchCor(int iItem)
{
	system("cls");
	cout << "\x1b[32m�������� ���� ��� ��������������: \x1b[0m" << endl;
	printf("%s  1 - �������\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  2 - ��� ��������\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  3 - ��� ������\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  4 - ���������� ����������� ����� (�����������)\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  5 - ���������� ����������� ����� (�������������)\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  6 - ���\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  7 - ����� �� ����\n", iItem == 7 ? "\x1b[34m--->\x1b[0m" : " ");
	printf("\x1b[36m!���������� �������������� ����������� �����, ����, ������!\n\x1b[0m");
}
void MenuSearchSort(int iItem)
{
	system("cls");
	cout << "\x1b[32m�������� ���� ��� ����������: \x1b[0m" << endl;
	printf("%s  1 - �������\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  2 - ��� ��������\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  3 - ��� ������\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  4 - ���������� ����������� ����� (�����������)\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  5 - ���������� ����������� ����� (�������������)\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  6 - ���\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  7 - ����� �� ����\n", iItem == 7 ? "\x1b[34m--->\x1b[0m" : " ");
	printf("\x1b[36m!���������� �������������� ����������� �����, ����, ������!\n\x1b[0m");
}
void ShowExit(int iItem)
{
	system("cls");
	cout << endl << "\x1b[31m�� �������, ��� ������ �����?\x1b[0m" << endl;
	printf("%s  1 - ��\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  2 - ���\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  3 - �����, �������� ������ � ����\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\x1b[36m!���������� �������������� ����������� �����, ����, ������!\n\x1b[0m");
}
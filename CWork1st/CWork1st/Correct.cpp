#include "Correct.h"
#include "Check.h"

void CorSurname(List* l, int num)
{
	List* temp = l;
	string surname = "";
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "\n������� ����� ������� ��� ��������: ";
			cin >> surname;
			temp->p.surname = surname;
			cout << "\n\x1b[32m������� �������� ��\x1b[0m " << temp->p.surname << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
void CorYear(List* l, int num)
{
	List* temp = l;
	int age = 0;
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "\n������� ����� ��� �������� ��� ��������: ";
			CheckYear(age);
			temp->p.year = age;
			cout << "\n\x1b[32m��� ������� ��\x1b[0m " << temp->p.year << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
void CorGroup(List* l, int num)
{
	List* temp = l;
	string gr = "";
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "\n������� ����� ������ � ��������: ";
			cin >> gr;
			temp->p.�odeGr = gr;
			cout << "\n\x1b[32m��� ������ ������ ��\x1b[0m " << temp->p.�odeGr << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
void CorSHours(List* l, int num)
{
	List* temp = l;
	int sH = 0;
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "\n������� ����� ���������� ����������� ����� � �������� (�����.): ";
			CheckHours(sH);
			temp->p.sHours = sH;
			cout << "\n\x1b[32m���� �������� ��\x1b[0m " << temp->p.sHours << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
void CorJHours(List* l, int num)
{
	List* temp = l;
	int sH = 0;
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "������� ����� ���������� ����������� ����� � �������� (���.): ";
			cin >> sH;
			CheckHours(sH);
			temp->p.jHours = sH;
			cout << "\x1b[32m���� �������� ��\x1b[0m " << temp->p.jHours << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
void CorGender(List* l, int num)
{
	List* temp = l;
	bool gender;
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "\n";
			CheckGender(gender);
			temp->p.gender = gender;
			cout << "\n\x1b[32m������� �������� ��\x1b[0m " << temp->p.gender << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
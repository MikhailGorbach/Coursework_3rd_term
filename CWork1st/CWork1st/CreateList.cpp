#define _CRT_SECURE_NO_WARNINGS
#include "CreateList.h"
#include "Check.h"
#include "Console.h"
#include <fstream>

List* NewTable(int* counter)
{
	CursorVisabilityChange(1);
	List* l = new List;
	Inf a;
	system("cls");
	cout << "\n \x1b[36m<!--������� ������ � �������� (* ��� ������)-->\x1b[0m\n" << endl << endl;
	cout << " ��� ������: "; getline(cin, a.�odeGr); cout << "\n";
	if (a.�odeGr == "*")
	{
		CursorVisabilityChange(0);
		return 0;
	}
	cout << " �������: "; getline(cin, a.surname); cout << "\n";
	cout << " ��� ��������:"; 
	CheckYear(a.year); cout << "\n";
	CheckGender(a.gender); cout << "\n";
	cout << " ���������� ����������� �����: "; 
	CheckHours(a.sHours); cout << "\n";
	cout << " ���������� ����������� �����: ";
	CheckHours(a.jHours); cout << "\n";
	a.id = ++(*counter);
	l->p = a;
	l->next = 0;
	CursorVisabilityChange(0);
	return l;
}
List* AddStudent(List* l, List* r, int* counter)
{
	if (!l) { cout << "\t\x1b[31m������ ����!\x1b[0m" << endl; cout << "\t"; system("pause"); return l; }

	CursorVisabilityChange(1);
	while (1)
	{
		system("cls");
		cout << "\n \x1b[36m<!--������� ������ � �������� (* ��� ������)-->\x1b[0m\n" << endl << endl;
		List* temp = new List;
		Inf a;
		cout << " ��� ������: "; cin.get(); getline(cin, a.�odeGr); cout << "\n";
		if (a.�odeGr == "*")
		{
			CursorVisabilityChange(0);
			return r;
		}
		cout << " �������: "; getline(cin, a.surname); cout << "\n";
		cout << " ��� ��������: ";
		CheckYear(a.year); cout << "\n";
		CheckGender(a.gender); cout << "\n";
		cout << " ���-�� ����������� �����: ";
		CheckHours(a.sHours); cout << "\n";
		cout << " ���-�� ����������� �����: ";
		CheckHours(a.jHours); cout << "\n";
		a.id = r->p.id + 1;
		(*counter)++;
		temp->p = a;
		temp->next = 0;
		r->next = temp;
		r = temp;
	}
	CursorVisabilityChange(0);
	return r;
}
List* AddNS(Inf a)
{
	List* temp = new List;
	temp->p = a;
	temp->next = 0;
	return temp;
}
List* AddS(List* r, Inf a)
{
	List* temp = new List;
	temp->p = a;
	temp->next = 0;
	r->next = temp;
	r = temp;
	return r;
}
int WriteFile(const string filename, List* l)
{
	ofstream fout(filename, ios::out);

	if (!fout.is_open()) { cout << "\t\x1b[31m�� ������� ������� ����!\x1b[0m" << endl; cout << "\t"; system("pause"); return 1; }

	List* temp = l;

	while (temp)
	{
		fout
			<< temp->p.id << endl
			<< temp->p.surname << endl
			<< temp->p.year << endl
			<< temp->p.�odeGr << endl
			<< temp->p.gender << endl
			<< temp->p.sHours << endl
			<< temp->p.jHours << endl;

		temp = temp->next;
	}
	cout << "\n\t\x1b[32m������ �������� � �����\x1b[0m " << filename << " \x1b[32m.\x1b[0m\n" << endl;
	cout << "\t"; system("pause");
	return 0;
}
int ReadFile(const string filename, List** l, List** r, List* end)
{
	ifstream fin(filename, ios::in);

	if (!fin.is_open()) { cout << "\n\t\x1b[31m�� ������� ������� ����!\x1b[0m\n" << endl; cout << "\t"; system("pause"); return 1; }

	if (!end)
	{
		*l = 0;
		Inf a;
		int n = 0;

		while (fin >> a.id)
		{
			fin
				>> a.surname
				>> a.year
				>> a.�odeGr
				>> a.gender
				>> a.sHours
				>> a.jHours;

			if (*l) { *r = AddS(*r, a); n++; }
			else { *l = AddNS(a); *r = *l; n++; }
		}
		cout << "\n\t\x1b[32m������ ��������� �� �����\x1b[0m " << filename << " \x1b[32m.\x1b[0m\n" << endl;
		cout << "\t"; system("pause");
		return n;
	}
	else
	{
		Inf a;
		int forId = 0;
		int n = 0;

		while (fin >> a.id)
		{
			forId++;
			a.id = end->p.id + forId;
			fin
				>> a.surname
				>> a.year
				>> a.�odeGr
				>> a.gender
				>> a.sHours
				>> a.jHours;
			*r = AddS(*r, a); n++;
		}
		cout << "\n\t\x1b[32m������ ��������� �� �����\x1b[0m " << filename << " \x1b[32m� ��������� � ������.\x1b[0m\n" << endl;
		cout << "\t"; system("pause");
		return n;
	}
}
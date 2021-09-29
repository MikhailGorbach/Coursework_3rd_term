#include "CreateList.h"
#include "Check.h"
#include <fstream>

List* NewTable(int* counter)
{
	List* l = new List;
	Inf a;
	cout << "������� ������ � ��������: " << endl;
	cout << "=======================================" << endl;
	cout << "��� ������: "; getline(cin, a.�odeGr);
	cout << "�������: "; getline(cin, a.surname);
	cout << "��� ��������: ";
	CheckYear(a.year);
	cout << "������� ��� (� - 1, � - 0): ";
	CheckGender(a.gender);
	cout << "���������� ����������� �����: ";
	CheckHours(a.sHours);
	cout << "���������� ����������� �����: ";
	CheckHours(a.jHours);
	a.id = ++(*counter);
	l->p = a;
	l->next = 0;

	return l;
}
List* AddStudent(List* l, List* r, int* counter)
{
	if (!l) { cout << "������ ����!" << endl; system("pause"); return l; }

	while (1)
	{
		List* temp = new List;
		Inf a;
		cout << "������� ������ � ��������: " << endl;
		cout << "������� *, ����� ����������." << endl;
		string c;
		cin >> c;
		if (c == "*") break;
		cout << "=======================================" << endl;
		cout << "��� ������: "; cin.get(); getline(cin, a.�odeGr);
		cout << "�������: "; getline(cin, a.surname);
		cout << "��� ��������: "; cin >> a.year;
		CheckYear(a.year);
		cout << "������� ��� (� - 1, � - 0): ";
		int g = 1;
		cin >> g;
		if (g == 1) a.gender = true;
		else a.gender = false;
		cout << "���-�� ����������� �����: "; cin >> a.sHours;
		CheckHours(a.sHours);
		cout << "���-�� ����������� �����: "; cin >> a.jHours;
		CheckHours(a.jHours);
		a.id = r->p.id + 1;
		(*counter)++;
		temp->p = a;
		temp->next = 0;
		r->next = temp;
		r = temp;
	}
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

	if (!fout.is_open()) { cout << "�� ������� ������� ����!" << endl; system("pause"); return 1; }

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
	cout << "\x1b[32m������ �������� � �����\x1b[0m " << filename << "\x1b[32m.\x1b[0m" << endl;
	system("pause");
	return 0;
}
int ReadFile(const string filename, List** l, List** r, List* end)
{
	ifstream fin(filename, ios::in);

	if (!fin.is_open()) { cout << "�� ������� ������� ����!" << endl; system("pause"); return 1; }

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
		cout << "\x1b[32m������ ��������� �� �����\x1b[0m " << filename << " \x1b[32m.\x1b[0m" << endl;
		system("pause");
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
		cout << "������ ��������� �� ����� " << filename << " � ��������� � ������ ������." << endl;
		system("pause");
		return n;
	}
}
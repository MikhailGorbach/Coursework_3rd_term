#include "Check.h"
#include "Console.h"

void CheckYear(int& a)
{
	CursorVisabilityChange(1);
	while (1)
	{
		cout << " ";
		cin >> a;
		string s = typeid(a).name();
		if (cin.fail() || a < 1900 || a > 2025 || (s == "string"))
		{
			cout << " \x1b[31m������� ���������� ��� ��������.\x1b[0m" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (cin.good())
		{
			CursorVisabilityChange(0);
			return;
		}
	}
}
void CheckHours(int& a)
{
	CursorVisabilityChange(1);
	while (1)
	{
		cout << " ";
		cin >> a;
		string s = typeid(a).name();
		if (cin.fail() || a > 2000 || a < 0 || (s == "string"))
		{
			cout << endl << " \x1b[31m������� ���������� ���������� �����.\x1b[0m" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (cin.good())
		{
			CursorVisabilityChange(0);
			return;
		}
	}
}
void CheckGender(bool& a)
{
	cout << " ������� ��� (� - 1, � - 0): ";
	CursorVisabilityChange(1);
	while (1)
	{
		cout << " ";
		cin >> a;
		string s = typeid(a).name();
		if (cin.fail() || (s == "string"))
		{
			cout << endl << " \x1b[31m������� ���������� ���.\x1b[0m" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (cin.good())
		{
			CursorVisabilityChange(0);
			return;
		}
	}
}
#include "Check.h"

void CheckYear(int& a)
{
	while (1)
	{
		cout << "--> ";
		cin >> a;
		string s = typeid(a).name();
		if (cin.fail() || a < 1900 || a > 2025 || (s == "string"))
		{
			cout << "\x1b[31mВведите корректный год рождения.\x1b[0m" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (cin.good())
		{
			return;
		}
	}
}
void CheckHours(int& a)
{
	while (1)
	{
		cout << "--> ";
		cin >> a;
		string s = typeid(a).name();
		if (cin.fail() || a > 2000 || a < 0 || (s == "string"))
		{
			cout << endl << "\x1b[31mВведите корректное количество часов.\x1b[0m" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (cin.good())
		{
			return;
		}
	}
}
void CheckGender(bool& a)
{
	cout << "Введите пол (М - 1, Ж - 0)";
	while (1)
	{
		cout << "--> ";
		cin >> a;
		string s = typeid(a).name();
		if (cin.fail() || (s == "string"))
		{
			cout << endl << "\x1b[31mВведите корректный пол.\x1b[0m" << endl;
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			continue;
		}
		else if (cin.good())
		{
			return;
		}
	}
}
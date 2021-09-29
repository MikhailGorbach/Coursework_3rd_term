#include "Sort.h"

void SortSurToLow(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.surname < temp2->p.surname)
			{
				string sur = temp1->p.surname;
				temp1->p.surname = temp2->p.surname;
				temp2->p.surname = sur;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortSurToHigh(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.surname > temp2->p.surname)
			{
				string sur = temp1->p.surname;
				temp1->p.surname = temp2->p.surname;
				temp2->p.surname = sur;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortSHoursToHigh(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.sHours > temp2->p.sHours)
			{
				int sH = temp1->p.sHours;
				temp1->p.sHours = temp2->p.sHours;
				temp2->p.sHours = sH;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortSHoursToLow(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.sHours < temp2->p.sHours)
			{
				int sH = temp1->p.sHours;
				temp1->p.sHours = temp2->p.sHours;
				temp2->p.sHours = sH;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortJHoursToHigh(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.jHours > temp2->p.jHours)
			{
				int jH = temp1->p.jHours;
				temp1->p.jHours = temp2->p.jHours;
				temp2->p.jHours = jH;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortJHoursToLow(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.jHours < temp2->p.jHours)
			{
				int jH = temp1->p.jHours;
				temp1->p.jHours = temp2->p.jHours;
				temp2->p.jHours = jH;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortYearToHigh(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.year > temp2->p.year)
			{
				int y = temp1->p.year;
				temp1->p.year = temp2->p.year;
				temp2->p.year = y;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortYearToLow(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.year < temp2->p.year)
			{
				int y = temp1->p.year;
				temp1->p.year = temp2->p.year;
				temp2->p.year = y;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortGenderToHigh(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.gender > temp2->p.gender)
			{
				int g = temp1->p.gender;
				temp1->p.gender = temp2->p.gender;
				temp2->p.gender = g;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortGenderToLow(List* l)
{
	List* temp1;
	List* temp2;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.gender < temp2->p.gender)
			{
				int g = temp1->p.gender;
				temp1->p.gender = temp2->p.gender;
				temp2->p.gender = g;
			}
		}
	}
	cout << "\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
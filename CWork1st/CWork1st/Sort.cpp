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
				Inf sur = temp1->p;
				temp1->p = temp2->p;
				temp2->p = sur;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf sur = temp1->p;
				temp1->p = temp2->p;
				temp2->p = sur;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf sH = temp1->p;
				temp1->p = temp2->p;
				temp2->p = sH;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf sH = temp1->p;
				temp1->p = temp2->p;
				temp2->p = sH;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf jH = temp1->p;
				temp1->p = temp2->p;
				temp2->p = jH;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf jH = temp1->p;
				temp1->p = temp2->p;
				temp2->p = jH;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf y = temp1->p;
				temp1->p = temp2->p;
				temp2->p = y;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf y = temp1->p;
				temp1->p = temp2->p;
				temp2->p = y;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf g = temp1->p;
				temp1->p = temp2->p;
				temp2->p = g;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
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
				Inf g = temp1->p;
				temp1->p = temp2->p;
				temp2->p = g;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortGroupToLow(List* l)
{
	List* temp1;
	List* temp2;

	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.сodeGr < temp2->p.сodeGr)
			{
				Inf g = temp1->p;
				temp1->p = temp2->p;
				temp2->p = g;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
void SortGroupToHigh(List* l)
{
	List* temp1;
	List* temp2;

	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		for (temp2 = temp1->next; temp2; temp2 = temp2->next)
		{
			if (temp1->p.сodeGr > temp2->p.сodeGr)
			{
				Inf g = temp1->p;
				temp1->p = temp2->p;
				temp2->p = g;
			}
		}
	}

	int counter = 1;
	for (temp1 = l; temp1; temp1 = temp1->next)
	{
		temp1->p.id = counter++;
	}

	cout << "\n\x1b[32mСортировка выполнена!\x1b[0m" << endl;
	system("pause");
}
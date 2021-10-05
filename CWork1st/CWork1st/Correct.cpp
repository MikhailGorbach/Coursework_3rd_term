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
			cout << "\nВведите новую фамилию для студента: ";
			cin >> surname;
			temp->p.surname = surname;
			cout << "\n\x1b[32mФамилия изменена на\x1b[0m " << temp->p.surname << "\n\n";
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
			cout << "\nВведите новый год рождения для студента: ";
			CheckYear(age);
			temp->p.year = age;
			cout << "\n\x1b[32mГод изменен на\x1b[0m " << temp->p.year << "\n\n";
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
			cout << "\nВведите новую группу у студента: ";
			cin >> gr;
			temp->p.сodeGr = gr;
			cout << "\n\x1b[32mКод группы изменён на\x1b[0m " << temp->p.сodeGr << "\n\n";
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
			cout << "\nВведите новое количество пропущенных часов у студента (неопр.): ";
			CheckHours(sH);
			temp->p.sHours = sH;
			cout << "\n\x1b[32mЧасы изменены на\x1b[0m " << temp->p.sHours << "\n\n";
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
			cout << "Введите новое количество пропущенных часов у студента (опр.): ";
			cin >> sH;
			CheckHours(sH);
			temp->p.jHours = sH;
			cout << "\x1b[32mЧасы изменены на\x1b[0m " << temp->p.jHours << "\n\n";
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
			cout << "\n\x1b[32mФамилия изменена на\x1b[0m " << temp->p.gender << "\n\n";
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
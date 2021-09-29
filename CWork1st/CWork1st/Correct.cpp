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
			cout << "Введите новую фамилию для студента: ";
			cin >> surname;
			temp->p.surname = surname;
			cout << "\x1b[32mФамилия изменена на\x1b[0m " << temp->p.surname << endl;
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
			cout << "Введите новый год рождения для студента: ";
			cin >> age;
			CheckYear(age);
			temp->p.year = age;
			cout << "\x1b[32mГод изменен на\x1b[0m " << temp->p.year << endl;
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
			cout << "Введите новую группу у студента: ";
			cin >> gr;
			temp->p.сodeGr = gr;
			cout << "\x1b[32mКод группы изменён на\x1b[0m " << temp->p.сodeGr << endl;
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
			cout << "Введите новое количество пропущенных часов у студента (неопр.): ";
			cin >> sH;
			CheckHours(sH);
			temp->p.sHours = sH;
			cout << "\x1b[32mЧасы изменены на\x1b[0m " << temp->p.sHours << endl;
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
			cout << "\x1b[32mЧасы изменены на\x1b[0m " << temp->p.jHours << endl;
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
void CorGender(List* l, int num)
{
	List* temp = l;
	int gender;
	while (temp)
	{
		if (temp->p.id == num)
		{
			cout << "Введите другой пол студента (1 - М, 0 - Ж): ";
			cin >> gender;
			temp->p.gender = gender;
			cout << "\x1b[32mФамилия изменена на\x1b[0m " << temp->p.gender << endl;
			system("pause");
			break;
		}
		temp = temp->next;
	}
}
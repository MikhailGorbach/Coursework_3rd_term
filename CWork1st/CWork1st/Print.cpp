#include "Print.h"
#include <iomanip>

void Print(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }

	system("cls");

	List* temp = l;

	cout << " ________________________________________________________________________________" << endl;
	cout << "| №  |   Код группы   |    Фамилия     | Год  | Часы : ув. / неув. причина | Пол |" << endl;
	while (temp)
	{
		cout
			<< "| " << setw(2) << temp->p.id
			<< " | " << setw(14)
			<< temp->p.сodeGr << " | "
			<< setw(14)
			<< temp->p.surname << " | "
			<< setw(4)
			<< temp->p.year << " | "
			<< setw(10)
			<< temp->p.jHours << " | "
			<< setw(13)
			<< temp->p.sHours << " | "
			<< setw(3) << temp->p.gender << " |" << endl;
		temp = temp->next;
	}
	cout << " ________________________________________________________________________________ " << endl;
	system("pause");
}
void PrintBySur(List* l, string surname)
{
	List* temp = l;
	cout
		<< endl << "По фамилии " << surname << " найдены следующие записи:" << endl;
	cout << " ________________________________________________________________________________" << endl;
	cout << "| №  |   Код группы   |    Фамилия     | Год  | Часы : ув. / неув. причина | Пол |" << endl;
	while (temp)
	{
		if (temp->p.surname == surname)
		{
			cout
				<< "| " << setw(2) << temp->p.id << " | " << setw(10)
				<< temp->p.сodeGr << " | " << setw(14) << temp->p.surname << " | "
				<< setw(4) << temp->p.year << " | " << setw(10) << temp->p.sHours << " | "
				<< setw(13) << temp->p.jHours << " | "
				<< setw(3) << temp->p.gender << " |" << endl;
		}
		temp = temp->next;
	}
	cout << " ________________________________________________________________________________ " << endl;
	system("pause");
}
int PrintById(List* l, int id)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return 1; }

	cout << " ________________________________________________________________________________" << endl;
	cout << "| №  |   Код группы   |    Фамилия     | Год  | Часы : ув. / неув. причина | Пол |" << endl;
	List* temp = l;
	while (temp)
	{
		if (temp->p.id == id)
		{
			cout
				<< "| " << setw(2) << temp->p.id << " | " << setw(14)
				<< temp->p.сodeGr << " | " << setw(14) << temp->p.surname << " | "
				<< setw(4) << temp->p.year << " | " << setw(10) << temp->p.sHours << " | "
				<< setw(13) << temp->p.jHours << " | "
				<< setw(3) << temp->p.gender << " |" << endl;
			cout << " ________________________________________________________________________________ " << endl;
			system("pause");
			return 0;
		}
		temp = temp->next;
	}
	cout << " ________________________________________________________________________________ " << endl;
}
#include "Delete.h"

List* DelFirstStudent(List* l, int* id)
{
	if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); return l; }

	List* tmpId;
	for (tmpId = l; tmpId; tmpId = tmpId->next)
	{
		tmpId->p.id--;
	}

	(*id)--;
	List* temp = l;
	l = l->next;
	delete temp;

	cout << "\t\x1b[32mПервый элемент списка удалён.\x1b[0m\n" << endl << "\t";
	system("pause");
	return l;
}
void DelStudent(List* l, int counter, int* id)
{
	if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); return; }

	(*id)--;
	List* temp = l;
	List* tempN = temp->next;
	while (tempN)
	{
		if (tempN->p.id == counter)
		{
			List* tmpId;
			for (tmpId = tempN; tmpId; tmpId = tmpId->next)
			{
				tmpId->p.id--;
			}
			temp->next = tempN->next;
			delete tempN;
			break;
		}
		temp = temp->next;
		tempN = tempN->next;
	}
	cout << "\t\x1b[32mЭлемент\x1b[0m " << counter << " \x1b[32mудалён.\x1b[0m\n" << endl << "\t";
	system("pause");
}
List* DelLastStudent(List* l, List* r, int* id)
{
	if (!r) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); return r; }

	(*id)--;
	for (r = l; r->next->next; r = r->next);

	List* temp = r->next;
	r->next = 0;
	delete temp;

	cout << "\t\x1b[32mПоследний элемент списка удалён.\x1b[0m\n" << endl << "\t";
	system("pause");
	return l;
}
List* DelAllStudents(List* l, int* id)
{

	for (l; l;)
	{
		(*id)--;
		List* temp = l;
		l = l->next;
		delete temp;
	}
	l = 0;

	cout << "\t\x1b[32mСписок удалён!\x1b[0m\n" << endl << "\t";
	system("pause");
	return l;
}
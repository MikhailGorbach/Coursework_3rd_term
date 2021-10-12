#include "Print.h"
#include <iomanip>
#include <Windows.h>
#include <conio.h>

void Print(List* l, int* id)
{
	if (!l) { cout << "������ ����!" << endl; system("pause"); return; }

	cout << "������� 1, ���� ������ ������� ���� ������" << endl;
	string c;
	cin >> c;
	if (c == "1")
	{
		PrintAll(l, id);
		return;
	}

	system("cls");

	List* temp = l;
	List* table = l;
	int list = 0;
	int endlist = ((*id) % 10 == 0) ? (*id) / 10 : ((*id) / 10) + 1;
	List* tempprev = l;

	while (1)
	{
		char Key = _getch();
		if (GetAsyncKeyState(VK_RIGHT))
		{
			keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
			if (list < endlist)
			{
				list++;
				temp = PrintTen(temp);
				cout << " ________________________________________________________________________________ " << endl;
				cout << "�������� " << list << " �� " << endlist << endl;
				system("pause");
			}
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			break;
		}
	}
}
void PrintBySur(List* l, string surname)
{
	List* temp = l;
	bool find = false;

	while (temp)
	{
		if (temp->p.surname == surname) find = true;
		temp = temp->next;
	}
	if (find)
	{
		system("cls");
		List* temp = l;
		cout
			<< endl << "�� ������� " << surname << " ������� ��������� ������:" << endl;
		cout << " ________________________________________________________________________________" << endl;
		cout << "| �  |   ��� ������   |    �������     | ���  | ���� : ��. / ����. ������� | ��� |" << endl;
		while (temp)
		{
			if (temp->p.surname == surname)
			{
				cout
					<< "| " << setw(2) << temp->p.id << " | " << setw(14)
					<< temp->p.�odeGr << " | " << setw(14) << temp->p.surname << " | "
					<< setw(4) << temp->p.year << " | " << setw(10) << temp->p.sHours << " | "
					<< setw(13) << temp->p.jHours << " | "
					<< setw(3) << temp->p.gender << " |" << endl;
			}
			temp = temp->next;
		}
		cout << " ________________________________________________________________________________ " << endl;
		system("pause");
	}
	else
	{
		cout << "�� ������� " << surname << " ��� �� ����� ������." << endl;
		system("pause");
	}
}
int PrintById(List* l, int id)
{
	if (!l) { cout << "������ ����!" << endl; system("pause"); return 1; }

	cout << " ________________________________________________________________________________" << endl;
	cout << "| �  |   ��� ������   |    �������     | ���  | ���� : ��. / ����. ������� | ��� |" << endl;
	List* temp = l;
	while (temp)
	{
		if (temp->p.id == id)
		{
			cout
				<< "| " << setw(2) << temp->p.id << " | " << setw(14)
				<< temp->p.�odeGr << " | " << setw(14) << temp->p.surname << " | "
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
void PrintAll(List* l, int* id)
{
	if (!l) { cout << "������ ����!" << endl; system("pause"); return; }

	system("cls");

	List* temp = l;

	while (1)
	{
		system("cls");
		cout << " ________________________________________________________________________________" << endl;
		cout << "| �  |   ��� ������   |    �������     | ���  | ���� : ��. / ����. ������� | ��� |" << endl;
		while (temp)
		{

			cout
				<< "| " << setw(2) << temp->p.id
				<< " | " << setw(14)
				<< temp->p.�odeGr << " | "
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
		break;
	}
}
List* PrintTen(List* l)
{
	List* temp = l;

	while (temp)
	{
		int pcounter = 0;
		system("cls");
		cout << " ________________________________________________________________________________" << endl;
		cout << "| �  |   ��� ������   |    �������     | ���  | ���� : ��. / ����. ������� | ��� |" << endl;
		while (pcounter < 10)
		{
			cout
				<< "| " << setw(2) << temp->p.id << " | " << setw(14)
				<< temp->p.�odeGr << " | " << setw(14) << temp->p.surname << " | "
				<< setw(4) << temp->p.year << " | " << setw(10) << temp->p.sHours << " | "
				<< setw(13) << temp->p.jHours << " | "
				<< setw(3) << temp->p.gender << " |" << endl;
			temp = temp->next;
			pcounter++;
		}
		break;
	}
	return temp;
}

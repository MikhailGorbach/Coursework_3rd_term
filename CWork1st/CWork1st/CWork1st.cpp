#include <iostream>
#include <string>
#include <typeinfo>	
using namespace std;

struct Inf
{
	string сodeGr;
	string surname;
	int year;
	bool gender;
	int sHours;
	int jHours;
};
struct List
{
	Inf p;
	List* next;
};
//                                    Прототипы функций

int MenuCheck(int* a); //Валидация меню
List* NewTable(int* counter); //Начальное создание таблицы
List* AddStudent(List* r, int* counter);//Добавление в список
void Print(List* l); //Просмотр списка
List* DelStudent(List* l, const int counter);
//Подсчёт количества неоправданных часов по каждому студенту
int main()
{
	List* l = 0,* r = 0;
	int id = 0;
	setlocale(LC_ALL, "rus");
	while (1)
	{
		system("cls");
		cout << " 1 -> Начальное создание таблицы" << endl;
		cout << " 2 -> Просмотр таблицы" << endl;
		cout << " 3 -> Добавление новой записи в таблицу" << endl;
		cout << " 4 -> Удаление записи" << endl;
		cout << " 5 -> Корректировка записи в таблице" << endl;
		cout << " 6 -> Сортировка таблицы" << endl;
		cout << " 7 -> Поиск записи в таблице" << endl;
		cout << " 8 -> Сохранение таблицы в файле" << endl;
		cout << " 9 -> Чтение данных из файла" << endl;
		cout << "10 -> Обработка таблицы и просмотр результатов обработки" << endl;
		cout << "11 -> Выход" << endl << endl;
		cout << "Выберите пункт меню -> ";
		
		int key = 0;
		cin >> key;
		
		if (MenuCheck(&key))
		{
			switch (key)
			{
			case 1:
				l = NewTable(&id);
				r = l;
				break;
			case 2:
				Print(l);
				break;
			case 3:
				r = AddStudent(r, &id);
				break;
			case 4:
			{
				int number = 0;
				cout << "Введите номер студента для удаления -> ";
				while (1)
				{
					cin >> number;
					if (number <= id)
					{
						break;
					}
					else
					{
						cout << "Нет такого номера записи!" << endl;
						system("pause");
					}
				}
				l = DelStudent(l, number);
				break;
			}
			case 5:

				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:

				break;
			case 10:

				break;
			case 11:
				return 0;
			default:
				cout << "Выберите пункт из списка!" << endl;
				system("pause");
			}
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}
int MenuCheck(int* a)
{
	int &key = *a;
	string s = typeid(key).name();
	if (s == "int" && key != 0) return 1;
	return 0;
}
List* NewTable(int* counter)
{
	List* l = new List;
	Inf a;
	cout << "Введите данные о студенте: " << endl;
	cout << "=======================================" << endl;
	cout << "Код группы: "; cin.get(); getline(cin, a.сodeGr);
	cout << "Фамилия: "; getline(cin, a.surname);
	cout << "Год рождения: "; cin >> a.year;
	cout << "Количество пропущенных часов: "; cin >> a.sHours;
	cout << "Количество оправданных часов: "; cin >> a.jHours;
	a.gender = true;
	l->p = a;
	l->next = 0;
	(*counter)++;
	return l;
}
void Print(List* l)
{
	if (!l)
	{
		cout << "Список пуст!" << endl;
		system("pause");
		return;
	}
	List* temp = l;
	cout << "/============\\" << endl;
	while (temp)
	{
		cout << "Группа| Фамилия        |Год рождения|Кол-во пропущенных ч.|Кол-во оправданных ч." << endl;
		cout << temp->p.сodeGr << "   " << temp->p.surname << " " << temp->p.year << " " << temp->p.sHours << " " << temp->p.jHours << endl;
		system("pause");
		temp = temp->next;
	}
}
List* AddStudent(List* r, int* counter)
{
	while (1)
	{
		List* temp = new List;
		Inf a;
		cout << "Введите данные о студенте: " << endl;
		cout << "Нажмите *, чтобы прекратить." << endl;
		string c;
		cin >> c;
		if (c == "*") break;
		cout << "=======================================" << endl;
		cout << "Код группы: "; cin.get(); getline(cin, a.сodeGr);
		cout << "Фамилия: "; getline(cin, a.surname);
		cout << "Год рождения: "; cin >> a.year;
		a.gender = true;
		cout << "Кол-во пропущенных часов: "; cin >> a.sHours;
		cout << "Кол-во оправданных часов: "; cin >> a.jHours;
		temp->p = a;
		temp->next = 0;
		r->next = temp;
		r = temp;
		(*counter)++;
	}
	return r;
}
List* DelStudent(List* l, const int counter)
{
	if (!l)
	{
		cout << "Список пуст!" << endl;
		system("pause");
		return l;
	}
	int index = 1;
	List* temp = l;
	while (temp)
	{
		if (index == counter)
		{
			List* tmp = temp;
			temp = temp->next;
			delete tmp;
			return l;
		}
		else
		{
			index++;
		}
		temp = temp->next;
	}
}
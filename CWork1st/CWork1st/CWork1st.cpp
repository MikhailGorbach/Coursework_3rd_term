#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <Windows.h>
using namespace std;
						//Информация о студенте
struct Inf
{
	string сodeGr;
	string surname;
	int year;
	bool gender;
	int sHours;
	int jHours;
	int id;
};	
						//Структура списка
struct List
{
	Inf p;
	List* next;
};
										//Прототипы функций

bool MenuCheck(int a);										//Валидация меню
List* NewTable(int* counter);								//Начальное создание таблицы
List* AddStudent(List* r, int* counter);					//Добавление в список
void Print(List* l);										//Просмотр списка
List* DelFirstStudent(List* l, int* id);					//Удаление первого студента
void DelStudent(List* l, int counter, int* id);				//Удаление студента по ключу
List* DelLastStudent(List* l, List* r);						//Удаление последнего студента
int WriteFile(const string filename, List* l);				//Запись данных в файл
int ReadFile(const string filename, List** l, List** r);	//Чтение данных из файла
List* AddNS(Inf a);											//Создание первого элемента (для чтения)
List* AddS(List* r, Inf a);									//Создание элементов (для чтения)
void PrintBySur(List* l, string surname);					//Просмотр списка студентов по фамилии
int SummJHours(List* l);									//Сумма оправданных часов у студентов
int SummSHours(List* l);									//Сумма неоправданных часов у студентов
float PerSHours(List* l);									//Процент неоправданных часов
void ClearStream();											//Чистка потока

int main()
{
	List* l = 0,* r = 0;
	int id = 0;

	setlocale(LC_ALL, "rus");
	
	while (1)
	{
		system("cls");
		cout << "\x1b[36mДобро пожаловать!\x1b[0m" << endl;
		cout
			<< " 1 -> Начальное создание таблицы" << endl
			<< " 2 -> Просмотр таблицы" << endl
			<< " 3 -> Добавление новой записи в таблицу" << endl
			<< " 4 -> Удаление записи" << endl
			<< " 5 -> Корректировка записи в таблице" << endl
			<< " 6 -> Сортировка таблицы" << endl
			<< " 7 -> Поиск записи в таблице" << endl
			<< " 8 -> Сохранение таблицы в файле" << endl
			<< " 9 -> Чтение данных из файла" << endl
			<< "10 -> Обработка таблицы и просмотр результатов обработки" << endl
			<< "11 -> Количество пропущенных часов(оправданных) у всех студентов" << endl
			<< "12 -> Процент пропущенных(неоправданных) часов" << endl	
			<< "13 -> Выход" << endl << endl
			<< "\x1b[31mВыберите пункт меню -> \x1b[0m";

		int key = 0;
		cin >> key;
		if (MenuCheck(key) && key <= 13 && key > 0)
		{
			switch (key)
			{
			case 1:
				if (!l)
				{
					l = NewTable(&id);
					r = l;
				}
				else
				{
					cout << "Таблица уже создана!" << endl;
					system("pause");
				}
				break;
			case 2:
				Print(l);
				break;
			case 3:
				r = AddStudent(r, &id);
				break;
			case 4:
			{
				int number = 1;
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
				if (number == 1) l = DelFirstStudent(l, &id);
				else if (number == id) r = DelLastStudent(l, r);
				else DelStudent(l, number, &id);
				break;
			}
			case 5:

				break;
			case 6:

				break;
			case 7:
			{
				cout << "Введите фамилию студента для поиска: ";
				string surname = "";
				cin >> surname;
				PrintBySur(l, surname);
				break;
			}
			case 8:
			{
				cout << "Введите название файла и его расширение: ";
				string filename = "";
				cin >> filename;
				WriteFile(filename, l);
				break;
			}
			case 9:
			{
				cout << "Введите название файла и его расширение: ";
				string filename = "";
				cin >> filename;
				ReadFile(filename, &l, &r);
				break;
			}
			case 10:

				break;
			case 11:
				cout << "Пропущенно часов(оправданных): " << SummJHours(l) << endl;
				system("pause");
				break;
			case 12:
				cout << "Процент пропущенных(неоправданных) часов: " << PerSHours(l) << "%" << endl;
				system("pause");
				break;
			case 13:
				return 0;
			}
		}
		else
		{
			ClearStream();
			cout << "Выберите пункт из списка!" << endl;
			system("pause");
		}
	}
}

bool MenuCheck(int a)
{
	return (a != 0) ? 1 : 0;
}
void ClearStream()
{
	cin.clear();
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
	cout << "Введите пол (М - 1, Ж - 0): ";
	a.id = ++(*counter);
	a.gender = true;
	l->p = a;
	l->next = 0;
	
	return l;
}
void Print(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	
	List* temp = l;
	cout << "№ Код Фам. Год Часы(пр/опр)" << endl;
	while (temp)
	{
		cout 
			<< temp->p.id
			<< " " << temp->p.сodeGr
			<< "   " << temp->p.surname
			<< " " << temp->p.year
			<< " " << temp->p.sHours
			<< " " << temp->p.jHours << endl;
		temp = temp->next;
	}
	system("pause");
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
		a.id = ++(*counter);
		temp->p = a;
		temp->next = 0;
		r->next = temp;
		r = temp;
	}
	return r;
}
List* DelFirstStudent(List* l, int* id)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return l; }

	List* temp = l;
	l = l->next;
	delete temp;

	List* tmpId;
	for (tmpId = l; tmpId; tmpId = tmpId->next)
	{
		tmpId->p.id--;
	}
	cout << "Первый элемент списка удалён." << endl;
	system("pause");
	return l;
}
void DelStudent(List* l, int counter, int* id)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Список пуст!" << endl; system("pause"); return; }
	
	List* temp = l;
	List* tempN = temp->next;
	while (tempN)
	{
		if (tempN->p.id == counter)
		{
			temp->next = tempN->next;
			delete tempN;
			break;
		}
		temp = temp->next;
		tempN = tempN->next;
	}

	List* tmpId;
	for (tmpId = l; tmpId; tmpId = tmpId->next)
	{
		tmpId->p.id--;
	}
	cout << "Элемент " << counter << " удалён." << endl;
	system("pause");
}
List* DelLastStudent(List* l, List* r)
{
	if (!r) { cout << "Список пуст!" << endl; system("pause"); return r; }

	for (r = l; r->next->next; r = r->next);
	
	List* temp = r->next;
	r->next = 0;
	delete temp;

	cout << "Последний элемент списка удалён." << endl;
	system("pause");
	return l;
}
int WriteFile(const string filename, List* l)
{
	ofstream fout(filename, ios::out);

	if (!fout.is_open()) { cout << "Не удалось открыть файл!" << endl; system("pause"); return 1; }

	List* temp = l;

	while (temp)
	{
		fout
			<< temp->p.id << endl
			<< temp->p.surname << endl
			<< temp->p.year << endl
			<< temp->p.сodeGr << endl
			<< temp->p.gender << endl
			<< temp->p.sHours << endl
			<< temp->p.jHours << endl;

		temp = temp->next;
	}
	cout << "Данные записаны в файл " << filename << " ." << endl;
	system("pause");
	return 0;
}
int ReadFile(const string filename, List** l, List** r)
{
	ifstream fin(filename, ios::in);

	if (!fin.is_open()) { cout << "Не удалось открыть файл!" << endl; system("pause"); return 1; }

	*l = 0;
	Inf a;

	while (fin >> a.id)
	{
		fin
			>> a.surname 
			>> a.year
			>> a.сodeGr
			>> a.gender
			>> a.sHours
			>> a.jHours;

		if (*l) { *r = AddS(*r, a); }
		else { *l = AddNS(a); *r = *l; }
	}
	cout << "Данные загружены из файла " << filename << " ." << endl;
	system("pause");
	return 0;
}
List* AddNS(Inf a)
{
	List* temp = new List;
	temp->p = a;
	temp->next = 0;
	return temp;
}
List* AddS(List* r, Inf a)
{
	List* temp = new List;
	temp->p = a;
	temp->next = 0;
	r->next = temp;
	r = temp;
	return r;
}	
void PrintBySur(List* l, string surname)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }

	List* temp = l;
	cout
		<< endl << "По фамилии " << surname << " найдены следующие записи:" << endl
		<< "№ Код Фам. Год Часы(пр/опр)" << endl;
	while (temp)
	{
		if (temp->p.surname == surname)
		{
			cout
				<< temp->p.id
				<< " " << temp->p.сodeGr
				<< "   " << temp->p.surname
				<< " " << temp->p.year
				<< " " << temp->p.sHours
				<< " " << temp->p.jHours << endl;
		}
		temp = temp->next;
	}
	system("pause");
}
int SummJHours(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return 0; }

	int sum = 0;
	List* temp = l;
	while (temp)
	{
		sum += temp->p.jHours;
		temp = temp->next;
	}
	return sum;
}
int SummSHours(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return 0; }

	int sum = 0;
	List* temp = l;
	while (temp)
	{
		sum += temp->p.sHours;
		temp = temp->next;
	}
	return sum;
}
int SummH(List* l)
{
	return SummJHours(l) + SummSHours(l);;
}
float PerSHours(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return 0.0f; }
	return ((float)SummSHours(l) / (float)SummH(l)) * 100;;
}

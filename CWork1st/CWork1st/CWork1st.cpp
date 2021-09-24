#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
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
//Создание списка
List* NewTable(int* counter);								//Начальное создание таблицы
List* AddStudent(List* l, List* r, int* counter);			//Добавление в список
List* AddNS(Inf a);											//Создание первого элемента (для чтения)
List* AddS(List* r, Inf a);									//Создание элементов (для чтения)
									//Удаление элементов
List* DelFirstStudent(List* l, int* id);					//Удаление первого студента
void DelStudent(List* l, int counter, int* id);				//Удаление студента по ключу
List* DelLastStudent(List* l, List* r, int* id);			//Удаление последнего студента
									//Просмотр списка
void Print(List* l);										//Просмотр списка
void PrintBySur(List* l, string surname);					//Просмотр списка студентов по фамилии
int PrintById(List* l, int id);							//Просмотр списка по номеру
									//Файл
int WriteFile(const string filename, List* l);						//Запись данных в файл
int ReadFile(const string filename, List** l, List** r, List* end);	//Чтение данных из файла
									//Работа с часами
int SummJHours(List* l);									//Сумма оправданных часов у студентов
int SummSHours(List* l);									//Сумма неоправданных часов у студентов
float PerSHours(List* l);									//Процент неоправданных часов
									//Менюшки
void ShowMenu(int iItem);									//Главное меню
void MenuSearchCor(int iItem);								//Меню для корректировки полей
void MenuSearchSort(int iItem);								//Меню для сортировки полей
void ShowExit(int iItem);
									//Проверки
void ClearStream();											//Чистка потока
int YearCheck(int year);
									//Корректировка
void CorSurname(List* l, int num);							//Корректировка фамилии студента
void CorYear(List* l, int num);								//Корректировка года рождения студента
void CorGroup(List* l, int num);							//Корректировка группы студента
void CorSHours(List* l, int num);							//Корректировка часов(пропущ.) студента
void CorJHours(List* l, int num);							//Корректировка фамилии(оправд.) студента
void CorGender(List* l, int num);							//Корректировка гендера студента
									//Сортировки
void SortSurToLow(List* l);									//Сортировка фамилий по убыванию
void SortSurToHigh(List* l);								//Сортировка фамилий по возрастанию
void SortSHoursToHigh(List* l);								//Сортировка пропущенных часов(пропущ.) по убыванию
void SortSHoursToLow(List* l);								//Сортировка пропущенных часов(пропущ.) по возрастанию
void SortJHoursToHigh(List* l);								//Сортировка пропущенных часов(оправд.) по возрастанию
void SortJHoursToLow(List* l);								//Сортировка пропущенных часов(оправд.) по убыванию
void SortYearToHigh(List* l);								//Сортировка года рождения по возрастанию
void SortYearToLow(List* l);								//Сортировка года рождения по убыванию
void SortGenderToLow(List* l);								//Сортировка гендера по убыванию
void SortGenderToHigh(List* l);								//Сортировка гендера по возрастанию

int main()
{
	List* l = 0, * r = 0;
	int id = 0;

	setlocale(LC_ALL, "rus");

	int iItem = 1;
	int nLast = 13;

	ShowMenu(iItem);
	while (1)
	{
		char Key1 = _getch();
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			ShowMenu(iItem);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			ShowMenu(iItem);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
			ShowMenu(iItem);
			switch (iItem)
			{
			case 1: //Создание таблицы
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
			case 2: //Печать таблицы
				Print(l);
				break;
			case 3: //Добавление студента в список
				r = AddStudent(l, r, &id);
				break;
			case 4:
			{
				int number = 1;
				cout << "Введите номер студента для удаления -> ";
				while (1)
				{
					cin >> number;
					if (number <= id && number > 0)
					{
						if (number == 1) l = DelFirstStudent(l, &id);
						else if (number == id) r = DelLastStudent(l, r, &id);
						else DelStudent(l, number, &id);
						break;
					}
					else
					{
						cout << "Нет такого номера записи!" << endl;
						system("pause");
						break;
					}
				}
			}
			break;
			case 5:
			{
				cout << "Введите номер студента, у которого хотите произвести корректировку -> ";
				int num = 0;
				cin >> num;
				if (PrintById(l, num)) break;
				bool bExit = false;

				int iItem1 = 1;
				int nLast1 = 7;

				while (!bExit)
				{
					MenuSearchCor(iItem1);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (0 < iItem1 - 1)
							iItem1 = iItem1 - 1;
						else
							iItem1 = nLast1;
						MenuSearchCor(iItem1);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (iItem1 < nLast1)
							iItem1 = iItem1 + 1;
						else
							iItem1 = 1;
						MenuSearchCor(iItem1);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						MenuSearchCor(iItem1);
						switch (iItem1)
						{
						case 1:
							CorSurname(l, num);
							break;
						case 2:
							CorYear(l, num);
							break;
						case 3:
							CorGroup(l, num);
							break;
						case 4:
							CorJHours(l, num);
							break;
						case 5:
							CorSHours(l, num);
							break;
						case 6:
							CorGender(l, num);
							break;
						case 7:
							bExit = true;
						}
					}
				}
			}
			iItem = 0;
			ShowMenu(iItem);
			break;
			case 6:
			{
				system("cls");
				bool bExit = false;

				int iItem1 = 1;
				int nLast1 = 6;

				cout << "\x1b[36m!Выбор по нажатию клавишы 8 или 2 и Enter!\n\x1b[0m" << endl;
				cout
					<< "Выберите сортировку:" << endl
					<< "8 - по возрастанию" << endl
					<< "2 - по убыванию" << endl;

				string Check;
				cin >> Check;
				if (Check == "8") while (!bExit)
				{
					MenuSearchSort(iItem1);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (0 < iItem1 - 1)
							iItem1 = iItem1 - 1;
						else
							iItem1 = nLast1;
						MenuSearchSort(iItem1);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (iItem1 < nLast1)
							iItem1 = iItem1 + 1;
						else
							iItem1 = 1;
						MenuSearchSort(iItem1);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						MenuSearchSort(iItem1);
						switch (iItem1)
						{
						case 1:
							SortSurToHigh(l);
							break;
						case 2:
							SortYearToHigh(l);
							break;
						case 3:
							SortJHoursToHigh(l);
							break;
						case 4:
							SortSHoursToHigh(l);
							break;
						case 5:
							SortGenderToHigh(l);
							break;
						case 6:
							bExit = true;
						}
					}
				}
				else if (Check == "2") while (!bExit)
				{
					MenuSearchSort(iItem1);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (0 < iItem1 - 1)
							iItem1 = iItem1 - 1;
						else
							iItem1 = nLast1;
						MenuSearchSort(iItem1);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (iItem1 < nLast1)
							iItem1 = iItem1 + 1;
						else
							iItem1 = 1;
						MenuSearchSort(iItem1);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						MenuSearchSort(iItem1);
						switch (iItem1)
						{
						case 1:
							SortSurToLow(l);
							break;
						case 2:
							SortYearToLow(l);
							break;
						case 3:
							SortJHoursToLow(l);
							break;
						case 4:
							SortSHoursToLow(l);
							break;
						case 5:
							SortGenderToLow(l);
							break;
						case 6:
							bExit = true;
						}
					}
				}
				else break;
			}
			iItem = 0;
			ShowMenu(iItem);
			break;
			case 7:
			{
				cout << "Введите фамилию студента для поиска: ";
				string surname = "";
				cin >> surname;
				PrintBySur(l, surname);
			}
			break;
			case 8:
			{
				cout << "Введите название файла и его расширение: ";
				string filename = "";
				cin >> filename;
				WriteFile(filename, l);
			}
			break;
			case 9:
			{
				cout << "Введите название файла и его расширение: ";
				string filename = "";
				cin >> filename;
				id = ReadFile(filename, &l, &r, r);
			}
			break;
			case 10:
				//Что-то тут происходит
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
			{
				bool bExit = false;

				int iItem1 = 1;
				int nLast1 = 3;

				while (!bExit)
				{
					ShowExit(iItem1);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (0 < iItem1 - 1)
							iItem1 = iItem1 - 1;
						else
							iItem1 = nLast1;
						ShowExit(iItem1);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						if (iItem1 < nLast1)
							iItem1 = iItem1 + 1;
						else
							iItem1 = 1;
						ShowExit(iItem1);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
						ShowExit(iItem1);
						switch (iItem1)
						{
						case 1:
							return 0;
						case 2:
							bExit = true;
						case 3:
						{
							cout << "Введите название файла и его расширение: ";
							string filename = "";
							cin >> filename;
							WriteFile(filename, l);
							return 0;
						}
					}
				}
			}
			}
			iItem = 0;
			ShowMenu(iItem);
			break;
			}
		}
	}
}

List* NewTable(int* counter)
{
	List* l = new List;
	Inf a;
	cout << "Введите данные о студенте: " << endl;
	cout << "=======================================" << endl;
	cout << "Код группы: "; getline(cin, a.сodeGr);
	cout << "Фамилия: "; getline(cin, a.surname);
	cout << "Год рождения: "; cin >> a.year;
	cout << "Введите пол (М - 1, Ж - 0): ";
	int g = 1;
	cin >> g;
	if (g == 1) a.gender = true;
	else a.gender = false;
	cout << "Количество пропущенных часов: "; cin >> a.sHours;
	cout << "Количество оправданных часов: "; cin >> a.jHours;
	a.id = ++(*counter);
	l->p = a;
	l->next = 0;

	return l;
}
List* AddStudent(List* l, List* r, int* counter)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return l; }

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
		cout << "Введите пол (М - 1, Ж - 0): ";
		int g = 1;
		cin >> g;
		if (g == 1) a.gender = true;
		else a.gender = false;
		cout << "Кол-во пропущенных часов: "; cin >> a.sHours;
		cout << "Кол-во оправданных часов: "; cin >> a.jHours;
		a.id = r->p.id + 1;
		(*counter)++;
		temp->p = a;
		temp->next = 0;
		r->next = temp;
		r = temp;
	}
	return r;
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

List* DelFirstStudent(List* l, int* id)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return l; }

	List* tmpId;
	for (tmpId = l; tmpId; tmpId = tmpId->next)
	{
		tmpId->p.id--;
	}

	(*id)--;
	List* temp = l;
	l = l->next;
	delete temp;

	cout << "\x1b[32mПервый элемент списка удалён.\x1b[0m" << endl;
	system("pause");
	return l;
}
void DelStudent(List* l, int counter, int* id)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Список пуст!" << endl; system("pause"); return; }

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
	cout << "\x1b[32mЭлемент\x1b[0m " << counter << " \x1b[32mудалён.\x1b[0m" << endl;
	system("pause");
}
List* DelLastStudent(List* l, List* r, int* id)
{
	if (!r) { cout << "Список пуст!" << endl; system("pause"); return r; }

	(*id)--;
	for (r = l; r->next->next; r = r->next);

	List* temp = r->next;
	r->next = 0;
	delete temp;

	cout << "\x1b[32mПоследний элемент списка удалён.\x1b[0m" << endl;
	system("pause");
	return l;
}

void ShowMenu(int iItem)
{
	system("cls");
	cout << "\x1b[32mДобро пожаловать!\x1b[0m" << endl;
	printf("%s 1 - Начальное создание таблицы\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 2 - Просмотр таблицы\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 3 - Добавление новой записи в таблицу\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 4 - Удаление записи\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 5 - Корректировка записи в таблице\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 6 - Сортировка таблицы\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 7 - Поиск записи в таблице\n", iItem == 7 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 8 - Сохранение таблицы в файле\n", iItem == 8 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s 9 - Чтение данных из файла\n", iItem == 9 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s10 - Обработка таблицы и просмотр результатов обработки\n", iItem == 10 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s11 - Количество пропущенных часов(оправданных) у всех студентов\n", iItem == 11 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s12 - Процент пропущенных(неоправданных) часов\n", iItem == 12 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s13 - Выход\n", iItem == 13 ? "\x1b[33m--->\x1b[0m" : " ");
	printf("\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}
void MenuSearchCor(int iItem)
{
	system("cls");
	cout << "\x1b[32mВыберите поле для редактирования: \x1b[0m" << endl;
	printf("%s  1 - Фамилия\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  2 - Год рождения\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  3 - Шифр группы\n", iItem == 3 ? "\x1b[33m>>\x1b[0m" : " ");
	printf("%s  4 - Количество пропущенных часов (оправданных)\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  5 - Количество пропущенных часов (неоправданных)\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  6 - Пол\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  7 - Выйти из меню\n", iItem == 7 ? "\x1b[34m--->\x1b[0m" : " ");
	printf("\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}
void MenuSearchSort(int iItem)
{
	system("cls");
	cout << "\x1b[32mВыберите поле для сортировки: \x1b[0m" << endl;
	printf("%s  1 - Фамилия\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  2 - Год рождения\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  3 - Количество пропущенных часов (оправданных)\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  4 - Количество пропущенных часов (неоправданных)\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  5 - Пол\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  6 - Выйти из меню\n", iItem == 6 ? "\x1b[34m--->\x1b[0m" : " ");
	printf("\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}
void ShowExit(int iItem)
{
	system("cls");
	cout << endl << "\x1b[31mВы уверены, что хотите выйти?\x1b[0m" << endl;
	printf("%s  1 - Да\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  2 - Нет\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("%s  3 - Выйти, сохранив данные в файл\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}

void Print(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }

	List* temp = l;
	cout << "№ Код Фам. Год Часы(пр/опр)" << endl;
	while (temp)
	{
		cout
			<< setw(2)
			<< temp->p.id
			//<< setw(1)
			<< " " << temp->p.сodeGr
			//<< setw(1)
			<< " " << temp->p.surname
			//<< setw(1)
			<< " " << temp->p.year
			//<< setw(1)
			<< " " << temp->p.sHours
			//<< setw()
			<< " " << temp->p.jHours << endl;
		temp = temp->next;
	}
	system("pause");
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
int PrintById(List* l, int id)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return 1; }

	cout << "№ Код Фам. Год Часы(пр/опр)" << endl;
	List* temp = l;
	while (temp)
	{
		if (temp->p.id == id)
		{
			cout
				<< temp->p.id
				<< " " << temp->p.сodeGr
				<< "   " << temp->p.surname
				<< " " << temp->p.year
				<< " " << temp->p.sHours
				<< " " << temp->p.jHours << endl;
			system("pause");
			return 0;
		}
		temp = temp->next;
	}
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
	cout << "\x1b[32mДанные записаны в файле\x1b[0m" << filename << " \x1b[32m.\x1b[0m" << endl;
	system("pause");
	return 0;
}
int ReadFile(const string filename, List** l, List** r, List* end)
{
	ifstream fin(filename, ios::in);

	if (!fin.is_open()) { cout << "Не удалось открыть файл!" << endl; system("pause"); return 1; }

	if (!end)
	{
		*l = 0;
		Inf a;
		int n = 0;

		while (fin >> a.id)
		{
			fin
				>> a.surname
				>> a.year
				>> a.сodeGr
				>> a.gender
				>> a.sHours
				>> a.jHours;

			if (*l) { *r = AddS(*r, a); n++; }
			else { *l = AddNS(a); *r = *l; n++; }
		}
		cout << "\x1b[32mДанные загружены из файла\x1b[0m " << filename << " \x1b[32m.\x1b[0m" << endl;
		system("pause");
		return n;
	}
	else
	{
		Inf a;
		int forId = 0;
		int n = 0;

		while (fin >> a.id)
		{
			forId++;
			a.id = end->p.id + forId;
			fin
				>> a.surname
				>> a.year
				>> a.сodeGr
				>> a.gender
				>> a.sHours
				>> a.jHours;
			*r = AddS(*r, a); n++;
		}
		cout << "Данные загружены из файла " << filename << " и дополнены к новому списку." << endl;
		system("pause");
		return n;
	}
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
			cout << "\x1b[32mФамилия изменена на\x1b[0m " << surname << endl;
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
			temp->p.year = age;
			cout << "\x1b[32mГод изменен на\x1b[0m " << age << endl;
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
			cout << "Введите новый шифр группы у студента: ";
			cin >> gr;
			temp->p.сodeGr = gr;
			cout << "\x1b[32mШифр группы изменён на\x1b[0m " << gr << endl;
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
			cout << "Введите новое количество пропущенных часов у студента: ";
			cin >> sH;
			temp->p.sHours = sH;
			cout << "\x1b[32mЧасы изменены на\x1b[0m " << sH << endl;
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
			cout << "Введите новое количество пропущенных часов у студента: ";
			cin >> sH;
			temp->p.jHours = sH;
			cout << "\x1b[32mЧасы изменены на\x1b[0m " << sH << endl;
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
			cout << "\x1b[32mФамилия изменена на\x1b[0m " << gender << endl;
			system("pause");
			break;
		}
		temp = temp->next;
	}
}

int ClearStreamI(int integer)
{
	if (integer != 0) return integer;
	cin.clear();
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
}
int YearCheck(int year)
{
	if (year < 2021 && year > 1850) return year;
	year = 0;
}

void SortSurToLow(List* l)
{
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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
	if (!l) { cout << "Список пуст!" << endl; system("pause"); return; }
	if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); return; }

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

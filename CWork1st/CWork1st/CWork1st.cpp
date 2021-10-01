#include "List.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	List* l = 0, * r = 0;
	int id = 0;

	int iItem = 1;
	int nLast = 12;

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
			case 1:					//Создание таблицы
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
			case 2:					//Печать
				Print(l);
				break;
			case 3:					//Добавление нового элемента
				r = AddStudent(l, r, &id);
				break;
			case 4:					//Удаление элемента
			{
				if (!l) { cout << "Список пуст!" << endl; system("pause"); break; }
				int number = 1;
				cout << endl;
				printf("\x1b[36m! Для удаления всего списка нажмите 0 !\n\x1b[0m");
				cout << "Введите номер студента для удаления -> ";
				while (1)
				{
					cin >> number;
					if (number == 0)
					{
						l = DelAllStudents(l, &id);
						r = l;
						break;
					}
					else if (number <= id && number > 0)
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
			case 5:					//Корректировка записи
			{
				if (!l) { cout << "Список пуст!" << endl; system("pause"); break; }
				cout << "Введите номер студента, у которого хотите произвести корректировку -> ";
				int num = 0;
				cin >> num;
				if (num > id)
				{
					cout << "Нет такого студента!" << endl;
					system("pause");
					break;
				}
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
				if (!l) { cout << "Список пуст!" << endl; system("pause"); break; }
				if (!l->next) { cout << "Недостаточно элементов для сортировки!" << endl; system("pause"); break; }

				system("cls");
				bool bExit = false;

				int iItem1 = 1;
				int nLast1 = 7;

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
							SortGroupToHigh(l);
							break;
						case 4:
							SortJHoursToHigh(l);
							break;
						case 5:
							SortSHoursToHigh(l);
							break;
						case 6:
							SortGenderToHigh(l);
							break;
						case 7:
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
							SortGroupToLow(l);
							break;
						case 4:
							SortJHoursToLow(l);
							break;
						case 5:
							SortSHoursToLow(l);
							break;
						case 6:
							SortGenderToLow(l);
							break;
						case 7:
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
				if (!l) { cout << "Список пуст!" << endl; system("pause"); break; }
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
				if (!l) { cout << "Список пуст!" << endl; system("pause"); break; }
				cout << "Пропущенно часов(оправданных): " << SummJHours(l) << endl;
				system("pause");
				break;
			case 11:
				if (!l) { cout << "Список пуст!" << endl; system("pause"); break; }
				cout << "Процент пропущенных(неоправданных) часов: " << PerSHours(l) << "%" << endl;
				system("pause");
				break;
			case 12:
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
							break;
						case 3:
						{
							if (!l) { cout << "Список пуст!" << endl; system("pause"); return 0; }
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
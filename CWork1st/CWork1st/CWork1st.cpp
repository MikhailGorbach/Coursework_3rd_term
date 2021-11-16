#define _CRT_SECURE_NO_WARNINGS
#include "List.h"

int main()
{
	ConsoleSettings();
	CursorVisabilityChange(0);

	List* l = 0, * r = 0;
	int id = 0;

	int iItem = 1;
	int nLast = 11;
	bool skip_cinget = true;

	MenuMain(iItem);
	while (1)
	{
		char Key = _getch();
		if (GetAsyncKeyState(VK_UP))
		{
			keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			if (0 < iItem - 1)
				iItem = iItem - 1;
			else
				iItem = nLast;
			MenuMain(iItem);
		}
		if (GetAsyncKeyState(VK_DOWN))
		{
			keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
			if (iItem < nLast)
				iItem = iItem + 1;
			else
				iItem = 1;
			MenuMain(iItem);
		}
		if (GetAsyncKeyState(VK_RIGHT))
		{
			keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
			MenuMain(iItem);
			switch (iItem)
			{
			case 1:					//Создание таблицы
				if (!l)
				{
					l = r = NewTable(&id, skip_cinget);
					MenuMain(iItem);
				}
				else
				{
					cout << "\t\x1b[31mТаблица уже создана!\x1b[0m" << endl << "\t";
					system("pause");
				}
				break;
			case 2:					//Печать
				Print(l, &id, &iItem);
				MenuMain(iItem);
				break;
			case 3:					//Добавление нового элемента
			{
				r = AddStudent(l, r, &id);
			}
			MenuMain(iItem);
			break;
			case 4:					//Удаление элемента
			{
				if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); break; }
				system("cls");
				int number = 1;
				printf("\n\t\x1b[36m<!--Для удаления всего списка нажмите 0-->\n\n\x1b[0m");
				CursorVisabilityChange(1);
				cout << "\tВведите номер студента для удаления -> ";
				while (1)
				{
					cin >> number;
					cout << "\n";
					if (number == 0)
					{
						l = r = DelAllStudents(l, &id, &skip_cinget);
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
						cout << "\t\x1b[31mНет такого номера записи!\x1b[0m" << endl << "\n\t";
						system("pause");
						break;
					}
				}
				iItem = 0;
				CursorVisabilityChange(0);
			}
			break;
			case 5:					//Корректировка записи
			{
				if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); break; }
				system("cls");
				CursorVisabilityChange(1);
				cout << "\n\tВведите номер студента, у которого хотите произвести корректировку -> ";
				int num = 0;
				cin >> num;
				CursorVisabilityChange(0);
				if (num > id)
				{
					cout << "\n\t\x1b[31mНет такого студента!\x1b[0m" << endl << "\n\t";
					system("pause");
					break;
				}
				if (PrintById(l, num)) break;
				bool bExit = false;

				int iItem = 1;
				int nLast = 7;

				while (!bExit)
				{
					MenuCorrect(iItem);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
						if (0 < iItem - 1)
							iItem = iItem - 1;
						else
							iItem = nLast;
						MenuCorrect(iItem);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
						if (iItem < nLast)
							iItem = iItem + 1;
						else
							iItem = 1;
						MenuCorrect(iItem);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
						MenuCorrect(iItem);
						switch (iItem)
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
			MenuMain(iItem);
			break;
			case 6:
			{
				if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); break; }
				if (!l->next) { cout << "\t\x1b[31mНедостаточно элементов сортировки.\x1b[0m" << endl; cout << "\t"; system("pause"); break; }

				system("cls");

				bool bExit = false;

				int iItem = 1;
				int nLast = 7;

				int iItemM = 1;
				int nLastM = 3;

				while (!bExit)
				{
					MenuSortFirst(iItemM);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
						if (0 < iItemM - 1)
							iItemM = iItemM - 1;
						else
							iItemM = nLastM;
						MenuSortFirst(iItemM);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
						if (iItemM < nLastM)
							iItemM = iItemM + 1;
						else
							iItemM = 1;
						MenuSortFirst(iItemM);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
						MenuSortFirst(iItemM);
						switch (iItemM)
						{
						case 1:
							while (!bExit)
							{
								MenuSort(iItem);

								char Key = _getch();

								if (GetAsyncKeyState(VK_UP))
								{
									keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
									if (0 < iItem - 1)
										iItem = iItem - 1;
									else
										iItem = nLast;
									MenuSort(iItem);
								}
								if (GetAsyncKeyState(VK_DOWN))
								{
									keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
									if (iItem < nLast)
										iItem = iItem + 1;
									else
										iItem = 1;
									MenuSort(iItem);
								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
									MenuSort(iItem);
									switch (iItem)
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
							break;
						case 2:
							while (!bExit)
							{
								MenuSort(iItem);

								char Key = _getch();

								if (GetAsyncKeyState(VK_UP))
								{
									keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
									if (0 < iItem - 1)
										iItem = iItem - 1;
									else
										iItem = nLast;
									MenuSort(iItem);
								}
								if (GetAsyncKeyState(VK_DOWN))
								{
									keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
									if (iItem < nLast)
										iItem = iItem + 1;
									else
										iItem = 1;
									MenuSort(iItem);
								}
								if (GetAsyncKeyState(VK_RIGHT))
								{
									keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
									MenuSort(iItem);
									switch (iItem)
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
							break;
						case 3:
						{
							bExit = true;
							break;
						}
						}
					}
				}
			}
			iItem = 0;
			MenuMain(iItem);
			break;
			case 7:
			{
				if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); break; }

				system("cls");
				CursorVisabilityChange(1);
				cout << "\n\tВведите фамилию студента для поиска: ";
				string surname = "";
				cin >> surname;
				CursorVisabilityChange(0);
				PrintBySur(l, surname);
			}
			break;
			case 8:
			{
				if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); break; }
				system("cls");
				CursorVisabilityChange(1);
				while (1)
				{
					cout
						<< endl << "\n\t\x1b[36m<!--Для выхода введите *-->\x1b[0m\n" << endl
						<< "\tВведите название файла и его расширение: ";
					string filename = "";
					cin >> filename;
					CursorVisabilityChange(0);
					if (filename == "*") break;
					else if (filename.size() < 3)
					{
						cout << "\n\t\x1b[31mНеправильное имя файла\x1b[0m\n" << endl;
						cout << "\t";
						system("pause");
						break;
					}
					WriteFile(filename, l);
					break;
				}
			}
			iItem = 0;
			MenuMain(iItem);
			break;
			case 9:
			{
				system("cls");
				CursorVisabilityChange(1);
				while (1)
				{
					cout
						<< endl << "\n\t\x1b[36m<!--Для выхода введите *-->\x1b[0m\n" << endl;
					cout << "\tВведите название файла и его расширение: ";
					string filename = "";
					cin >> filename;
					CursorVisabilityChange(0);
					if (filename == "*") break;
					else if (filename.size() < 3 || filename.size() > 30)
					{
						cout << "\n\t\x1b[31mНеправильное имя файла\x1b[0m\n" << endl;
						cout << "\t";
						system("pause");
						break;
					}
					id += ReadFile(filename, &l, &r, r);
					break;
				}
			}
			iItem = 0;
			MenuMain(iItem);
			break;
			case 10:
				system("pause");
				if (!l) { cout << "\t\x1b[31mСписок пуст!\x1b[0m" << endl; cout << "\t"; system("pause"); break; }
				cout
					<< endl << "\n\t\x1b[36m<!--Отчёт по посещаемости студентов-->\x1b[0m\n" << endl;
				WriteReport(SummJHours(l), PerSHours(l));
				cout << ReadReport() << "\n\t";
				system("pause");
				break;
			case 11:
			{
				bool bExit = false;

				int iItem = 1;
				int nLast = 3;

				while (!bExit)
				{
					MenuExit(iItem);

					char Key = _getch();

					if (GetAsyncKeyState(VK_UP))
					{
						keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
						if (0 < iItem - 1)
							iItem = iItem - 1;
						else
							iItem = nLast;
						MenuExit(iItem);
					}
					if (GetAsyncKeyState(VK_DOWN))
					{
						keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
						if (iItem < nLast)
							iItem = iItem + 1;
						else
							iItem = 1;
						MenuExit(iItem);
					}
					if (GetAsyncKeyState(VK_RIGHT))
					{
						keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
						MenuExit(iItem);
						switch (iItem)
						{
						case 1:
							return 0;
						case 2:
							bExit = true;
							break;
						case 3:
						{
							if (!l) { cout << "Список пуст!" << endl; system("pause"); return 0; }
							CursorVisabilityChange(1);
							cout << "Введите название файла и его расширение: ";
							string filename = "";
							cin >> filename;
							WriteFile(filename, l);
							CursorVisabilityChange(0);
							return 0;
						}
						}
					}
				}
			}
			iItem = 0;
			MenuMain(iItem);
			break;
			}
		}
	}
}
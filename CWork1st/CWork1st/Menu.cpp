#include "Menu.h"

void ShowMenu(int iItem)
{
	system("cls");
	cout << "\n\t\t\t\t\t\x1b[32mДобро пожаловать!\n\x1b[0m" << endl;
	printf("\t\t\t\t%s 1 - Начальное создание таблицы\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 2 - Просмотр таблицы\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 3 - Добавление новой записи в таблицу\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 4 - Удаление записи\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 5 - Корректировка записи в таблице\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 6 - Сортировка таблицы\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 7 - Поиск записи в таблице\n\n", iItem == 7 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 8 - Сохранение таблицы в файле\n\n", iItem == 8 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s 9 - Чтение данных из файла\n\n", iItem == 9 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s10 - Количество пропущенных часов(оправданных) у всех студентов\n\n", iItem == 10 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s11 - Процент пропущенных(неоправданных) часов\n\n", iItem == 11 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t%s12 - Выход\n\n", iItem == 12 ? "\x1b[33m--->\x1b[0m" : " ");
	printf("\t\t\t\t\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\n\x1b[0m");
}
void MenuSearchCor(int iItem)
{
	system("cls");
	cout << "\n\t\x1b[32mВыберите поле для редактирования: \x1b[0m\n" << endl;
	printf("\t%s  1 - Фамилия\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  2 - Год рождения\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  3 - Код группы\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  4 - Количество пропущенных часов (оправданных)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  5 - Количество пропущенных часов (неоправданных)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  6 - Пол\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  7 - Выйти из меню\n\n", iItem == 7 ? "\x1b[34m--->\x1b[0m" : " ");
	printf("\t\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}
void MenuSearchSort(int iItem)
{
	system("cls");
	cout << "\n\t\x1b[32mВыберите поле для сортировки: \x1b[0m\n" << endl;
	printf("\t%s  1 - Фамилия\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  2 - Год рождения\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  3 - Код группы\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  4 - Количество пропущенных часов (оправданных)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  5 - Количество пропущенных часов (неоправданных)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  6 - Пол\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  7 - Выйти из меню\n\n", iItem == 7 ? "\x1b[34m--->\x1b[0m" : " ");
	printf("\t\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}
void ShowExit(int iItem)
{
	system("cls");
	cout << endl << "\t\x1b[31mВы уверены, что хотите выйти?\x1b[0m\n" << endl;
	printf("\t%s  1 - Да\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  2 - Нет\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s  3 - Выйти, сохранив данные в файл\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\x1b[36m!Управление осуществляется стрелочками ВВЕРХ, ВНИЗ, ВПРАВО!\n\x1b[0m");
}
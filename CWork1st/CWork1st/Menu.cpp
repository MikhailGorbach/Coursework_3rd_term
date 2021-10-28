#include "Menu.h"

void MenuMain(int iItem)
{
	system("cls");
	printf("\n\t\t\t\t\t\t\x1b[32mДОБРО ПОЖАЛОВАТЬ!\n\x1b[0m\n");
	printf("\t\t\t\x1b[36m------------------------------------------------------------------------------\x1b[0m\n\n");
	printf("\t\t\t\t\t %s Начальное создание таблицы\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Просмотр таблицы\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Добавление новой записи в таблицу\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Удаление записи\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Корректировка записи в таблице\x1b[0m\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Сортировка таблицы\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Поиск записи в таблице\n\n", iItem == 7 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Сохранение таблицы в файле\n\n", iItem == 8 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Чтение данных из файла\n\n", iItem == 9 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Количество пропущенных часов(оправданных) у всех студентов\n\n", iItem == 10 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s Процент пропущенных(неоправданных) часов\n\n", iItem == 11 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s \x1b[31mВыход\x1b[0m\n\n", iItem == 12 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\t\t\x1b[36m------------------------------------------------------------------------------\x1b[0m\n\n");
	printf("\t\t\t \x1b[36m<!--Управление осуществляется стрелками ВВЕРХ, ВНИЗ, ВПРАВО-->\n\n\n\x1b[0m");
}
void MenuCorrect(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32mВыберите поле для редактирования: \x1b[0m\n\n");
	printf("\t%s Фамилия\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Год рождения\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Код группы\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Количество пропущенных часов (по уваж. причине)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Количество пропущенных часов (по неуваж. причине)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Пол\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Выйти из меню\n\n", iItem == 7 ? "\x1b[33m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--Управление осуществляется стрелками ВВЕРХ, ВНИЗ, ВПРАВО-->\n\x1b[0m");
}
void MenuSort(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32mВыберите поле для сортировки: \x1b[0m\n\n");
	printf("\t%s Фамилия\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Год рождения\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Код группы\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Количество пропущенных часов (оправданных)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Количество пропущенных часов (неоправданных)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Пол\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Выйти из меню\n\n", iItem == 7 ? "\x1b[33m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--Управление осуществляется стрелками ВВЕРХ, ВНИЗ, ВПРАВО-->\n\x1b[0m");
}
void MenuExit(int iItem)
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t\x1b[31mВы уверены, что хотите выйти?\x1b[0m\n\n\n");
	printf("\t\t\t\t\t%s Да\n\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t%s Нет\n\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t%s Выйти, сохранив данные в файл\n\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\x1b[36m<!--Управление осуществляется стрелками ВВЕРХ, ВНИЗ, ВПРАВО-->\n\x1b[0m");
}
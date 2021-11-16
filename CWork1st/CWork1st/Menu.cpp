#include "Menu.h"

void MenuMain(int iItem)
{
	system("cls");
	printf("\n\t\t\t\t\t\t\x1b[32mÄÎÁÐÎ ÏÎÆÀËÎÂÀÒÜ!\n\x1b[0m\n");
	printf("\t\t\t\x1b[36m--------------------------------------------------------------------\x1b[0m\n\n");
	printf("\t\t\t\t\t %s ÍÀ×ÀËÜÍÎÅ ÑÎÇÄÀÍÈÅ ÒÀÁËÈÖÛ\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÏÐÎÑÌÎÒÐ ÒÀÁËÈÖÛ\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÄÎÁÀÂËÅÍÈÅ ÍÎÂÎÉ ÇÀÏÈÑÈ\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÓÄÀËÅÍÈÅ ÇÀÏÈÑÈ\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÊÎÐÐÅÊÒÈÐÎÂÊÀ ÇÀÏÈÑÈ\x1b[0m\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÑÎÐÒÈÐÎÂÊÀ ÒÀÁËÈÖÛ\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÏÎÈÑÊ ÑÒÓÄÅÍÒÀ\n\n", iItem == 7 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÑÎÕÐÀÍÅÍÈÅ ÄÀÍÍÛÕ Â ÔÀÉË\n\n", iItem == 8 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÇÀÃÐÓÇÈÒÜ ÄÀÍÍÛÅ ÈÇ ÔÀÉËÀ\n\n", iItem == 9 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s ÎÒ×¨Ò\n\n", iItem == 10 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t %s \x1b[31mÂûõîä\x1b[0m\n\n", iItem == 11 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\t\t\x1b[36m--------------------------------------------------------------------\x1b[0m\n\n");
	printf("\t\t\t\x1b[36m<!--Óïðàâëåíèå îñóùåñòâëÿåòñÿ ñòðåëêàìè ÂÂÅÐÕ, ÂÍÈÇ, ÂÏÐÀÂÎ-->\n\n\n\x1b[0m");
}
void MenuCorrect(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32mÂûáåðèòå ïîëå äëÿ ðåäàêòèðîâàíèÿ: \x1b[0m\n\n");
	printf("\t%s Ôàìèëèÿ\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Ãîä ðîæäåíèÿ\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Êîä ãðóïïû\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Êîëè÷åñòâî ïðîïóùåííûõ ÷àñîâ (ïî óâàæ. ïðè÷èíå)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Êîëè÷åñòâî ïðîïóùåííûõ ÷àñîâ (ïî íåóâàæ. ïðè÷èíå)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Ïîë\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s \x1b[31mÂûõîä\x1b[0m\n\n", iItem == 7 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--Óïðàâëåíèå îñóùåñòâëÿåòñÿ ñòðåëêàìè ÂÂÅÐÕ, ÂÍÈÇ, ÂÏÐÀÂÎ-->\n\x1b[0m");
}
void MenuSort(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32mÂûáåðèòå ïîëå äëÿ ñîðòèðîâêè: \x1b[0m\n\n");
	printf("\t%s Ôàìèëèÿ\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Ãîä ðîæäåíèÿ\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Êîä ãðóïïû\n\n", iItem == 3 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Êîëè÷åñòâî ïðîïóùåííûõ ÷àñîâ (îïðàâäàííûõ)\n\n", iItem == 4 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Êîëè÷åñòâî ïðîïóùåííûõ ÷àñîâ (íåîïðàâäàííûõ)\n\n", iItem == 5 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Ïîë\n\n", iItem == 6 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s \x1b[31mÂûõîä\x1b[0m\n\n", iItem == 7 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--Óïðàâëåíèå îñóùåñòâëÿåòñÿ ñòðåëêàìè ÂÂÅÐÕ, ÂÍÈÇ, ÂÏÐÀÂÎ-->\n\x1b[0m");
}
void MenuExit(int iItem)
{
	system("cls");
	printf("\n\n\n\n\t\t\t\t\x1b[31mÂû óâåðåíû, ÷òî õîòèòå âûéòè?\x1b[0m\n\n\n");
	printf("\t\t\t\t\t%s Äà\n\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t%s Íåò\n\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t\t\t\t\t%s Âûéòè, ñîõðàíèâ äàííûå â ôàéë\n\n\n", iItem == 3 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\t\t\t\x1b[36m<!--Óïðàâëåíèå îñóùåñòâëÿåòñÿ ñòðåëêàìè ÂÂÅÐÕ, ÂÍÈÇ, ÂÏÐÀÂÎ-->\n\x1b[0m");
}
void MenuSortFirst(int iItem)
{
	system("cls");
	printf("\n\t\x1b[32mÂûáåðåòå ñîðòèðîâêó\x1b[0m\n\n");
	printf("\t%s Ïî âîçðàñòàíèþ\n\n", iItem == 1 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s Ïî óáûâàíèþ\n\n", iItem == 2 ? "\x1b[33m-->\x1b[0m" : " ");
	printf("\t%s \x1b[31mÂûéòè\x1b[0m\n\n", iItem == 3 ? "\x1b[31m--->\x1b[0m" : " ");
	printf("\t\x1b[36m<!--Óïðàâëåíèå îñóùåñòâëÿåòñÿ ñòðåëêàìè ÂÂÅÐÕ, ÂÍÈÇ, ÂÏÐÀÂÎ-->\n\x1b[0m");
}	
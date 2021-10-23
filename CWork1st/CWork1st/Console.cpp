#include "Console.h"

void CursorVisabilityChange(int flag)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO structCursorInfo;
	GetConsoleCursorInfo(handle, &structCursorInfo);
	if (flag == 0)
	{
		structCursorInfo.bVisible = FALSE;
	}
	else
	{
		structCursorInfo.bVisible = TRUE;
	}
	SetConsoleCursorInfo(handle, &structCursorInfo);
}
void ConsoleSettings()
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);
	GetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
	wcscpy_s(fontInfo.FaceName, L"Lucida Console");
	fontInfo.dwFontSize.Y = 22;
	SetCurrentConsoleFontEx(hConsole, TRUE, &fontInfo);
}